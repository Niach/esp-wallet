#pragma once
#include <Arduino.h>

#define LEFT_BUTTON_PIN 18
#define RIGHT_BUTTON_PIN 23

enum Direction {
  none, left, right, both
};

class Buttons {
  private:
  Direction lastInput = none;

  
  public:
  Direction currentInput = none;

  void init();
  void handleInput();
  bool wasDirectionPressed(Direction direction);
};
