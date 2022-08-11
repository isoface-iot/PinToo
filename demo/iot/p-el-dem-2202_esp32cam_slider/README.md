# PinToo ESP32CAM 滑軌照相機

> **請加入【物聯網、智聯網、ERP、視訊、監控，快速整合開發】社團，掌握產品最新動態**
>
> [https://www.facebook.com/groups/535849751457439](https://www.facebook.com/groups/535849751457439)

## 控制重點
* 使用 rtsp 接收 ESP32CAM 的視訊流，實現對視訊直播流的截圖拍照或視訊錄製的功能。
* 使用 WebSocket 協議連線至控制步進電機的馬達，通過 WebSocket 發送指令實現滑軌的運動操作。

## 使用控制裝置

|序號|零件名稱|數量|
|---|---|---|
|1|AI-Thinker ESP32CAM開發板帶攝像頭|1|
|2|28BYJ-48 步進電機(帶驅動板)|2|
|3|滑軌軌道套裝|1|
|4|杜邦線|若干|
|5|NodeMCU ESP32S|1|

## 範例匯入方式

退出 PinToo Design 設計器，將目錄中的 `PinToo_esp32cam_slider.pdb` 複製至 PinToo Design 的安裝目錄中，將原先目錄下的 `PinToo.pdb` 做好備份，將複製的檔案重新命名為 `PinToo.pdb`。重新打開 PinToo Design 設計器可檢視匯入的模組資料庫檔案中的模組。

## 注意事項

1. 開發板的硬體連線圖在 `Fritzing` 資料夾中，可使用 Fritzing 打開以檢視。
2. 需使用的程式碼使用 Arduino 來展示。請下載對應的 Arduino IDE 來進行燒錄。


* **產品**：https://isoface.net/isoface/production/software/pintoo
* **產品說明**：https://isoface.net/isoface/doc/pintoo/main/
* **網址**：https://isoface.net/