#include <Arduino.h>
#include "Bitcoin.h"
#include <EEPROM.h>
#include "hardware_wallet.h"
#include <Preferences.h>

String getValue(String data, char separator, int index);


Preferences preferences;
HDPrivateKey hd;

String getAddress(int accountNumber, int addressNumber) {
  HDPrivateKey account = hd.derive("m/84'/0'/0'/");
  return account.derive("m/0/0/").address();
}

/*
void printAddress(U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2) {
  u8x8.clear();
  u8x8.drawString(0, 0,"First Address:");
  String toDraw = getAddress(0, 0);
  for (int i = 0; i < toDraw.length(); i+=16) {
    u8x8.drawString(0, i/16 + 2, toDraw.substring(i, i+16).c_str());
  }
}*/

String getSeed() {
  preferences.begin("wallet", false);
  String seed = preferences.getString("seed", "");
  preferences.end();
  return seed;
}

void generateSeed() {
  preferences.begin("wallet", false);
  preferences.clear();
  preferences.putString("seed", generateMnemonic(256));  
  preferences.end(); 
}
/*
void printSeed(U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2) {
  u8x8.clear();
  String seed = getSeed();
  for(int i = 0; i < 24; i++) {
    String seed_word = getValue(seed, ' ', i);
    String line = (String(i+1) + ": "  + seed_word);
    Serial.println(line);
    u8x8.drawString(0, i%8, line.c_str());
    if(i == 7 || i == 15 || i == 23) {
      delay(2000);
      u8x8.clear();
    }
  }
}*/


void init(bool newSeed) {
  String seed = getSeed();
  if (seed.length() == 0 || newSeed) {
    Serial.println("generate new seed");
    generateSeed();
    seed = getSeed();
  }

  Serial.println("Seed: " + seed);

  hd = HDPrivateKey(seed, "");
}


// split helper
String getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
