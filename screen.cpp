#include "screen.h"

Screen::Screen(U8G2_SSD1306_128X64_NONAME_F_SW_I2C *u8g2, Buttons *buttons, void (*finish)()) {
  this->u8g2 = u8g2;
  this->buttons = buttons;
  this->finish = finish;
}

void Screen::update() {
  
}

void Screen::draw() {
  this->u8g2->clearBuffer();

  // borders
  this->u8g2->drawFrame(0,0,128,64);
  this->u8g2->sendBuffer();
}
