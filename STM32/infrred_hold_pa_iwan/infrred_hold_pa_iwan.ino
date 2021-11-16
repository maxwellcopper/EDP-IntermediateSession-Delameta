int r = PA2;
int y = PA3;
int g = PA4;

int ir = PA1;

int state1 = 0;
int oldstate1 = 0;

int convert(int x){
  if(x == 1){
    x = 0;
  }else {
    x = 1;
  }
  return x;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(ir, INPUT);  
}

void loop() {
  // put your main code here, to run repeatedly:
  state1 = digitalRead(ir);
  state1 = convert(state1);
  Serial.print("kondisi ir : ");
  Serial.println(state1);
  
  if(oldstate1 == 0 && state1 == 1){
        delay(500);
        digitalWrite(r, HIGH);
        oldstate1=1;
   }else if(oldstate1 == 1 && state1 == 1){
        delay(500);
        digitalWrite(r, LOW);
        oldstate1=0;
   }

}
   
