#include <OneWire.h>
#include <DallasTemperature.h>

//inisialisasi
int suhu = 8;
OneWire oneWire(suhu);
DallasTemperature sensors(&oneWire);

int r = 5;
int y = 6;
int g = 7;
int buzz = 3;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  sensors.begin();

  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures();
  float vsuhu = sensors.getTempCByIndex(0); //membaca data index 0 pada one wire 

 //serial monitor
  Serial.print("Suhu :  ");
  Serial.print(vsuhu);
  Serial.println("  C");

  //logika >32 buzzer bunyi, led merah nyala. kalo dibawahny led ijo aja 
  if(vsuhu >= 31 ){
      digitalWrite(g, LOW);
      digitalWrite(r, HIGH);
      digitalWrite(buzz, HIGH);
      delay(200);
      digitalWrite(buzz, LOW);
      delay(750);
  }else {
      digitalWrite(r, LOW);
      digitalWrite(buzz, LOW);
      digitalWrite(g, HIGH);
      delay(200);
  }

}
