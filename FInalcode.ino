#include <FastLED.h>
#define LED_PIN 2
#define PING_PIN 7
#define NUM_LEDS 60
const int threshold = 40;
double dis;
bool p=false;
CRGB leds[NUM_LEDS];

void setup() {
  // put your setup code here, to run once:

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
  pinMode(LED_PIN,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  pinMode(PING_PIN, OUTPUT);
  long duration, inches, cm;
  digitalWrite(PING_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(PING_PIN, HIGH);
  delayMicroseconds(5);
  digitalWrite(PING_PIN, LOW);

  pinMode(PING_PIN, INPUT);
//  delay(100);
  duration = pulseIn(PING_PIN, HIGH);
  dis=duration*2/29;
//  Serial.print("distance = ");
//  Serial.println(dis);
  delay(200);
  if (dis<=threshold)
  {
    p=!p;
    Serial.print("Counter = ");
    Serial.println(c);
//    delay(500);
    if (p){
        for (int i=0; i<NUM_LEDS; i++){
          leds[i] = CRGB(255, 255 , 255);
          FastLED.setBrightness(50);
          FastLED.show();
          delay(50);
        

        ///GESTURE CONTROL PART HERE
        
        }
//      delay(500);
      }
       else
       {
          for (int i=0; i<NUM_LEDS; i++){
          leds[i] = CRGB(0, 0, 0);
//          FastLED.setBrightness(0);
          FastLED.show();
          delay(10);             
        }
//        delay(500);
        }
    

    
  }


}
