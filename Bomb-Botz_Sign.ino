#include <FastLED.h>

// MultiArrays - see https://github.com/FastLED/FastLED/wiki/Multiple-Controller-Examples for more info on
// using multiple controllers.  In this example, we're going to set up three NEOPIXEL strips on three
// different pins, each strip getting its own CRGB array to be played with

#include "FastLED.h"

#define delayms 150
#define fadeDelay 1
#define fadecount 2

//set nubmer of LEDs per strip
#define NUM_LEDS_B 23
#define NUM_LEDS_O 20 
#define NUM_LEDS_M 29
#define NUM_LEDS_T 11
#define NUM_LEDS_Z 14


//set data pin for LED strip
#define DATA_PIN_B1 3
#define DATA_PIN_O1 4
#define DATA_PIN_M 5
#define DATA_PIN_B2 6
#define DATA_PIN_B3 8
#define DATA_PIN_O2 9
#define DATA_PIN_T 10
#define DATA_PIN_Z 11

//create arrays of LED strip
CRGB ledsB1[NUM_LEDS_B];
CRGB ledsO1[NUM_LEDS_O];
CRGB ledsM[NUM_LEDS_M];
CRGB ledsB2[NUM_LEDS_B];
CRGB ledsB3[NUM_LEDS_B];
CRGB ledsO2[NUM_LEDS_O];
CRGB ledsT[NUM_LEDS_T];
CRGB ledsZ[NUM_LEDS_Z];

int randNumber; 

// addLeds multiple times, once for each strip
void setup() {
  //Serial.begin(9600); 
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_B1
  FastLED.addLeds<NEOPIXEL, DATA_PIN_B1>(ledsB1, NUM_LEDS_B);
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_O1
  FastLED.addLeds<NEOPIXEL, DATA_PIN_O1>(ledsO1, NUM_LEDS_O);
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_M
  FastLED.addLeds<NEOPIXEL, DATA_PIN_M>(ledsM, NUM_LEDS_M);
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_B2
  FastLED.addLeds<NEOPIXEL, DATA_PIN_B2>(ledsB2, NUM_LEDS_B);
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_B3
  FastLED.addLeds<NEOPIXEL, DATA_PIN_B3>(ledsB3, NUM_LEDS_B);
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_GEAR
  FastLED.addLeds<NEOPIXEL, DATA_PIN_O2>(ledsO2, NUM_LEDS_O);
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_T
  FastLED.addLeds<NEOPIXEL, DATA_PIN_T>(ledsT, NUM_LEDS_T);  
  // tell FastLED the NEOPIXEL leds on pin DATA_PIN_Z
  FastLED.addLeds<NEOPIXEL, DATA_PIN_Z>(ledsZ, NUM_LEDS_Z);

  randomSeed(analogRead(0));
}

void allFadeInOut(int red, int green, int blue) {
  float r, g, b;
  //fade in
  for(int i= 0; i <= 255; i++) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    allOn(CRGB(r,g,b));
    FastLED.show();
    FastLED.delay(fadeDelay);
  }

  //fade out
  for(int i = 255; i >= 0; i--) {
    r = (i/256.0)*red;
    g = (i/256.0)*green;
    b = (i/256.0)*blue;
    allOn(CRGB(r,g,b));
    FastLED.show();
    //FastLED.delay(fadeDelay);
  }

  
}
void allFadeCount(int count,int red, int green, int blue) {
  for(int i = 0; i < count; i++) {
    allFadeInOut(red,green,blue);
  }

}

void allOn(const struct CRGB &color) {
  fill_solid(ledsB1,NUM_LEDS_B,color);
  fill_solid(ledsO1,NUM_LEDS_O,color);
  fill_solid(ledsM,NUM_LEDS_M,color);
  fill_solid(ledsB2,NUM_LEDS_B,color);
  fill_solid(ledsB3,NUM_LEDS_B,color);
  fill_solid(ledsO2,NUM_LEDS_O,color);
  fill_solid(ledsT,NUM_LEDS_T,color);
  fill_solid(ledsZ,NUM_LEDS_Z,color);
}


void allOnDelay(const struct CRGB &color){
  fill_solid(ledsB1,NUM_LEDS_B,color);
  FastLED.show();
  delay(delayms);
  fill_solid(ledsO1,NUM_LEDS_O,color);
  FastLED.show();
  delay(delayms);
  fill_solid(ledsM,NUM_LEDS_M,color);
  FastLED.show();
  delay(delayms);
  fill_solid(ledsB2,NUM_LEDS_B,color);
  FastLED.show();
  delay(delayms);
  fill_solid(ledsB3,NUM_LEDS_B,color);
  FastLED.show();
  delay(delayms);
  fill_solid(ledsO2,NUM_LEDS_O,color);
  FastLED.show();
  delay(delayms);
  fill_solid(ledsT,NUM_LEDS_T,color);
  FastLED.show();
  delay(delayms);
  fill_solid(ledsZ,NUM_LEDS_Z,color);
  FastLED.show();
  delay(delayms);
}



/*
void gearCylon() {
  Serial.println("in gearCylon()");
  gearBlack();
  FastLED.show();
  for (uint8_t j = 0; j < NUM_LEDS_O; j++) {
    ledsO2[j] = CRGB::PaleTurquoise;
    if (j < NUM_LEDS_O) {
      ledsO2[j + 1] = CRGB::Gold;
    }
    if (j > 0) {
      //ledsO2 [j - 1] = CRGB::Black;
    }
    FastLED.show();
    FastLED.delay(gearDelay);
  }
  gearBlack();
  FastLED.show();
  for (int j = (NUM_LEDS_O - 1); j >= 0; j--) {
    //Serial.print("j=");
    //Serial.println(j);
    ledsO2[j] = CRGB::Gold;
    if (j < NUM_LEDS_O - 1) {
      ledsO2[j + 1] = CRGB::Gold;
    }
    if (j < NUM_LEDS_O - 1) {
      ledsO2[j + 1] = CRGB::Red;
    }
    FastLED.show();
    FastLED.delay(gearDelay);
  }
  gearBlack();
  FastLED.show();
  Serial.println("exit gearCylon()");
}*/

void loop() {
  //b1Black();
  randNumber = random(1,5);
  switch(randNumber) {
    case 1:
      allOnDelay(CRGB::Red);
      FastLED.show();;
      FastLED.delay(delayms);
      allOn(CRGB::Black);
      FastLED.show();;
      FastLED.delay(delayms);
    break;
    case 2:
      allFadeCount(1,124,252,0);  //lawn green
      FastLED.show();
      FastLED.delay(delayms);
    break;
    case 3:
      allFadeCount(1,255,255,0);   //yellow
      FastLED.show(); 
      FastLED.delay(delayms);
    break;
    case 4:
        allFadeCount(2,255,0,0);   //red
        FastLED.show();
        FastLED.delay(delayms);        
    break;
    case 5:
        allOnDelay(CRGB::Violet);
        FastLED.show();
        FastLED.delay(delayms);
    default:

      break;
  }

  
/*
  allOn(CRGB::Black);
  FastLED.show();
  allOn(CRGB::Green);
  FastLED.show();
  allOn(CRGB::Black);
  FastLED.delay(delayms);
  allFadeCount(1,255,0,0);
*/


  //FastLED.delay(delayms * 4);
}
