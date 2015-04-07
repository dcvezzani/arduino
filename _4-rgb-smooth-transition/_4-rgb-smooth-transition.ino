int ledPinsLen = 3;
int ledPins[3] = {9, 10, 11};
int ledCyclePin = 12;
int inc = 1;

int timer = 5;
int intensity = 255;

int cur = -1;
int last = -1;

void setup() {
  for(int i=0; i<ledPinsLen; i++){
    pinMode(ledPins[i], OUTPUT);
  }
  
  pinMode(ledCyclePin, OUTPUT);
  
  analogWrite(ledPins[9], 255);
  analogWrite(ledPins[10], 255);
  analogWrite(ledPins[11], 0);
  
  cur = 0;
  last = 2;
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

void fadeOn(int ledPin, int timer){
    for(int j=0; j<256; j+=inc){
      analogWrite(ledPin, j);
      delay(timer);
    }    
}

void fadeOff(int ledPin, int timer){
    for(int j=255; j>=0; j-=inc){
      analogWrite(ledPin, j);
      delay(timer);
    }    
}

void loop() {
    
  fadeOff(ledPins[cur], timer);
  fadeOn(ledPins[last], timer);
  
  last = cur;
  cur = cur + 1;
  if(cur > (ledPinsLen-1)){
    cur = 0;
  }
      
/*  
  dTurnOn(ledCyclePin, timer);
  delay(200);
  dTurnOff(ledCyclePin, timer);
*/  
}
