#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <RtcDS1302.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <Wire.h>
#include <RtcDS1307.h>

#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 4
#define SCREEN_ADDRESS 0x27

#define RELAY1 12
#define RELAY2 13
#define RELAY3 14
#define RELAY4 15
#define RECIEVER 25

LiquidCrystal_I2C screen(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_ADDRESS);
IRrecv irSensor(RECIEVER);
RtcDS1307<TwoWire> Rtc(Wire);
decode_results results;

bool wasError();

void setup()
{
  Serial.begin(115200);
  screen.init();
  screen.backlight();
  irSensor.enableIRIn();
  Rtc.Begin();
  RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
  printDateTime(compiled);
  Serial.println();
}