#include <NewPing.h>

// inisialisasi
int pinLedR = PB10;
int pinLedY = PB1;
int pinLedG = PB0;
int pinPIR = PB3;
int pinFlame = PB11;
int pinTrigger = PA5;
int pinEcho = PA7;

int prevFlame = 0;
int prevPIR = 0;
int toggle = true;

// ultrasonik
int MAX_DISTANCE = 500;
NewPing us(pinTrigger, pinEcho);


int checkRising(int input, int& prev){
  int isRising = 0;
  if(prev == 0 && input == 1) {
    isRising = 1;
  }
  prev = input;
  return isRising;
}

int writeLED(int r, int y, int g) {
  digitalWrite(pinLedR, r);
  digitalWrite(pinLedY, y);
  digitalWrite(pinLedG, g);
}

void blink(int dduration){
  writeLED(1,1,1);
  delay(dduration);
  writeLED(0,0,0);
  delay(dduration);
}

void flipflop(int dduration) {
  writeLED(1,0,0);
  delay(dduration);
  writeLED(0,1,0);
  delay(dduration);
  writeLED(0,0,1);
  delay(dduration);
  writeLED(0,1,0);
  delay(dduration);
}

// setup 
void setup() {
  Serial.begin(9600);
  pinMode(pinLedR, OUTPUT);
  pinMode(pinLedY, OUTPUT);
  pinMode(pinLedG, OUTPUT);

  pinMode(pinFlame, INPUT);
  pinMode(pinPIR, INPUT);
}

void loop(){
  
  // baca input
  int readFlame = !digitalRead(pinFlame);
  int readPIR = !digitalRead(pinPIR);
  int risingFlame = checkRising(readFlame, prevFlame);
  int risingPIR = checkRising(readPIR, prevPIR);
  int readUS = us.ping_cm();

  // print
  Serial.print("readFlame=" + String(readFlame));
  Serial.print(", risingFlame=" + String(risingFlame));
  Serial.print(", readPIR=" + String(readPIR));
  Serial.print(", risingPIR=" + String(risingPIR));
  Serial.print(", readUS=" + String(readUS));
  Serial.print(", toggle=" + String(toggle));
  Serial.println();

  // logic
  if(risingFlame || risingPIR) toggle = !toggle;

  if(toggle) {
    if(readUS < 10 && readUS > 0) {
      blink(30);
    } else if (readUS < 30 && readUS > 0) {
      blink(350);
    } else {
      flipflop(100);
    }
  } else {
    writeLED(0,0,0);
  }


}
