#include "esp_camera.h"
#include <Arduino.h>
#include <WiFi.h>
#include <ArduinoWebsockets.h>
#include "esp_timer.h"
#include "img_converters.h"
#include "fb_gfx.h"
#include "soc/soc.h" //disable brownout problems
#include "soc/rtc_cntl_reg.h"  //disable brownout problems
#include "driver/gpio.h"
#include "esp32-hal-ledc.h"
#include <iostream>
#include <sstream>
#include<ArduinoJson.h>

//#define CAMERA_MODEL_AI_THINKER

#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

//電路圖引腳設定
const int RMotor1 = 14;
const int RMotor2 = 15;
const int LMotor1 = 13;
const int LMotor2 = 12;
const int panServo = 2;
const int tiltServo = 3; //航向舵機設定針腳，實際操作中可能會被線束卡住，可不使用
const int FlashPin = 4;
/* Defining initial values */
int speed = 255;
int panVal = 4875;
int tiltVal = 4875;

//定義WIFI連線資訊與websocket設定資訊
const char* ssid = "WIFI-SSID"; //Enter SSID
const char* password = "WIFI-PASSWORD"; //Enter Password
const char* websockets_server_host = "192.168.0.151"; //Enter websocket server adress
const uint16_t websockets_server_port = 9998; // Enter websocket server port
const char* websockets_server_path = "/"; // Enter websocket server path

camera_fb_t * fb = NULL;
size_t _jpg_buf_len = 0;
uint8_t * _jpg_buf = NULL;
uint8_t state = 0;

using namespace websockets;
WebsocketsClient client;

///////////////////////////////////CALLBACK FUNCTIONS///////////////////////////////////
void onMessageCallback(WebsocketsMessage message) {
  Serial.print("Got Message: ");
  Serial.println(message.data());
  String json = message.data();

  DynamicJsonDocument doc(json.length() * 2); //設定需解析的json數據大小
  //反序列化
  deserializeJson(doc,json);
  String typeString = doc["type"].as<String>();
  int val = doc["val"].as<int>();
  if(typeString == "CAR_UP"){
    ledcWrite(4, speed);
    ledcWrite(5, 0);
    ledcWrite(6, 0);
    ledcWrite(7, speed);
  }
  //小車移動指令
  else if(typeString == "CAR_DOWN"){
    ledcWrite(4, 0);
    ledcWrite(5, speed);
    ledcWrite(6, speed);
    ledcWrite(7, 0);
  }
  else if(typeString == "CAR_LEFT"){
    ledcWrite(4, speed);
    ledcWrite(5, 0);
    ledcWrite(6, speed);
    ledcWrite(7, 0);
  }
  else if(typeString == "CAR_RIGHT"){
    ledcWrite(4, 0);
    ledcWrite(5, speed);
    ledcWrite(6, 0);
    ledcWrite(7, speed);
  }
  else if(typeString == "CAR_STOP"){
    ledcWrite(4, 0); 
    ledcWrite(5, 0);
    ledcWrite(6, 0);
    ledcWrite(7, 0);
  }
  //舵機移動指令
  else if(typeString == "SERVO_UP"){
    if      (tiltVal > 6500) tiltVal = 6500;
    else if (tiltVal < 3250) tiltVal = 3250;
    tiltVal = tiltVal + 200;
    ledcWrite(9, tiltVal);
  }
  else if(typeString == "SERVO_DOWN"){
    if      (tiltVal > 6500) tiltVal = 6500;
    else if (tiltVal < 3250) tiltVal = 3250;
    tiltVal = tiltVal - 200;
    ledcWrite(9, tiltVal);
  }
  else if(typeString == "SERVO_LEFT"){
    if      (panVal > 6500) panVal = 6500;
    else if (panVal < 3250) panVal = 3250;
    panVal = panVal + 200;
    ledcWrite(8, panVal);
  }
  else if(typeString == "SERVO_RIGHT"){
    if      (panVal > 6500) panVal = 6500;
    else if (panVal < 3250) panVal = 3250;
    panVal = panVal - 200;
    ledcWrite(8, panVal);
  }
    /* Flash LED control */
  else if(typeString == "FLASH"){
    ledcWrite(3, val);
  }
  else if(typeString == "SPEED"){
    /* Setting the motor speed */
    if      (val > 255) speed = 255;
    else if (val <   0) speed = 0;
    else speed = val;
  }
  else{
    ledcWrite(4, 0); 
    ledcWrite(5, 0);
    ledcWrite(6, 0);
    ledcWrite(7, 0);
  }
}

///////////////////////////////////INITIALIZE FUNCTIONS///////////////////////////////////
esp_err_t init_camera() {
  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  //init with high specs to pre-allocate larger buffers
  if (psramFound()) {
    config.frame_size = FRAMESIZE_XGA;
    config.jpeg_quality = 12;
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 12;
    config.fb_count = 1;
  }
  // Camera init
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return err;
  }
  sensor_t * s = esp_camera_sensor_get();
  s->set_framesize(s, FRAMESIZE_VGA);
  Serial.println("Cam Success init");
  return ESP_OK;
}

//WIFI SETUP
esp_err_t init_wifi() {
  WiFi.begin(ssid, password);
  Serial.println("Starting Wifi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("Connecting to websocket");
  client.onMessage(onMessageCallback);
  bool connected = client.connect(websockets_server_host, websockets_server_port, websockets_server_path);
  if (!connected) {
    Serial.println("Cannot connect to websocket server!");
    state = 3;
    return ESP_FAIL;
  }
  if (state == 3) {
    return ESP_FAIL;
  }

  Serial.println("Websocket Connected!");
  client.send("{\"action\":\"login\",\"sid\":\"esp32cam_car\"}"); // for verification
  return ESP_OK;
}

void init_Motors()
{
  /* Configuring PWM channels for DC motors */
  /* ledcSetup(Channel, Frequency, Resolution) */
  ledcSetup(4, 2000, 8); /* 2000 hz PWM, 8-bit resolution and range from 0 to 255 */
  ledcSetup(5, 2000, 8); 
  ledcSetup(6, 2000, 8); 
  ledcSetup(7, 2000, 8); 
  /* Attaching the channel to the GPIO to be controlled */
  /* ledcAttachPin(GPIO, Channel) */
  ledcAttachPin(RMotor1, 4);
  ledcAttachPin(RMotor2, 5);
  ledcAttachPin(LMotor1, 6);
  ledcAttachPin(LMotor2, 7);
}

void init_Servo() {
  /* Configuring PWM channels for servo motors */
  ledcSetup(8, 50, 16); /*50 hz PWM, 16-bit resolution and range from 3250 to 6500 */
  ledcSetup(9, 50, 16); 
  ledcAttachPin(panServo, 8);
  ledcAttachPin(tiltServo, 9);
  /* Initializing servo motors */
  ledcWrite(8, panVal);
  ledcWrite(9, tiltVal);
}

void init_Flash() {
  /* Configuring PWM channels for Falsh LED */
  ledcSetup(3, 5000, 8); /* 5000 hz PWM, 8-bit resolution and range from 0 to 255 */
  ledcAttachPin(FlashPin, 3);
}


///////////////////////////////////SETUP///////////////////////////////////
void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  init_camera();
  init_wifi();
  init_Motors();
  init_Servo();
  init_Flash();
}

///////////////////////////////////MAIN LOOP///////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
  if (client.available()) {
    camera_fb_t *fb = esp_camera_fb_get();
    if (!fb) {
      Serial.println("Camera capture failed");
      esp_camera_fb_return(fb);
      ESP.restart();
    }
    client.sendBinary((const char*) fb->buf, fb->len);
    Serial.println("MJPG sent");
    esp_camera_fb_return(fb);
    client.poll();
  }
}
