int ledpin=13;
int inputPin=2;
int pirState=LOW;
int val=0;

void setup(){
  pinMode(ledpin,OUTPUT);
  pinMode(ledpin,INPUT);
  Serial.begin(9600);
}

void loop(){
  val = digitalRead(inputPin);
  if(val == HIGH){
    digitalWrite(ledpin,HIGH);
    if(pirState == LOW){
      Serial.println("Motion");
      pirState = HIGH;
    }
  }
  else{
    digitalWrite(ledpin,LOW);
    if(pirState == HIGH){
      Serial.println("end");
      pirState=LOW;
    }
  }
}
