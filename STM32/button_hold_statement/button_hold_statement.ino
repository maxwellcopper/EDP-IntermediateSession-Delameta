int r = PA1;
int y = PA2;
int g = PA3;

int b1 = PA4;
int b2 = PA5;
int b3 = PA6;

int x = 1000;
int d = 350;

int state1 = 0;
int oldstate1 = 0;
int led1 = 0;

int state2 = 0;
int oldstate2 = 0;
int led2 = 0;

int state3 = 0;
int oldstate3 = 0;
int led3 = 0;

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
  state1 = digitalRead(b1);
  state2 = digitalRead(b2);
  state3 = digitalRead(b3);

  if(oldstate1 == 0 && state1 == 1){
      if(led1 = 1){
        digitalWrite(r, HIGH);
        led1 = 0;
      }else {
        digitalWrite(r, LOW);
        led1 = 1;
      }
  }
  oldstate1 = state1;
  
}
