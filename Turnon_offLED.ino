int led_pin=12;
int toggle_pin=2;

int period = 300;
unsigned long timepresent = 0;
int output_pin = 8;
const int input_pin=7;
boolean current_input = LOW;
boolean last_input = LOW;
int led_state = LOW;
int i;
int timer;

void setup()
{
  Serial.begin(9600);
  pinMode(output_pin, OUTPUT);
  pinMode(toggle_pin, INPUT_PULLUP);
  pinMode(input_pin, INPUT_PULLUP);
  pinMode(led_pin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(toggle_pin),toggle, RISING);
  i=0;
}

boolean debounce(boolean last)
{
  boolean current = digitalRead(input_pin);
  if(last!=current)
  {
    delay(5);
    current = digitalRead(input_pin);
  }
  return current;
}

void loop()
{
  if(millis()- timepresent>period)
  {
    timepresent = millis();
    timer++;
    if(timer>5)
    {
      timer = 5;
    } 
  }
  Serial.print("timer = ");
  Serial.println(timer);
    current_input = debounce(last_input);
    if(last_input == LOW && current_input == HIGH)
    {
      i++;
      timer=0:
    }
    last_input=current_input;
    if(timer>3)
    {
      i=0;
    }
    if(i>=3)
    {
      digitalWrite(output_pin, HIGH);
    }
    else
    {
      digitalWrite(output_pin, LOW);
    }
    Serial.println(i);
}

void toggle()
{
  led_state=!led_starte;
  digitalWrite(led_pin, led_state);
}
