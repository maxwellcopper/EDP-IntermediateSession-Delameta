int r = 2;
int y = 3;
int g = 4;
int x = 500;
void setup() {
  // put your setup code here, to run once:
  for (int i=2; i<=4; i++){
    pinMode(i, OUTPUT);
  }
  
  /*pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
  */
}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i=2; i<=4; i++){
    digitalWrite(i, HIGH);
    delay(250);
    digitalWrite(i, LOW);
    delay(250);
  }
}
