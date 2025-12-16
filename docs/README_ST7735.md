# ST7735S test - ESP8266

Bu proje ESP8266 (NodeMCU) üzerine bağladığınız ST7735(S) TFT için basit bir test uygulaması içerir.

Dosyalar:
- `platformio.ini` : PlatformIO yapılandırması
- `src/main.cpp` : Test uygulaması

Bağlantı (sizin verdiğiniz pinler):
- `VCC`  -> `3.3V`
- `GND`  -> `GND`
- `SCL` / `SCK`  -> `D5`  (GPIO14)
- `SDA` / `MOSI` -> `D7`  (GPIO13)
- `CS`   -> `D8`  (GPIO15)
- `DC`   -> `D2`  (GPIO4)
- `RST`  -> `D3`  (GPIO0)

Not: `RST` için `D3` (GPIO0) kullanımı bazı NodeMCU/ESP8266 kartlarında boot modunu etkileyebilir. Eğer kart normal olarak boot etmezse `RST` için farklı bir pin (ör. D1/D0 üzerinden bir çevirici) kullanmayı düşünün.

Notlar:
- Bazı ST7735 panellerde `INITR_BLACKTAB` yerine `INITR_GREENTAB` veya `INITR_REDTAB` gerekebilir. `src/main.cpp` içindeki `tft.initR(...)` çağısını değiştirin.
- VCC mutlaka 3.3V olmalı. 5V vermeyin.

Derleme ve yükleme (PlatformIO):

1. Visual Studio Code + PlatformIO eklentisini kurun.
2. Bu klasörü açın ve PlatformIO'da `Build` ardından `Upload` yapın.

Alternatif: Arduino IDE
- `Adafruit GFX Library` ve `Adafruit ST7735 and ST7789 Library` kütüphanelerini Library Manager ile ekleyin.
- `src/main.cpp` içeriğini `.ino` dosyası olarak Arduino sketch'e kopyalayın (pin tanımlamalarını NodeMCU için tutabilirsiniz) ve yükl­eyin.

Test kriterleri:
- Ekran açıldığında kısa bir başlık ve renk bantları görünmeli.
- Ardından ekranda artan bir sayaç görünmeli.
