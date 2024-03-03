#include <FastLED.h> 
int a,b,c,d,e,f,g,h,j=0; //Variables to store Sensor data

#define NUM_LEDS 60 
#define DATA_PIN 2 

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
  pinMode(4,INPUT); 
  pinMode(5,INPUT); 
  pinMode(6,INPUT); 
  pinMode(7,INPUT); 
  pinMode(8,INPUT); 
  pinMode(9,INPUT); 
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  
  LEDS.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS); 
  LEDS.setBrightness(84); 
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(250); } } 

void loop() { 
  a=digitalRead(4); 
  b=digitalRead(5); 
  c=digitalRead(6); 
  d=digitalRead(7); 
  e=digitalRead(8); 
  f=digitalRead(9); 
  g=digitalRead(10);
  h=digitalRead(11);
  
  static uint8_t hue = 0; 
 
  
  if(a==1)
  {
    if(b==1)
    {
  for(int i = 4; i < 55; i++) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(10);
                              }
    }
  }

  if(g==1)
{
  if(f==1)
  {
  // Now go in the other direction.  
  for(int i = (56)-1; i >= 4; i--) {
    // Set the i'th led to red 
    leds[i] = CHSV(hue++, 255, 255);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(10);
                                   }
  }
}
          }
