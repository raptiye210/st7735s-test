#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>

// Pin mapping (NodeMCU pin names). Kullanıcının verdiği pinlere göre ayarlandı.
// SCL -> D5 (SPI SCK), SDA -> D7 (SPI MOSI)
#define TFT_SCK  D5 // GPIO14 (SCL)
#define TFT_MOSI D7 // GPIO13 (SDA)
#define TFT_CS   D8 // GPIO15
#define TFT_DC   D2 // GPIO4
#define TFT_RST  D3 // GPIO0 (D3 kullanımı boot modunu etkileyebilir)

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("ST7735 Test - ESP8266");

  // Eğer ekranınız farklı bir tab versiyonuyse INITR_** değerini değiştirin.
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);

  // Basit test ekranı: başlık + renk şeritleri
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(6, 6);
  tft.println("ESP8266 + ST7735");

  int w = tft.width();
  int h = tft.height();
  int barh = h / 6;
  tft.fillRect(0, 24 + 0 * barh, w, barh, ST77XX_RED);
  tft.fillRect(0, 24 + 1 * barh, w, barh, ST77XX_YELLOW);
  tft.fillRect(0, 24 + 2 * barh, w, barh, ST77XX_GREEN);
  tft.fillRect(0, 24 + 3 * barh, w, barh, ST77XX_CYAN);
  tft.fillRect(0, 24 + 4 * barh, w, barh, ST77XX_BLUE);
  tft.fillRect(0, 24 + 5 * barh, w, barh, ST77XX_MAGENTA);

  delay(2000);
}

void loop() {
  static int cnt = 0;
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextColor(ST77XX_WHITE);
  tft.setTextSize(2);
  tft.setCursor(6, 6);
  tft.println("Counter:");
  tft.setTextSize(4);
  tft.setCursor(6, 30);
  tft.println(cnt);
  cnt++;
  if (cnt > 9999) cnt = 0;
  delay(1000);
}
