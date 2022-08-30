# PinToo PM2.5 感測器數據讀取

> **請加入【FaceBook社團】掌握產品最新動態**
>
> [https://www.facebook.com/groups/535849751457439](https://www.facebook.com/groups/535849751457439)


通過 ModbusTCP 協議，連線至 ESP32 串接的 PMS5003ST PM2.5 感測器，讀取感測器的數據，並存入 ESP32 的 Modbus 裝置中 ，Smart 通過裝置的連線獲取感測器的數據資訊，從而實現 PM2.5 數據的讀取。

PMS5003ST 是一款可以同時監測空氣中顆粒物濃度、甲醛濃度及溫濕度的三合一感測器。其中顆粒物濃度的監測基於鐳射散射原理，可連續採集並計算單位體積內空氣中不同粒徑的懸浮顆粒物個數，即顆粒物濃度分佈，進而換算成為質量濃度。甲醛濃度的監測基於電化學原理，具有高精度、高穩定性的特點。感測器同時內嵌瑞士生產的溫濕度一體檢測晶片。顆粒物濃度數值、甲醛濃度數值及溫度、濕度合併以通用數字介面形式輸出。本感測器可嵌入各種與空氣質量監測和改善相關的儀器裝置，為其提供及時準確的環境參數。


## 範例匯入方式

請注意，範例的匯入流程會將原有的模板資料庫覆蓋，所在在匯入其他模板資料庫之前請先備份已有的 `PinToo.pdb` 檔案。

將安裝目錄下的 `PinToo.pdb` 檔案複製一份，重新命名為其他名稱的檔案。

打開 PinToo Design 設計器，進入至模組列表界面。選擇 `匯入資料庫`，選擇目錄中的示例 `pdb` 檔案 匯入至 PinToo Design 的模組列表中。

將原先目錄下的 `PinToo.pdb` 做好備份，將複製的檔案重新命名為 `PinToo.pdb`。重新打開 PinToo Design 設計器可檢視匯入的模組資料庫檔案中的模組。

## 注意事項

1. 開發板的硬體連線圖在 `Fritzing` 資料夾中，可使用 Fritzing 打開以檢視。
2. 需使用的程式碼使用 Arduino 來展示。請下載對應的 Arduino IDE 來進行燒錄。

* **产品**：https://www.isoface.cn/isoface/production/software/pintoo
* **产品说明**：https://www.isoface.cn/isoface/doc/pintoo/main/
* **网址**：https://www.isoface.cn/