#pragma once

#include <Arduino.h>
//#include <U8g2lib.h>

String getAddress(String accountNumber, String addressNumber);
void generateSeed();
String getSeed();
String signPSBT(String psbt_data);
void init(bool newSeed);
