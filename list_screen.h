#pragma once

#include "screen.h"

class ListScreen: public Screen {
  private:
  std::vector<String> *items;

  public:
  ListScreen(U8G2_SSD1306_128X64_NONAME_F_SW_I2C *u8g2, Buttons *buttons, std::vector<String> *items, void (*finish)()): Screen::Screen(u8g2, buttons){
    this->finish = finish;
    this->items = items;
  };

  virtual void update() override;
  virtual void draw() override;

};
