    #include <FastLED.h>
    #define NUM_STRIPS 8
    #define LED_B 24
    #define LED_O 20
    #define LED_M 30
    #define LED_T 15
    #define LED_Z 17
    
    /*
    #define B0_INDEX (0)
    #define O0_INDEX (1)
    #define M0_INDEX (2)
    #define B1_INDEX (3)
    #define B2_INDEX (4)
    #define O1_INDEX (5)
    #define T0_INDEX (6)
    #define Z0_INDEX (7)
    */
#define NUM_LEDS_PER_STRIP (30)

  uint8_t numLedPerLetter[] = {LED_B, LED_O, LED_M, LED_B, LED_B, LED_O, LED_T, LED_Z};
    CRGB leds[NUM_STRIPS][NUM_LEDS_PER_STRIP];

   // struct Letter {
    //  uint8_t numLed;
    //  CRGB ledArray[LED_M];//Has the Most LEDS
    //};

  //Letter letterList[8];




void setup() {
  Serial.begin(9600);
  // Setup each letter with pin and numof of led per letter
  

  //Setup led 
  //FastLED.addLeds<NEOPIXEL, letterList[B0_INDEX].pin>(letterList[B0_INDEX], letterList[B0_INDEX].numLed);
 //   FastLED.addLeds<NEOPIXEL, pinArray[0]>(letterList[0].ledArray, letterList[0].numLed);

/*
  FastLED.addLeds<NEOPIXEL, 3>(letterList[B0_INDEX].ledArray, letterList[B0_INDEX].numLed);
  FastLED.addLeds<NEOPIXEL, 4>(letterList[O0_INDEX].ledArray, letterList[O0_INDEX].numLed);
  FastLED.addLeds<NEOPIXEL, 5>(letterList[M0_INDEX].ledArray, letterList[M0_INDEX].numLed);
  FastLED.addLeds<NEOPIXEL, 6>(letterList[B1_INDEX].ledArray, letterList[B1_INDEX].numLed);
  FastLED.addLeds<NEOPIXEL, 8>(letterList[B2_INDEX].ledArray, letterList[B2_INDEX].numLed);
  FastLED.addLeds<NEOPIXEL, 9>(letterList[O1_INDEX].ledArray, letterList[O1_INDEX].numLed);
  FastLED.addLeds<NEOPIXEL, 10>(letterList[T0_INDEX].ledArray, letterList[T0_INDEX].numLed);
  FastLED.addLeds<NEOPIXEL, 11>(letterList[Z0_INDEX].ledArray, letterList[Z0_INDEX].numLed);
*/



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
  
  //for(i = 0; i < index.numLed; i++) //each led


 /*
  // This outer loop will go over each strip, one at a time
  int x = 0;
  int i = 0;
  for( x = 0; x < NUM_STRIPS; x++) {
    // This inner loop will go over each led in the current strip, one at a time
    for( i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      leds[x][i] = CRGB::Red;
      FastLED.show();
      //leds[x][i] = CRGB::Black;
      delay(50);
    }
    delay(1000);
  }  
  delay(10000);
  for( x = 0; x < NUM_STRIPS; x++) {
    for( i = 0; i < NUM_LEDS_PER_STRIP; i++) {
      leds[x][i] = CRGB::Black;
      FastLED.show();
      //leds[x][i] = CRGB::Black;
      delay(50);
    }
    delay(1000);
  }  
  */
}
