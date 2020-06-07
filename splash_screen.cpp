#include "splash_screen.h"
#include "icons.h"


void SplashScreen::update()  {
  this->currentFrame++;
  if (this->currentFrame > this->duration) {
    Serial.println("Duration over");
    this->finish();  
  }
}

void SplashScreen::draw()  {
  this->u8g2->clearBuffer();
  this->u8g2->drawStr(16,20, "prattle");
  this->u8g2->drawStr(46,36, "// wallet");

  this->u8g2->setBitmapMode(true);
  drawSoundIcon(this->u8g2, 14, 64-25, this->currentFrame % 28);
  drawSoundIcon(this->u8g2, 64, 64-25, 27 - this->currentFrame % 28);
  this->u8g2->sendBuffer();
}
