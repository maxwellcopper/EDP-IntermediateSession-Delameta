int pir = 2;
int buzz = 5;


void setup() {
  // put your setup code here, to run once:
pinMode(2,INPUT);
pinMode(5, OUTPUT);
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int vpir = digitalRead(pir);

  Serial.print("Nilai PIR : ");
  Serial.print(vpir);
  Serial.println();

  if(vpir == 1){
    Serial.println("ada maling");
    /*for(int i = 500; i>20; i-=50){
    digitalWrite(buzz, HIGH);
    delay(i);
    digitalWrite(buzz, LOW);
    delay(i);
    */
    for (int i = 255; i >=0; i--){
      analogWrite(buzz, i);
      delay(50);
    }
  }else {
    Serial.println("G");
    digitalWrite(buzz, LOW);
  }
}
