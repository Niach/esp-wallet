#include "confirmation_screen.h"


void ConfirmationScreen::update()  {
  if (this->buttons->wasDirectionPressed(right)) {
    this->finish();
  }
  
}

void ConfirmationScreen::draw()  {
  this->u8g2->clearBuffer();
  this->u8g2->drawStr(0, 40, this->message.c_str());
  this->u8g2->setBitmapMode(false);
  this->u8g2->drawXBMP(90, 21, 26, 19, check_icon);
  
  this->u8g2->sendBuffer();
}
