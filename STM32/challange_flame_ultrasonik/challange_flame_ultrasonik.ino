#include <NewPing.h>

int pir = PA2;
int flame = PA1;

int r = PA3;
int y = PA4;
int g = PA5;

int trig = PB5;
int echo = PB6;
int batas = 800;
int key = 0;
NewPing cm(trig, echo, batas);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);

    pinMode(r, OUTPUT);
    pinMode(y, OUTPUT);
    pinMode(g, OUTPUT);
    
}

int sonik(int x){
  int lenght = cm.ping_cm();
  if (lenght == 0){
    lenght = 200;
  }else {
    lenght = lenght;
  }
  Serial.print("Jarak : ");
  Serial.print(lenght);
  Serial.println(" cm");
  delay(500);
  x = lenght;
  return x;
}

void blinking(int x){
  digitalWrite(r, HIGH);
  digitalWrite(y, HIGH);
  digitalWrite(g, HIGH);
  delay(x);
  digitalWrite(r, LOW);
  digitalWrite(y, LOW);
  digitalWrite(g, LOW);
  delay(x);
}

void flipflop(){
  for(int i = 3; i<=5; i++){
    digitalWrite(i, HIGH);
    delay(250);
    digitalWrite(i, LOW);
    delay(250);
  }
  for(int j = 5; j>=3; j--){
    digitalWrite(j, HIGH);
    delay(250);
    digitalWrite(j, LOW);
    delay(250);
  }
}

int convert (int x){
  if (x == 1){
    x = 0;
  }else {
    x = 1;
  }
  return x;
}

void loop() {
  // put your main code here, to run repeatedly:
  int vflame = digitalRead(flame);
  vflame = convert(vflame);
  Serial.println(vflame);

  if(vflame == 1 && key == 0){
    delay(250);
      int jarak = cm.ping_cm();
      Serial.print("Jarak : ");
      Serial.print(jarak);
      Serial.println(" cm");
    if (jarak != 0 && jarak >= 1 && jarak <= 10)
    {   
        digitalWrite(r, HIGH);
        digitalWrite(y, HIGH);
        digitalWrite(g, HIGH);
        delay(100);
        digitalWrite(r, LOW);
        digitalWrite(y, LOW);
        digitalWrite(g, LOW);
        delay(100);
    }
    else if(jarak != 0 && jarak >= 11 && jarak <= 50)
    {
        digitalWrite(r, HIGH);
        digitalWrite(y, HIGH);
        digitalWrite(g, HIGH);
        delay(1000);
        digitalWrite(r, LOW);
        digitalWrite(y, LOW);
        digitalWrite(g, LOW);
        delay(1000);
    }
    else if(jarak > 50 || jarak == 0)
    {
        digitalWrite(r, HIGH);
        delay(100);
        digitalWrite(r, LOW);
        digitalWrite(y, HIGH);
        delay(100);
        digitalWrite(y, LOW);
        digitalWrite(g, HIGH);
        delay(100);
        digitalWrite(g, LOW);
        digitalWrite(y, HIGH);
        delay(100);
        digitalWrite(y, LOW);
    }
    key = 1;
   }
   /*
   if (vflame == 0 && key == 1){
      delay(250);
      int jarak = cm.ping_cm();
      Serial.print("Jarak : ");
      Serial.print(jarak);
      Serial.println(" cm");
    if (jarak != 0 && jarak >= 1 && jarak <= 10)
    {
        digitalWrite(r, HIGH);
        digitalWrite(y, HIGH);
        digitalWrite(g, HIGH);
        delay(100);
        digitalWrite(r, LOW);
        digitalWrite(y, LOW);
        digitalWrite(g, LOW);
        delay(100);
    }
    else if(jarak != 0 && jarak >= 11 && jarak <= 50)
    {
        digitalWrite(r, HIGH);
        digitalWrite(y, HIGH);
        digitalWrite(g, HIGH);
        delay(1000);
        digitalWrite(r, LOW);
        digitalWrite(y, LOW);
        digitalWrite(g, LOW);
        delay(1000);
    }
    else if(jarak > 50 || jarak == 0)
    {
        digitalWrite(r, HIGH);
        delay(100);
        digitalWrite(r, LOW);
        digitalWrite(y, HIGH);
        delay(100);
        digitalWrite(y, LOW);
        digitalWrite(g, HIGH);
        delay(100);
        digitalWrite(g, LOW);
        digitalWrite(y, HIGH);
        delay(100);
        digitalWrite(y, LOW);
    }
   }
  */
  else if ( vflame == 1 && key == 1){
    delay(250);
    digitalWrite(r, LOW);
    digitalWrite(y, LOW);
    digitalWrite(g, LOW);
    key = 0;
  }
  

}
