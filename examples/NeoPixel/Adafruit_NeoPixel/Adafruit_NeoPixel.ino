/*******************************************************************************
 * Adafruit NeoPixel GFX Example
 * This is a simple GFX example for Adafruit_NeoPixel
 *
 * Dependent libraries:
 * Adafruit_NeoPixel: https://github.com/adafruit/Adafruit_NeoPixel.git
 ******************************************************************************/
#include <Arduino_GFX_Library.h>

// all settings in header file
#include "Adafruit_NeoPixel_GFX.h"
Arduino_GFX *gfx = new Adafruit_NeoPixel_GFX();
int16_t x;
uint16_t w, tw;

void setup(void)
{
  Serial.begin(115200);
  // Serial.setDebugOutput(true);
  // while(!Serial);
  Serial.println("Arduino_GFX Adafruit_NeoPixel example");

  // Init Display
  if (!gfx->begin())
  {
    Serial.println("gfx->begin() failed!");
  }
  gfx->fillScreen(RGB565_BLACK);

  x = 0;
  gfx->setCursor(x, 0);
  gfx->setTextColor(RGB565_RED);
  gfx->println("Hello World!");

  int16_t x1, y1;
  uint16_t h;
  gfx->getTextBounds("Hello World!", 0, 0, &x1, &y1, &w, &h);
  tw = w;
  w = gfx->width();

  delay(1000); // 1 seconds
}

void loop()
{
  x--;
  if (x < (-tw))
  {
    x = w - 1;
  }
  gfx->setCursor(x, 0);
  gfx->setTextColor(random(0xffff), RGB565_BLACK);
  gfx->println("Hello World!");

  delay(100); // 0.1 second
}
