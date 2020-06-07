#include <U8g2lib.h>
#include "hardware_wallet.h"
#include "buttons.h"
#include "confirmation_screen.h"
#include "list_screen.h"
#include "splash_screen.h"

#ifdef ESP32
#include <WiFi.h>
#include <AsyncTCP.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#endif
#include <ESPAsyncWebServer.h>

AsyncWebServer server(80);




U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, /* clock=*/ 22, /* data=*/ 21, /* reset=*/ 16);
Buttons buttons;
Screen *currentScreen;

std::vector<String> items = { "pair", "seed", "settings" };

void setup() {
  Serial.begin(115200);

  buttons.init();

  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB14_tr);

  init(false);


  setupWifi();
  startServer();
  
  currentScreen = new SplashScreen(&u8g2, &buttons, 28, showList);
}

void loop() {
  buttons.handleInput();
  currentScreen->update();
  currentScreen->draw();

}

void setupWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.printf("WiFi Failed!\n");
    exit(-1);
    return;
  }

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  
}

void startServer() {
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String amount = signPSBT("70736274ff01007202000000014b30bba309cd2b8a3d51030f7731c283d8ca7bd03a750fd712206bf432bfe89c0000000000fdffffff02a08601000000000017a914c43ffc04e8fd52e70988da5a81347396e73882f28712bb0d0000000000160014d924a0e0e40ca2766bacba5db53cdc35eb3532d8f0e517000001011f40420f000000000016001470e54ab67c6b6c4eeb6a019a83332a43b909b1992206037b3a3a013c18228e7070c97bb5d8d2afe2fd749ee9ef77dc4ac20c208a4795a8180464238c54000080010000800000008000000000000000000000220203d3b09e954f3e05800bf3bb4aec4734f8d7e3a233d90bfd75c234df702a132bfe180464238c540000800100008000000080010000000000000000");
    request->send(200, "text/plain", amount);
  });

  server.on("/address", HTTP_GET, [](AsyncWebServerRequest *request){
    if(request->hasParam("account") && request->hasParam("offset")) {
      AsyncWebParameter* account = request->getParam("account");
      AsyncWebParameter* offset = request->getParam("offset");


      String accountValue = account->value();
      String offsetValue = offset->value();

      String address = getAddress(accountValue, offsetValue);

      
      request->send(200, "text/plain", address);
    } else {
      request->send(400, "text/plain", "");
    }
  });
  server.on("/seed", HTTP_GET, [](AsyncWebServerRequest *request){
    String seed = getSeed();
    request->send(200, "text/plain", seed);
  });
  
  server.begin();
  Serial.println("server started");
}

void showList() {
  Serial.println("finish splash");

  currentScreen = new ListScreen(&u8g2, &buttons, &items, onListFinish);
}

void onListFinish() {
  Serial.println("list finish");
}
