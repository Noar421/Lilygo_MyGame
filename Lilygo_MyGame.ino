#include "Config.h"

TFT_eSPI tft = TFT_eSPI();            // Invoke library
TFT_eSprite img = TFT_eSprite(&tft);  // Create Sprite object "img" with pointer to "tft" object

Level level;
Player player;

bool button1 = false;
bool button2 = false;
bool buttonPressed = false;

unsigned long prevMillis = 0;

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

  //
  level = Level();
  player = Player();

  //
  level.setup();
  player.setup(int(IWIDTH / 2), int(IHEIGHT / 2));
}

void loop() {
  // Calcul dt
  // TODO : gerer le rollback
  unsigned long curMillis = millis();
  uint dt = curMillis - prevMillis;
  prevMillis = curMillis;

  // Buttons detection
  if (digitalRead(PIN_BUTTON1) == 0) {
    if (!buttonPressed) {
      buttonPressed = true;
      button1 = true;
    }

  } else if (digitalRead(PIN_BUTTON2) == 0) {
    if (!buttonPressed) {
      buttonPressed = true;
      button2 = true;
    }

  } else {
    buttonPressed = false;
  }

  int dx = 0;
  if (button1) {
    dx += 1;
  }
  if (button2) {
    dx -= 1;
  }

  img.createSprite(IWIDTH, IHEIGHT);
  img.fillSprite(TFT_BLACK);

  level.update(img);
  player.update(dx, 0, img, dt);

  // Push the screen buffer
  img.pushSprite(0, 0);

  // Delete sprite to free up the memory
  img.deleteSprite();
}
