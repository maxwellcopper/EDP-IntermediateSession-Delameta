int flame = A1;
int buzz = 5;
int r = 9;
int y = 10;
int g = 11;


void setup() {
  // put your setup code here, to run once:
pinMode(5, OUTPUT);
Serial.begin(9600);

pinMode(r, OUTPUT);
pinMode(y, OUTPUT);
pinMode(g, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int vflame = analogRead(flame);
  vflame = map(vflame,22,1016,100,0);
  Serial.print("Nilai Flame : ");
  Serial.print(vflame);
  Serial.println();

  if(vflame == 0){
    delay(150);
    Serial.println("AMAAAN BOIII");
    digitalWrite(buzz, LOW);
    digitalWrite(r, LOW);
    digitalWrite(y, LOW);
    digitalWrite(g, HIGH);
  } else if (vflame >= 20 && vflame <=50){
    delay(150);
    Serial.println("WARNINGG BOIII");
    digitalWrite(r, LOW);
    digitalWrite(y, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(buzz, HIGH);
    delay(500);
    digitalWrite(buzz, LOW);
    delay(250);
  } else if (vflame > 50){
    delay(150);
    Serial.println("NGUNGSI BOIII");
    digitalWrite(r, HIGH);
    digitalWrite(y, LOW);
    digitalWrite(g, LOW);
    digitalWrite(buzz, HIGH);
    delay(100);
    digitalWrite(buzz, LOW);
    delay(100);
  }

/*
  analogWrite(r, vflame);
  analogWrite(y, vflame);
  analogWrite(g, vflame);
*/
}
