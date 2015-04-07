int ledPinsLen = 3;
int ledPins[3] = {9, 10, 11};
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

int cur = 0;
int last = -1;
void loop() {
  fadeOn(ledPins[cur], intensity, timer);
  
  if(last > -1){
    fadeOff(ledPins[last], intensity, timer);
  }
  
  last = cur;
  cur += 1;
  //if(cur > (ledPinsLen-1)){
  if(cur > 0){
    cur = 0;
  }
  
  delay(1000);
}
