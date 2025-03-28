# PIC24 I2C 库

这是一个用于 PIC24 微控制器的轻量级 I2C（集成电路）库，设计用于连接 EEPROM（如 24LC256）。该库已在 Proteus 中进行了测试，可用于各种基于 I2C 的外设。

## 特性

- 支持 I2C 读写操作
- 与 24LC256 EEPROM 兼容（可扩展至其他 I2C 设备）
- 使用 MPLAB XC16 的 C 语言编写
- 已在 Proteus 中测试验证

## 要求

- **硬件**
  - **PIC24F16KA102** *（或任何兼容的 PIC24 微控制器）* - 开发平台。
  - **24LC256** *（或类似的 I2C 设备）* - i2c 设备。
- **软件**
  - **MPLAB X** - 用于 PIC 微控制器的集成开发环境 (IDE)。
  - **XC16 编译器** - 用于 PIC24 的 C 编译器。
  - **Proteus** *（可选）* - 用于测试。

## IO 端口

| PIC24 引脚 | 功能    | 连接设备 | 说明            |
| ---------- | ------- | -------- | --------------- |
| RB0        | GPIO    | LED      | 控制 LED 指示灯 |
| RB8        | I2C SCL | 24LC256  | I2C 时钟        |
| RB9        | I2C SDA | 24LC256  | I2C 数据        |

## 源文件

- `main.c` - 主要应用逻辑。
- `led.h` & `led.c` - LED 控制，用于调试。
- `clock.h` & `clock.c` - 时钟初始化和延时。
- `i2c.h` & `i2c.c` - I2C 库。

## 待办事项列表

  - 添加错误处理机制。

## 作者信息

  - **作者**： 卫屹棋
  - **工作单位**： 上海交通大学
  - **联系方式**: yiqiwei4536@gmail.com

## References

- [PIC24F16KA102 数据手册](https://ww1.microchip.com/downloads/en/DeviceDoc/39927c.pdf)