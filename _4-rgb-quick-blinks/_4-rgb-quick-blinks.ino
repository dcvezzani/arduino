int ledPinsLen = 3;
int ledPins[3] = {9, 10, 11};
int ledCyclePin = 12;
int inc = 5;

int timer = 20;
int intensity = 255;

void setup() {
  for(int i=0; i<ledPinsLen; i++){
    pinMode(ledPins[i], OUTPUT);
  }
}

void turnOn(int ledPin, int intensity, int timer){
    analogWrite(ledPin, intensity);
    delay(timer);
}

void turnOff(int ledPin, int intensity, int timer){
    analogWrite(ledPin, intensity);
    delay(timer);
}

void dTurnOn(int ledPin, int timer){
    digitalWrite(ledPin, HIGH);
    delay(timer);
}

void dTurnOff(int ledPin, int timer){
    digitalWrite(ledPin, LOW);
    delay(timer);
}

void fadeOn(int ledPin, int intensity, int timer){
    for(int j=0; j<intensity; j+=inc){
      analogWrite(ledPin, j);
      delay(timer);
    }    
}

void fadeOff(int ledPin, int intensity, int timer){
    for(int j=255; j>=intensity; j-=inc){
      analogWrite(ledPin, j);
      delay(timer);
    }    
}

void loop() {
  for(int i=0; i < 4; i++){
    
    for(int j=0; j<ledPinsLen; j++){
      //turnOn(ledPins[j], intensity, timer);
      fadeOn(ledPins[j], intensity, timer);
    }    
    
    for(int j=0; j<ledPinsLen; j++){
      //turnOff(ledPins[j], 0, timer);
      fadeOff(ledPins[j], 0, timer);
    }    
    
  }
  
  delay(2000);  
}
