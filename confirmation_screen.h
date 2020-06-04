#pragma once

#include "screen.h"

class ConfirmationScreen: public Screen {
  private:
  String message;


  public:
  ConfirmationScreen(U8G2_SSD1306_128X64_NONAME_F_SW_I2C *u8g2, Buttons *buttons, String message, void (*finish)()): Screen::Screen(u8g2, buttons){
    this->message = message;
    this->finish = finish;
  };

  virtual void update() override;
  virtual void draw() override;


  
  
};
