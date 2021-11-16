int flame = PA1;
int r = PA3;
int y = PA4;
int g = PA5;

void setup() {
  // put your setup code here, to run once:
  pinMode(flame, INPUT);

  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int vflame = analogRead(flame);
  vflame = map(vflame, 4095, 253, 0, 100);
  Serial.println(vflame);
  delay(250);
  if(vflame == 0){
    digitalWrite(g, HIGH);
    digitalWrite(r, LOW);
    digitalWrite(y, LOW);
  }
  else if(vflame > 0 && vflame <= 50){
    digitalWrite(y, HIGH);
    digitalWrite(r, LOW);
    digitalWrite(g, LOW);
  }
  else if(vflame > 50){
    digitalWrite(r, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(y, LOW); 
  }

}
