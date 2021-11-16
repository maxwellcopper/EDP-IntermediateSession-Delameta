int ir = PA1;
int ledr = PA2;
int ledy = PA3;
int ledg = PA4;

int nstate = 0;
int lstate = 0;
int ledstate = 0;



void setup() {
  // put your setup code here, to run once:
  pinMode(ir, INPUT);
  pinMode(ledr, OUTPUT);
  pinMode(ledy, OUTPUT);
  pinMode(ledg, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int vir = digitalRead(ir);
  Serial.print("kondisi ir : ");
  Serial.println(vir);

  if(nstate == 0 && lstate == 1){
    if(ledstate == 0){
      digitalWrite(ledr, HIGH);
      ledstate = 1;
    }else {
      digitalWrite(ledr, LOW);
      ledstate = 0;
    }
  }
  lstate = nstate;
}
