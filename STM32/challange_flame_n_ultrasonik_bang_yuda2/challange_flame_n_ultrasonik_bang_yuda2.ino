#include <NewPing.h>

// inisialisasi
int pinFlame = PB11;
int pinLedR = PB10;
int pinLedY = PB1;
int pinLedG = PB0;
int pinTrigger = PA5;
int pinEcho =   PA7;

int prev = 0;
int toggle = 0;

// ultrasonik
int maxDistance = 5000;
NewPing ultraSonik(pinTrigger, pinEcho, maxDistance);

void setup() {
  Serial.begin(9600);
  pinMode(pinFlame, INPUT);
  pinMode(pinLedR, OUTPUT);
  pinMode(pinLedY, OUTPUT);
  pinMode(pinLedG, OUTPUT);
}

boolean checkRising(int input){
  boolean isRising = false;
  if(prev == 0 && input == 1) {
    isRising = true;
  }
  prev = input;
  return isRising;
}

void writeLED(int r, int y, int g) {
  digitalWrite(pinLedR, r);
  digitalWrite(pinLedY, y);
  digitalWrite(pinLedG, g);
}

void loop() {

  // baca input
  int readFlame = digitalRead(pinFlame);
  boolean rising = checkRising(readFlame);
  int readUS = ultraSonik.ping_cm();

  // print
  Serial.print("Flame=" + String(readFlame));
  Serial.print(" rising=" + String(rising));
  Serial.print(" readUS=" + String(readUS));
  Serial.print(" toggle=" + String(toggle));
  Serial.println();

  // logic
  if(rising) toggle = !toggle;

  if(toggle) {
    if(readUS < 10 && readUS > 0) {
      writeLED(1,0,0);
    } else if (readUS < 30 && readUS > 0) {
      writeLED(0,1,0);
    } else {
      writeLED(0,0,1);
    }
  } else {
    writeLED(0,0,0);
  }

}
