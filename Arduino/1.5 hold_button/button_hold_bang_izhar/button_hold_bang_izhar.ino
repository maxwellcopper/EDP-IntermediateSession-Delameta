// Inisialisasi
int tombol1=2;
int tombol2=3;
int tombol3=4;
int R=5;
int Y=6;
int G=7;
int status = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(tombol1,INPUT);
  pinMode(tombol2,INPUT);
  pinMode(tombol3,INPUT);
  pinMode(R,OUTPUT);
  pinMode(Y,OUTPUT);
  pinMode(G,OUTPUT);
}

void loop() {
  if(digitalRead(tombol1)== HIGH){
    status = !status;
    digitalWrite(R, status);
  } while(digitalRead(tombol1) ==HIGH);
  delay(50);

   if(digitalRead(tombol2)== HIGH){
    status = !status;
    digitalWrite(Y, status);
  } while(digitalRead(tombol2) ==HIGH);
  delay(50);

   if(digitalRead(tombol3)== HIGH){
    status = !status;
    digitalWrite(G, status);
  } while(digitalRead(tombol3) ==HIGH);
  delay(50);
}
