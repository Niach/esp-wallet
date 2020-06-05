#pragma once

#include "screen.h"
#include "icons.h"

class SplashScreen: public Screen {
  private:
  int currentFrame = 0;
  int duration;

  public:
  SplashScreen(U8G2_SSD1306_128X64_NONAME_F_SW_I2C *u8g2, Buttons *buttons, int duration, void (*finish)()): Screen::Screen(u8g2, buttons, finish){
    this->duration = duration;
  };

  virtual void update() override;
  virtual void draw() override;


  
  
};
