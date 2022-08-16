# PinToo 範例列表

PinToo 移動設備應用程式開發平臺，提供多層次開發框架，開發企業管理系統，只要有網路，無論何時、何地，快速開發APP。社區版功能無差別，全部免費。

> **請加入【物聯網、智聯網、ERP、視訊、監控，快速整合開發】社團，掌握產品最新動態**
>
> [https://www.facebook.com/groups/535849751457439](https://www.facebook.com/groups/535849751457439)

`PinToo_Demo.pdb` 中為初始安裝包中附帶的範例資料庫檔案，其中包含有以下範例

|範例編號|範例名稱|
|---|---|
|p-el-dem-2001|通訊埠印表機|
|p-el-dem-2002|通訊埠電子秤|
|p-el-dem-2004|通訊埠控制 LED 燈|
|p-el-dem-2005|RS485 計數器|
|p-el-dem-2006|ModbusTCP 控制元件使用|
|p-el-dem-2007|ModbusTCP 控制 LED 燈|
|p-el-dem-2008|ModbusTCP 讀取溫濕度|
|p-el-dem-2010|ModbusRTU 控制 LED 燈|
|p-el-dem-2011|ModbusRTU 讀取溫濕度|
|p-el-dem-2012|WiFi 控制 LED 燈|
|p-el-dem-2013|MQTTClient 控制元件使用|
|p-el-dem-2014|MQTT 控制 LED 燈|
|p-el-dem-2015|MQTT 讀取溫濕度|
|p-el-dem-2017|藍芽印表機|
|p-el-dem-2018|藍芽電子秤|
|p-el-dem-2019|藍芽控制 LED 燈|
|p-el-dem-2020|藍芽讀取溫濕度|
|p-el-dem-2022|網路文件瀏覽|
|p-el-dem-2023|網路視訊播放|
|p-el-dem-2024|呼叫 Android 原生庫|
|p-el-dem-2025|圖表展示|
|p-el-dem-2026|TARS 數據存取|
|p-el-dem-2027|Flying 網路列印|
|p-el-dem-2028|自定 HTTP Server 伺服器|
|p-el-dem-2029|自定 HTTP Client 客戶端|
|p-el-dem-2030|簡訊發送|
|p-el-dem-2031|窗體相互傳值|
|p-el-dem-2032|手寫板簽名|
|p-el-dem-2033|二維碼產生|
|p-el-dem-2034|語音轉文字|
|p-el-dem-2035|文字轉語音|
|p-el-dem-2037|地圖及定位|
|p-el-dem-2041|RestAPI 控制 LED 燈|
|p-el-dem-2042|RestAPI 讀取溫濕度|
|p-el-dem-2043|SVG 組態|
|p-el-dem-2044|網路聊天室|

新增範例目錄的說明如下：

## 物聯網

|目錄名稱|對應範例名稱|
|-------|------------|
|[p-el-dem-2201_esp32cam_servo_car](iot/p-el-dem-2201_esp32cam_servo_car/)|遙控小車|
|[p-el-dem-2202_esp32cam_slider](iot/p-el-dem-2202_esp32cam_slider/)|ESP32CAM 滑軌照相機|
|[p-el-dem-2203_esp32_slider](iot/p-el-dem-2203_esp32_slider/)|ESP32 滑軌照相機|
|[p-el-dem-2210_pms5003st_sensor](iot/p-el-dem-2210_pms5003st_sensor/)|PM2.5 感測器數據讀取|


## 組態

|目錄名稱|對應範例名稱|
|-------|------------|
|[p-el-dem-2204_filltank_openplc](scada/p-el-dem-2204_filltank_openplc/)|液化槽控制(OpenPLC)|
|[p-el-dem-2205_filltank_pintoo](scada/p-el-dem-2205_filltank_pintoo/)|液化槽控制(PinToo)|
|[p-el-dem-2208_factory_robot_arm](scada/p-el-dem-2208_factory_robot_arm/)|虛擬機器械臂控制|

## 範例匯入方式

請注意，範例的匯入流程會將原有的模板資料庫覆蓋，所在在匯入其他模板資料庫之前請先備份已有的 `PinToo.pdb` 檔案。

將安裝目錄下的 `PinToo.pdb` 檔案複製一份，重新命名為其他名稱的檔案。

打開 PinToo Design 設計器，進入至模組列表界面。選擇 `匯入資料庫`，選擇目錄中的示例 `pdb` 檔案 匯入至 PinToo Design 的模組列表中。

將原先目錄下的 `PinToo.pdb` 做好備份，將複製的檔案重新命名為 `PinToo.pdb`。重新打開 PinToo Design 設計器可檢視匯入的模組資料庫檔案中的模組。


* **產品**：https://isoface.net/isoface/production/software/pintoo
* **產品說明**：https://isoface.net/isoface/doc/pintoo/main/
* **網址**：https://isoface.net/