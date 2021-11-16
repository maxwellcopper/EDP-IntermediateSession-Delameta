int r = PA1;
int y = PA2;
int g = PA3;

int x = 1000;
int d = 350;

void setup() {
  // put your setup code here, to run once:
  pinMode(PA1, OUTPUT);
  pinMode(PA2, OUTPUT);
  pinMode(PA3, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PA1, HIGH);
  delay(x);
  digitalWrite(PA1, LOW);
  delay(x);

  digitalWrite(PA2, HIGH);
  delay(d);
  digitalWrite(PA2, LOW);
  delay(d);

  digitalWrite(PA3, HIGH);
  delay(x);
  digitalWrite(PA3, LOW);
  delay(x);

  
  
}
