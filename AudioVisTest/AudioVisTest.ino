#include <FHT.h>
#include "FastLED.h"

//Define how many LEDs and which pin they connect to 
#define NUM_LEDS 64
#define DATA_PIN A0
#define MIC_PIN A1

//Set up some memory space or something idk
CRGB leds[NUM_LEDS];

void setup() {
  //Serial init
  Serial.begin(9600);
  
  //Add set of LEDs
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(MIC_PIN, INPUT);

  //Turn on the first LED green and last LED red
  leds[0] = CRGB::Green;
  leds[63] = CRGB::Red;
}

void loop() {
  int avg = 0;
  
  for(int i = 1; i <256; i++){
    avg += analogRead(MIC_PIN)/i;
//    Serial.println(analogRead(MIC_PIN));
  }
  Serial.println(avg);
}
