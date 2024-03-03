int soundsensor = A0;
int soundsensor1=8;
int clap = 0;
long detection_range_start  = 0;
long detection_range = 0;
 
void  setup() {
  pinMode(soundsensor, INPUT);
  pinMode(soundsensor1, INPUT);
  Serial.begin(9600);
 }

 
void loop() {
  int status_sensor = analogRead(soundsensor);
  int status_sensor1 = digitalRead(soundsensor1);
  int sensitivity = 300;
  if (status_sensor  == 0)
  {
    if (clap == 0)
    {
      detection_range_start = detection_range  = millis();
      clap++;
    }
    else if (clap > 0 && millis()-detection_range  >= 50)
    {
      detection_range = millis();
      clap++;
    }
  }
      //Serial.println(clap);
      Serial.print(status_sensor);
      Serial.print("\t");
      Serial.println(status_sensor1);
            Serial.print("clap :");
                  Serial.println(clap);
      delay(200);
}
