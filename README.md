# 材料
- Arduino nano
- Tower Pro SG90 伺服馬達
- Keyes VS1838B 紅外線接收器
- 麵包板
- 杜邦線

# 伺服馬達 -> Arduino 線路
- VCC -> 5V
- GND -> GND
- Control -> PIN 9

# 紅外線接收器 -> Arduino 線路
- VCC -> PIN 4
- GND -> PIN 3
- Vout -> PIN 2

# Demo
![IrRemote](./IrRemote.gif)

# 注意遙控器電池電量，電量太低紅外線發射距離會很低，換電池解決