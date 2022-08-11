# PinToo 虛擬機器械臂

> **請加入【物聯網、智聯網、ERP、視訊、監控，快速整合開發】社團，掌握產品最新動態**
>
> [https://www.facebook.com/groups/535849751457439](https://www.facebook.com/groups/535849751457439)

通過PinToo 的ModbusTCP來控制虛擬場景中的機械臂的移動。實現對 Factory IO 場景的控制。

Factory IO是一款出色的虛擬模擬軟體，可以自由使用其內部的各種元器件、感測器、驅動器等搭建自己理想中的工業現場，並聯合PLC進行程式設計模擬。

範例目錄中已提供了場景的專案檔案，可直接在Factory IO 中打開。

在場景中選擇驅動方式，點選功能表欄中的 `檔案-驅動`，在下拉框中選擇驅動的方式為 `Modbus TCP/IP Server`，點選右側的 `配置` 按鈕，將從站ID 修改爲 `255`。

![](images/260330216227140.png)

![](images/375850216247306.png)

啟動PinToo，在模組設計界面點選 `匯入資料庫` ，將 `PinToo_Arm.pdb` 匯入至模組設計界面列表中。進入至模組設計界面，確認 `fxModbusTCP` 中的 `Host` 屬性已修改爲虛擬場景軟體指定的地址。

設計界面顯示如下：

![](images/244532616239975.png)

切換至發佈中心，將模組發佈至已連線的裝置。執行場景與裝置，檢視控制的效果。

![](images/281482716236530.png)

* **產品**：https://isoface.net/isoface/production/software/pintoo
* **產品說明**：https://isoface.net/isoface/doc/pintoo/main/
* **網址**：https://isoface.net/