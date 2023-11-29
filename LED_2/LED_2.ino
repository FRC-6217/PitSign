#include <FastLED.h

#define NUM_STRIPS 8
#define LED_B 24
#define LED_O 20
#define LED_M 30
#define LED_T 15
#define LED_Z 17

#define NUM_LEDS_PER_STRIP (30)

  uint8_t numLedPerLetter[] = {LED_B, LED_O, LED_M, LED_B, LED_B, LED_O, LED_T, LED_Z};
    CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];



void setup() {
  Serial.begin(9600);
  // Setup each letter with pin and numof of led per letter
  

  FastLED.addLeds<NEOPIXEL, 3>(leds[0], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 4>(leds[1], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 5>(leds[2], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 6>(leds[3], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 8>(leds[4], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 9>(leds[5], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 10>(leds[6], NUM_LEDS_PER_STRIP);
  FastLED.addLeds<NEOPIXEL, 11>(leds[7], NUM_LEDS_PER_STRIP);


}

void loop() {


  int x = 0;
  for(x = 0; x < NUM_STRIPS; x++) {
    if(x == 1 || x == 2 ) {
      int i = 0;
      for(i = numLedPerLetter[x] - 1; i >= 0; i--) {
        leds[x][i] = CRGB::Red;
        FastLED.show();
        delay(50);
      }
    }


    else {
      int i = 0;
      for(i = 0; i < numLedPerLetter[x]; i++) {
       leds[x][i] = CRGB::Red;
       FastLED.show();
       delay(50);
      }
    }
    delay(50);
  }

  
  delay(100);
  for(x = NUM_STRIPS - 1; x >= 0; x--) {
    if(x == 1 || x == 2) {
      int i = 0;
      for(i = 0; i < numLedPerLetter[x]; i++) {
        leds[x][i] = CRGB::Black;
        FastLED.show();
        delay(50); 
     }
    }


    else {
      int i = 0;
      for(i = numLedPerLetter[x] - 1; i >= 0; i--) {
        leds[x][i] = CRGB::Black;
        FastLED.show();
        delay(50);
      }
    }
    delay(50); 
  }
}
