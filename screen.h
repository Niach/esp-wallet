#pragma once

#include <Arduino.h>
#include <U8g2lib.h>
#include "buttons.h"

class Screen {
  protected:
  U8G2_SSD1306_128X64_NONAME_F_SW_I2C *u8g2;
  Buttons *buttons;
  void (*finish)();
  public:

  Screen(U8G2_SSD1306_128X64_NONAME_F_SW_I2C *u8g2, Buttons *buttons, void (*finish)());

  virtual void update();
  virtual void draw();
};
