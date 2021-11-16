#include <OneWire.h>
#include <DallasTemperature.h>
#include <NewPing.h>

//inisialisasi
int suhu = 8;
OneWire oneWire(suhu);
DallasTemperature sensors(&oneWire);

int r = 5;
int y = 6;
int g = 7;
int buzz = 3;

int trig = 11;
int echo = 12;
int batas = 400;

NewPing cm(trig, echo, batas);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int lenght = cm.ping_cm();
  
  Serial.print("Jarak : ");
  Serial.print(lenght);
  Serial.println(" cm");
  delay(500);
  
  if( (lenght <= 20) and (lenght != 0) ){
      Serial.println("Berhenti!!!!");
      delay(200);
      digitalWrite(g, LOW);
      digitalWrite(y, LOW);
      digitalWrite(r, HIGH);
      digitalWrite(buzz, HIGH);
      delay(50);
      digitalWrite(buzz, LOW);
      delay(50);
  }else if ( (lenght >= 21) && (lenght<=70) ) {
      Serial.println("BAHAYA BOII");
      delay(200);
      digitalWrite(g, LOW);
      digitalWrite(y, HIGH);
      digitalWrite(r, LOW);
      digitalWrite(buzz, HIGH);
      delay(300);
      digitalWrite(buzz, LOW);
      delay(300);
  }else if (lenght >= 71 or lenght == 0) {
      Serial.println("AMAN SLOO");
      delay(200);
      digitalWrite(g, HIGH);
      digitalWrite(y, LOW);
      digitalWrite(r, LOW);
      digitalWrite(buzz, LOW);
  }

  

}
