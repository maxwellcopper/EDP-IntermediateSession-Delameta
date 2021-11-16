int r = PA1;
int y = PA2;
int g = PA3;

int b1 = PB5;
int b2 = PB6;
int b3 = PB7;

int x = 1000;
int d = 350;

void setup() {
  // put your setup code here, to run once:
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int state   = digitalRead(b1);
  int state2  = digitalRead(b2);
  int state3  = digitalRead(b3);
   
  if(state == 1){
    digitalWrite(r, HIGH);
  }else {
    digitalWrite(r, LOW);
  }

  if(state2 == 1){
    digitalWrite(y, HIGH);
  }else {
    digitalWrite(y, LOW);
  }

  if(state3 == 1){
    digitalWrite(g, HIGH);
  }else {
    digitalWrite(g, LOW);
  }
}
