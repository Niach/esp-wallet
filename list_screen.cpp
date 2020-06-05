#include "list_screen.h"


void ListScreen::update()  {
  if (this->buttons->wasDirectionPressed(both)) {
    Serial.println("both");
    this->finish();
  }

  if (this->buttons->wasDirectionPressed(right)) {
    if (this->selectedItem < this->items->size() - 1) {
      this->selectedItem++;  
    }
  }
  if (this->buttons->wasDirectionPressed(left)) {
    if (this->selectedItem > 0) {
      this->selectedItem--;  
    }
  }

}

void ListScreen::draw()  {
  this->u8g2->clearBuffer();
  for (int i = 0; i < this->items->size(); i++) {
      String toDraw = this->items->at(i);
      if (i == this->selectedItem) {
        toDraw += "();";
      }
      this->u8g2->drawStr(0, (i+1)*20, toDraw.c_str());
  }
  this->u8g2->sendBuffer();
}
