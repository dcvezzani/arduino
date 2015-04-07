int ledPin = 9;
int timer = 250;
int intensity = 255;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for(int i=0; i < 4; i++){
    analogWrite(ledPin, intensity);
    delay(timer);
    
    analogWrite(ledPin, 0);
    delay(timer);
  }
  
  delay(2000);
}
