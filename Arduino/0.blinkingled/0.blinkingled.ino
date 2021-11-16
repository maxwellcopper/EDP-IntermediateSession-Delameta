int r = 2;  
int y = 3;
int g = 4;
int x = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(r, HIGH);
digitalWrite(y, HIGH);
digitalWrite(g, HIGH);
delay(x);
digitalWrite(r, LOW);
digitalWrite(y, LOW);
digitalWrite(g, LOW);
delay(x);
}
