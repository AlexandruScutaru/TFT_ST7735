/*
Sleep Command example
Very simple, when sleep on DC/DC converter is stopped, Internal oscillator is stopped, and panel scanning is stopped
MCU interface and memory are still working and the memory keeps its contents.
NOTE:
The led background still active since it's NOT controlled by chip so the result it's a white screen until you turn off
the backlight!
*/

#include <SPI.h>
#include <TFT_ST7735.h>


/*
Teensy3.x and Arduino's
 You are using 4 wire SPI here, so:
 MOSI:  11//Teensy3.x/Arduino UNO (for MEGA/DUE refere to arduino site)
 MISO:  12//Teensy3.x/Arduino UNO (for MEGA/DUE refere to arduino site)
 SCK:   13//Teensy3.x/Arduino UNO (for MEGA/DUE refere to arduino site)
ESP8266-----------------------------------
Use:
#define __CS  16  //(D0)
#define __DC  5   //(D1)
#define __RST 4   //(D2)

 SCLK:D5
 MOSI:D7
 */
#define __CS  10
#define __DC  6
#define __RST 23
/*
Teensy 3.x can use: 2,6,10,15,20,21,22,23
 Arduino's 8 bit: any
 DUE: check arduino site
 If you do not use reset, tie it to +3V3
 */


TFT_ST7735 tft = TFT_ST7735(__CS, __DC, __RST);

void setup() {
  tft.begin();
  tft.fillScreen(RED);
  delay(500);
}

void loop(void) {
  tft.sleepMode(true);
  delay(1000);
  tft.sleepMode(false);
  delay(1000);
}