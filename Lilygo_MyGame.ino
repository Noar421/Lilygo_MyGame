#include "Config.h"

TFT_eSPI tft = TFT_eSPI();            // Invoke library
TFT_eSprite img = TFT_eSprite(&tft);  // Create Sprite object "img" with pointer to "tft" object

void setup() {
  // Configure buttons
  pinMode(PIN_BUTTON1, INPUT);
  pinMode(PIN_BUTTON2, INPUT);
  
  // 
  Serial.begin(115200);

  // TFT initialization
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 0, 2);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(1);

}

void loop() {

}
