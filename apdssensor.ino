#include <Wire.h>
#include <SparkFun_APDS9960.h>

SparkFun_APDS9960 apds = SparkFun_APDS9960();

const int LED_PIN = 3;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  
  if (apds.init()) {
    Serial.println("APDS-9960 initialization complete");
  } else {
    Serial.println("APDS-9960 initialization failed");
  }

  // Start gesture sensing
  if (apds.enableGestureSensor(true)) {
    Serial.println("Gesture sensor enabled");
  } else {
    Serial.println("Failed to enable gesture sensor");
  }
}

void loop() {
  if (apds.isGestureAvailable()) {
    int gesture = apds.readGesture();

    switch (gesture) {
      case DIR_UP:
        Serial.println("Gesture: UP → LED ON");
        digitalWrite(LED_PIN, HIGH);
        break;

      case DIR_DOWN:
        Serial.println("Gesture: DOWN → LED OFF");
        digitalWrite(LED_PIN, LOW);
        break;

      case DIR_LEFT:
        Serial.println("Gesture: LEFT");
        break;

      case DIR_RIGHT:
        Serial.println("Gesture: RIGHT");
        break;

      default:
        Serial.println("Unknown gesture");
    }
  }
}
