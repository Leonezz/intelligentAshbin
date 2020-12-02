# 基于 FreeMODBUS 的stm32 modbus 从机系统

## 外设

系统维护传感器和推杆等共 5 个外设，分别是：

- 温湿度传感器`YSAT01B`（串口）
- 可燃气体传感器`MQ-2`（ADC）
- 烟雾传感器`MCU-30105`（IIC）
- 称重传感器（ADC）
- 推杆（继电器/普通IO）

## 寄存器分配

系统数据大致分为两类：只读数据（传感器数值）和只写数据（推杆状态）
对于只读数据，将其储存在输入寄存器`usRegInputBuf`中，数据类型为`unsigned short`，寄存器长度为10，分配如下：

| 地址  |   0x00    |   0x01    |   0x02    |   0x03    |       0x04        |       0x05        |     0x06      |     0x07      |   0x08    |   0x09    |
| :---: | :-------: | :-------: | :-------: | :-------: | :---------------: | :---------------: | :-----------: | :-----------: | :-------: | :-------: |
| 数值  | 温度高8位 | 温度低8位 | 湿度高8位 | 湿度低8位 | 可燃气体浓度高8位 | 可燃气体浓度低8位 | 烟雾浓度高8位 | 烟雾浓度低8位 | 重量高8位 | 重量低8位 |

对于只写数据，将其储存在线圈寄存器`RegCoil`中
