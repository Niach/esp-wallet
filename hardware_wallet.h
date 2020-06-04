#pragma once

#include <Arduino.h>
//#include <U8g2lib.h>

String getAddress(int accountNumber, int addressNumber);
//void printAddress(U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2);
void generateSeed();
String getSeed();
//void printSeed(U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2);
void init(bool newSeed);
