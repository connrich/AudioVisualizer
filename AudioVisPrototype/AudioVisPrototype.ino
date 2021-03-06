#include <FHT.h>

#include "FastLED.h"

//Define how many LEDs and which pin they connect to 
#define NUM_LEDS 64
#define DATA_PIN A0

//Set up some memory space or something idk
CRGB leds[NUM_LEDS];

void setup() {
  //Add set of LEDs
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}

void loop() {
  //Turn on the first LED green and last LED red
  leds[0] = CRGB::Green;
  leds[63] = CRGB::Red;

}
