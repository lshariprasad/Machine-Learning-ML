#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

#define BUZZER   15
#define RELAY    23

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

String emotion = "";

// 😊 SMILING

void drawSmile() {
tft.fillCircle(64,40,30,ST77XX_YELLOW);
tft.fillCircle(50,30,5,ST77XX_BLACK);
tft.fillCircle(78,30,5,ST77XX_BLACK);
tft.drawFastHLine(50,55,28,ST77XX_BLACK);
}

// 😐 NEUTRAL

void drawNeutral() {
tft.fillCircle(64,40,30,ST77XX_YELLOW);
tft.fillCircle(50,30,5,ST77XX_BLACK);
tft.fillCircle(78,30,5,ST77XX_BLACK);
tft.drawFastHLine(50,55,28,ST77XX_BLACK);
}

// 😲 SURPRISED

void drawSurprise() {
tft.fillCircle(64,40,30,ST77XX_YELLOW);
tft.fillCircle(50,30,6,ST77XX_BLACK);
tft.fillCircle(78,30,6,ST77XX_BLACK);
tft.fillCircle(64,55,6,ST77XX_BLACK);
}

// 😴 SLEEPING

void drawSleep() {
tft.fillCircle(64,40,30,ST77XX_YELLOW);
tft.drawFastHLine(45,30,15,ST77XX_BLACK);
tft.drawFastHLine(73,30,15,ST77XX_BLACK);

tft.setTextSize(2);
tft.setTextColor(ST77XX_BLUE);
tft.setCursor(95,15);
tft.print("Z");
}

// ☹️ SAD
void drawSad() {
tft.fillCircle(64,40,30,ST77XX_YELLOW);
tft.fillCircle(50,30,5,ST77XX_BLACK);
tft.fillCircle(78,30,5,ST77XX_BLACK);
tft.drawFastHLine(50,60,28,ST77XX_BLACK);
}

// 😭 CRYING
void drawCry() {
tft.fillCircle(64,40,30,ST77XX_YELLOW);
tft.fillCircle(50,30,5,ST77XX_BLACK);
tft.fillCircle(78,30,5,ST77XX_BLACK);
tft.fillCircle(50,45,3,ST77XX_BLUE);
tft.fillCircle(78,45,3,ST77XX_BLUE);
tft.drawFastHLine(50,60,28,ST77XX_BLACK);
}

// 😡 ANGER
void drawAnger() {
tft.fillCircle(64,40,30,ST77XX_RED);
tft.fillCircle(50,30,5,ST77XX_BLACK);
tft.fillCircle(78,30,5,ST77XX_BLACK);
tft.drawLine(45,20,55,25,ST77XX_BLACK);
tft.drawLine(83,25,73,20,ST77XX_BLACK);
tft.drawFastHLine(50,60,28,ST77XX_BLACK);
}

// 👀 SEARCHING
void drawSearching() {
tft.fillCircle(64,40,30,ST77XX_YELLOW);
tft.fillCircle(50,30,8,ST77XX_BLACK);
tft.fillCircle(78,30,8,ST77XX_BLACK);
}

void setup() {

Serial.begin(115200);

pinMode(BUZZER,OUTPUT);
pinMode(RELAY,OUTPUT);

digitalWrite(RELAY,HIGH); // motor ON

tft.initR(INITR_BLACKTAB);
tft.fillScreen(ST77XX_BLACK);
}

void loop() {

if(Serial.available()) {


emotion = Serial.readStringUntil('\n');

tft.fillScreen(ST77XX_BLACK);

if(emotion == "SMILING") drawSmile();
if(emotion == "NEUTRAL") drawNeutral();
if(emotion == "SURPRISED") drawSurprise();
if(emotion == "SLEEPING") drawSleep();
if(emotion == "SAD") drawSad();
if(emotion == "CRYING") drawCry();
if(emotion == "ANGER") drawAnger();
if(emotion == "SEARCHING") drawSearching();

tft.setCursor(20,110);
tft.setTextSize(2);
tft.setTextColor(ST77XX_WHITE);
tft.print(emotion);

if(emotion == "SLEEPING") {

  digitalWrite(BUZZER,HIGH);
  digitalWrite(RELAY,LOW);  // stop motor

}

else {

  digitalWrite(BUZZER,LOW);
  digitalWrite(RELAY,HIGH); // motor running

}

}
}

