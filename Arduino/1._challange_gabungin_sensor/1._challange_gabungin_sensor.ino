int flame = A1;
int ldr = A0;
int pir = 2;
int buzz = 5;
int r = 9;
int y = 10;
int g = 11;


void setup() {
  // put your setup code here, to run once:
pinMode(5, OUTPUT);
Serial.begin(9600);
pinMode(pir, INPUT);
pinMode(r, OUTPUT);
pinMode(y, OUTPUT);
pinMode(g, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int vflame = analogRead(flame);
  vflame = map(vflame,22,1016,100,0);
  int vldr = analogRead(ldr);
  vldr = map(vldr,0,1024,0,255);
  int vpir = digitalRead(pir);

  //flame
  Serial.print("Nilai Flame : ");
  Serial.print(vflame);
  //ldr
  Serial.print("      Nilai ldr : ");
  Serial.print(vldr);
  //pir
  Serial.print("                    Nilai pir : ");
  Serial.println(vpir);

  if(vflame == 0){
    delay(150);
    digitalWrite(buzz, LOW);
  } else if (vflame >= 20 && vflame <=50){
    delay(150);
    digitalWrite(buzz, HIGH);
    delay(500);
    digitalWrite(buzz, LOW);
    delay(250);
  } else if (vflame > 50){
    delay(150);
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(100);
  }
  
  analogWrite(r, vldr);
  analogWrite(y, vldr);
  analogWrite(g, vldr);
}
