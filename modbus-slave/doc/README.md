# 基于 FreeMODBUS 的stm32 modbus 从机系统

## 外设

系统目前维护传感器和推杆等共 4 个外设，分别是：

- 温湿度传感器`YSAT01B`（串口）
- 可燃气体传感器`MQ-2`（ADC）
- 称重传感器（ADC）
- 推杆（继电器/普通IO）

## 寄存器分配

系统数据大致分为两类：只读数据（传感器数值）和只写数据（推杆状态）
对于只读数据，将其储存在输入寄存器`usRegInputBuf`中，数据类型为`unsigned short`，寄存器长度为10，分配如下：

| 地址  | 0x00  | 0x01  |     0x02     | 0x03-0x04 |
| :---: | :---: | :---: | :----------: | :-------: |
| 数据  | 温度  | 湿度  | 可燃气体浓度 |   重量    |

推杆状态信息存储在线圈寄存器中，其地址为`0x00`，长度为`1`

## 读取指令数据帧格式：

| 从机地址 | 功能代码 | 寄存器地址高位 | 寄存器地址低位 | 寄存器数量高位 | 寄存器数量低位 | CRC高位 | CRC低位 |
| :------: | :------: | :------------: | :------------: | :------------: | :------------: | :-----: | :-----: |

## 写指令数据帧格式：

| 从机地址 | 功能代码 | 寄存器地址高位 | 寄存器地址低位 | 数据1-数据n | CRC高位 | CRC低位 |
| :------: | :------: | :------------: | :------------: | :---------: | :-----: | :-----: |

## 设备返回数据帧格式：

| 从机地址 | 功能代码 | 返回字节数n | 数据1-数据n | CRC高位 | CRC低位 |
| :------: | :------: | :---------: | :---------: | :-----: | :-----: |



## 目前的`modbus`数据读写指令如下表：

|                   指令                    |       描述       |                    响应示例                    |
| :---------------------------------------: | :--------------: | :--------------------------------------------: |
| `0x01 0x04 0x00 0x00 0x00 0x01 0x31 0xCA` |     读取温度     |      `0x01 0x04 0x02 0x06 0xBA 0x3B 0x23`      |
| `0x01 0x04 0x00 0x01 0x00 0x01 0x60 0x0A` |     读取湿度     |      `0x01 0x04 0x02 0x11 0x17 0xF5 0x6E`      |
| `0x01 0x04 0x00 0x02 0x00 0x01 0x90 0x0A` | 读取可燃气体浓度 |      `0x01 0x04 0x02 0x01 0x0C 0xB8 0xA5`      |
| `0x01 0x04 0x00 0x03 0x00 0x02 0x81 0xCB` |     读取重量     | `0x01 0x04 0x04 0x00 0x00 0x00 0x9B 0xBA 0x2F` |
| `0x01 0x01 0x00 0x00 0x00 0x01 0xFD 0xCA` |   读取推杆状态   |        `0x01 0x01 0x01 0x00 0x51 0x88`         |
| `0x01 0x05 0x00 0x00 0xFF 0x00 0x8C 0x3A` |   推杆状态写1    |   `0x01 0x05 0x00 0x00 0xFF 0x00 0x8C 0x3A`    |
| `0x01 0x05 0x00 0x00 0x00 0x00 0xCD 0xCA` |   推杆状态写0    |   `0x01 0x05 0x00 0x00 0x00 0x00 0xCD 0xCA`    |



