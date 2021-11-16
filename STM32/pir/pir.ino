int pir = PA2;
int r = PA3;
int y = PA4;
int g = PA5;
int key = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(pir, INPUT);

pinMode(r, OUTPUT);
pinMode(y, OUTPUT);
pinMode(g, OUTPUT);
Serial.begin(9600);

digitalWrite(g, HIGH);

}

int convert (int x){
  if(x == 1){
    x = 0;
  }else {
    x = 1;
  }
  return x;
}

void transisi(){
  digitalWrite(y, HIGH);
  delay(250);
  digitalWrite(y, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int vpir = digitalRead(pir);
  vpir = convert(vpir);
  Serial.println(vpir);

  if (vpir == 1){
    digitalWrite(g, LOW);
    digitalWrite(y, HIGH);
    delay(250);
    digitalWrite(y, LOW);
    while(vpir == 1){
      digitalWrite(r, HIGH);
      vpir = digitalRead(pir);
      vpir = convert(vpir);
    }
  }
  else if (vpir == 0){
    digitalWrite(r, LOW);
    transisi();
    while(vpir == 0){
      digitalWrite(g, HIGH);
      vpir = digitalRead(pir);
      vpir = convert(vpir);
    }
  }
}
