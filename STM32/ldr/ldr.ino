int ldr = PA1;
int r = PA3;
int y = PA4;
int g = PA5;  

void setup() {
  // put your setup code here, to run once:
  pinMode(r, OUTPUT);
  pinMode(ldr, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly
  int vldr = analogRead(ldr);
  Serial.println(vldr);
  vldr = map(vldr, 4095, 0, 255, 0);
  
  analogWrite(r, vldr);
  analogWrite(y, vldr);
  analogWrite(g, vldr);
}
