int ButtonPin = 8;
int RedPin = 9;
int GreenPin = 10;
int BluePin = 11;
bool ButtonState = 0;
bool IsPress = 0;
int LEDState = 0;
long TermSerial = 0, Interval = 100;
void setup() {
  // put your setup code here, to run once:
  pinMode(RedPin, OUTPUT);  
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin, OUTPUT);
  pinMode(ButtonState, INPUT);
  Serial.begin(9600);
}

void loop() {

  unsigned long CurentSerial = millis();

  if(CurentSerial - TermSerial >= Interval){
    TermSerial = CurentSerial;
    if(LEDState == 0){
      digitalWrite(RedPin, 1);      
      digitalWrite(GreenPin, 1);
      digitalWrite(BluePin, 1);

    }
    else if(LEDState == 1){
      digitalWrite(RedPin, 0);      
      digitalWrite(GreenPin, 1);
      digitalWrite(BluePin, 1);

    }
    else if(LEDState == 2){
      digitalWrite(RedPin, 1);      
      digitalWrite(GreenPin, 0);
      digitalWrite(BluePin, 1);
    }
    else if(LEDState == 3){
      digitalWrite(RedPin, 1);      
      digitalWrite(GreenPin, 1);
      digitalWrite(BluePin, 0);

    }
    else if(LEDState == 4){
      digitalWrite(RedPin, 0);      
      digitalWrite(GreenPin, 0);
      digitalWrite(BluePin, 1);
    }
    else if(LEDState == 5){
      digitalWrite(RedPin, 0);      
      digitalWrite(GreenPin, 1);
      digitalWrite(BluePin, 0);

    }
    else if(LEDState == 6){
      digitalWrite(RedPin, 1);      
      digitalWrite(GreenPin, 0);
      digitalWrite(BluePin, 0);
    }
    else if(LEDState == 7){
      digitalWrite(RedPin, 0);      
      digitalWrite(GreenPin, 0);
      digitalWrite(BluePin, 0);

    }
    else if(LEDState == 8){
      LEDState = 1;
    }
  }
  if(!digitalRead(ButtonPin) && !IsPress){
    IsPress = 1;
    LEDState++;
  }
  else if(digitalRead(ButtonPin) && IsPress)
  {
    IsPress = 0;
  }
}