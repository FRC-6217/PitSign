#include <FastLED.h>

#define NUM_STRIPS 10
#define LED_B 24
#define LED_O 20
#define LED_M 30
#define LED_T 15
#define LED_Z 17
#define LED_CF 30
#define LED_BO 40
#define BRIGHTNESS 150

#define NUM_LEDS_PER_STRIP (40)

  uint8_t numLedPerLetter[] = {LED_CF, LED_B, LED_O, LED_M, LED_B, LED_B, LED_O, LED_T, LED_Z, LED_BO};
    CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];



void setup() {
  Serial.begin(9600);
  // Setup each letter with pin and numof of led per letter
  
  FastLED.addLeds<NEOPIXEL, 2>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 3>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 4>(leds[2], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 5>(leds[3], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 6>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 8>(leds[5], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 9>(leds[6], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 10>(leds[7], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 11>(leds[8], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 12>(leds[9], NUM_LEDS_PER_STRIP);  

  FastLED.setBrightness(BRIGHTNESS);
}

bool isReversed(int x) {
  return (x == 0 || x == 2 || x == 3 || x == 8);
}

void doYourThing(CRGB color,int skip) {
  
  int x = 0;
  for(x = 0; x < NUM_STRIPS; x++) {
    if(isReversed(x)) {
      int i = 0;
      for(i = numLedPerLetter[x] - 1; i >= 0; i = i - skip) {
        leds[x][i] = color;
        FastLED.show();
        delay(10);
      }
    }

    else {
      int i = 0;
      for(i = 0; i < numLedPerLetter[x]; i = i + skip) {
       leds[x][i] = color;
       FastLED.show();
       delay(10);
      }
    }
    delay(100);
  }
}; 

void loop() {

doYourThing(CRGB(255,0,90),1);
doYourThing(CRGB(0,205,185),1);
doYourThing(CRGB(158,50,0),1);
/*
doYourThing(CRGB::Red,1);

doYourThing(CRGB::Blue,1);

doYourThing(CRGB::Green,1);
*/

}
