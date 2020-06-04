#include "list_screen.h"


void ListScreen::update()  {
  if (this->buttons->wasDirectionPressed(both)) {
    this->finish();
  }

}

void ListScreen::draw()  {
  this->u8g2->clearBuffer();
  for (int i = 0; i < this->items->size(); i++) {
      this->u8g2->drawStr(0, i*32, "ListItem");
  }
  this->u8g2->sendBuffer();
}
