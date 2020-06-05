#include <U8g2lib.h>
#include "hardware_wallet.h"
#include "buttons.h"
#include "confirmation_screen.h"
#include "list_screen.h"
#include "splash_screen.h"


U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 22, /* data=*/ 21, /* reset=*/ 16);
Buttons buttons;
Screen *currentScreen;

std::vector<String> items = { "pair", "seed", "settings" };

void setup() {
  Serial.begin(115200);

  buttons.init();

  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB14_tr);

  init(true);

  currentScreen = new SplashScreen(&u8g2, &buttons, 28, showList);

  //printSeed(u8x8);
  delay(2000);
  //printAddress(u8x8);
}

void loop() {
  Serial.println("loop");
  buttons.handleInput();
  currentScreen->update();
  currentScreen->draw();

}

void showList() {
  Serial.println("finish splash");

  currentScreen = new ListScreen(&u8g2, &buttons, &items, onListFinish);
}

void onListFinish() {
  Serial.println("list finish");
}
