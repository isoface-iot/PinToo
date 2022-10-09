# PinToo ModbusRTU 電錶數據採集

PinToo 移動設備應用程式開發平臺，提供多層次開發框架，開發企業管理系統，只要有網路，無論何時、何地，快速開發APP。社區版功能無差別，全部免費。

> **加入 Facebook 社團**
>
> [https://www.facebook.com/groups/isoface/](https://www.facebook.com/groups/isoface/)
> 
> **點讚追蹤 Facebook 粉絲專頁**
> 
> [https://www.facebook.com/diylogi](https://www.facebook.com/diylogi)


採用 ModbusRTU 通訊協議，連線至電錶讀取電錶的讀數資訊。

電能表是用來測量電能的儀表，又稱電度表，火表，千瓦小時表，指測量各種電學量的儀表。

電能表在低電壓（不超過 500 伏）和小電流（幾十安）的情況下，可直接接入電路進行測量。一般的家用電路是以這種方式接入電能表進行電費計量的。在高電壓或大電流的情況下，電能表不能直接接入線路，需配合電壓互感器或電流互感器使用。工廠的電能表通常會使用這種方式進行測量。

目前市面上使用的絕大多數數字液晶顯示屏電能表均有 RS485 的通訊介面，除了用於連線電路的接線柱外，還包含了 RS485 介面的接線柱，用於與計算機進行連線。範例中使用的電能表通過 RS485 通訊介面與計算機連線，計算機向該電能表發送讀取電能數據的Modbus指令，電能表對應返回數據，計算機進行解析后顯示讀取的結果數值。我們可以將讀取到的數值寫入至資料庫中實現能源分析的功能。


## 範例匯入方式

請注意，範例的匯入流程會將原有的模板資料庫覆蓋，在匯入其他模板資料庫之前請先備份已有的 `PinToo.pdb` 檔案。有以下兩種備份與打開方式。

**方法一**

將安裝目錄下的 `PinToo.pdb` 檔案複製一份，重新命名為其他名稱的檔案。打開 PinToo Design 設計器，進入至模組列表界面。選擇 `匯入資料庫`，選擇目錄中的示例 `pdb` 檔案 匯入至 PinToo Design 的模組列表中。

**方法二**

關閉 PinToo Design 設計器，將原先目錄下的 `PinToo.pdb` 做好備份，重新命名為其他名稱的檔案。將要打開的範例模板資料庫檔案重新命名為 `PinToo.pdb`。打開 PinToo Design 設計器可檢視匯入的模組資料庫檔案中的模組。


* **PinToo 簡介**：https://isoface.net/isoface/production/software/pintoo
* **PinToo下載**：[點選此處下載](https://github.com/isoface-iot/PinToo/releases/latest)
* **PinToo產品說明**：https://isoface.net/isoface/doc/pintoo/main/
* **PinToo 範例列表**：https://isoface.net/isoface/production/software/pintoo/pintoo-sample
* **PinToo 快速上手**：https://isoface.net/isoface/study/quick-start/2022-05-28-03-08-29/pintoo
* **PinToo 無需安裝，線上試用**：https://isoface.net/isoface/support/trial/pintoo