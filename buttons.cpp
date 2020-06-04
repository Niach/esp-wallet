#include <Arduino.h>
#include "buttons.h"


void Buttons::init() {
  pinMode(LEFT_BUTTON_PIN, INPUT);
  pinMode(RIGHT_BUTTON_PIN, INPUT);

}

void Buttons::handleInput() {
  int leftInput = digitalRead(LEFT_BUTTON_PIN);
  int rightInput = digitalRead(RIGHT_BUTTON_PIN);

  lastInput = currentInput;

  if (leftInput == HIGH && rightInput == LOW) {
    currentInput = left;
  } else if (leftInput == LOW && rightInput == HIGH) {
    currentInput = right;
  } else if (leftInput == HIGH && rightInput == HIGH) {
    currentInput = both;
  } else {
    currentInput = none;
  }

}

bool Buttons::wasDirectionPressed(Direction direction) {
   return lastInput == direction && currentInput == none;
}
