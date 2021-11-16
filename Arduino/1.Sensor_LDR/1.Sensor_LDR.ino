int ldr = A1;
int buzz = 5;
int r = 9;
int y = 10;
int g = 11;


void setup() {
  // put your setup code here, to run once:
pinMode(5, OUTPUT);
Serial.begin(9600);

pinMode(r, OUTPUT);
pinMode(y, OUTPUT);
pinMode(g, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int vldr = analogRead(ldr);
  vldr = map(vldr,0,1024,0,255);
  Serial.print("Nilai LDR : ");
  Serial.print(vldr);
  Serial.println();

  analogWrite(r, vldr);
  analogWrite(y, vldr);
  analogWrite(g, vldr);

}
