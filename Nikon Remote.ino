// adapted from:
// Nikon Remote Emulator by Gough Lui (http://goughlui.com)

bool released = false;

void setup() {
  pinMode(6, OUTPUT);
  digitalWrite(6, LOW);
  pinMode(8, INPUT_PULLUP);
}

void ML3(){
  // Delays are tuned to account for overhead of library code.
    tone(6,38000);
    delay(2);
    noTone(6);
    delay(28);//original delay 28ms
    tone(6,38000);
    delayMicroseconds(200);
    noTone(6);
    delayMicroseconds(1500);
    tone(6,38000);
    delayMicroseconds(200);
    noTone(6);
    delayMicroseconds(3300);
    tone(6,38000);
    delayMicroseconds(200);
    noTone(6);
}

void loop() {
  if (digitalRead(8) == LOW && released){
    ML3(); //transmit the remote signal
    released = false;    
  } else if (digitalRead(8) == HIGH){
    released = true;
  }
}



