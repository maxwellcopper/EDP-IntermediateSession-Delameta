int ir = PA1;
int ledr = PA2;
int ledy = PA3;
int ledg = PA4;

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
  pinMode(ir, INPUT);
  pinMode(ledr, OUTPUT);
  pinMode(ledy, OUTPUT);
  pinMode(ledg, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int vir = digitalRead(ir);
  vir = convert(vir);
  Serial.print("kondisi ir : ");
  Serial.println(vir);

  if(vir == 1){
    digitalWrite(ledr, HIGH);
  }else {
    digitalWrite(ledr, LOW);
  }
}
