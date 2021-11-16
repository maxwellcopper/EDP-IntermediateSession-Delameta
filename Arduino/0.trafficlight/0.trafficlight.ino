int r = 2;
int y = 3;
int g = 4;
int x = 500;
void setup() {
  // put your setup code here, to run once:
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(r, HIGH); //merah laa boii
delay(1000);
digitalWrite(r, LOW);
delay(x);

digitalWrite(y, HIGH); //kuning ni boii
delay(250);
digitalWrite(y, LOW);
delay(250);

digitalWrite(g, HIGH); //ijo dong boii 
delay(1000);
digitalWrite(g, LOW);
delay(x);
}
