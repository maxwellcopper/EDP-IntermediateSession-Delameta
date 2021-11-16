//led1 n led2 dinyalakan satu tombol (button1)

//inisialisasi button
int butt = 2;
int butt2 = 3;
int butt3 = 4;

//inisialisasi led
int r = 5;
int y = 6;
int g = 7;

void setup() {
  // serial setup
  Serial.begin(9600);

  //led as output
  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);

  //button as input
  pinMode(butt, INPUT);
  pinMode(butt2, INPUT);
  pinMode(butt3, INPUT);
}

void loop() {
  // pembacaan button
  int kondisi = digitalRead(butt);
  int kondisi2 = digitalRead(butt2);
  int kondisi3 = digitalRead(butt3);

  //serial monitor
  Serial.println("kondisi button1 : " + String(kondisi));
  Serial.println("kondisi button2 : " + String(kondisi2));
  Serial.println("kondisi button3 : " + String(kondisi3));
  Serial.println();

  //logika 1 button, 2 LED on 
  if(kondisi == 1){
    digitalWrite(r, HIGH); //merah laa boii
    digitalWrite(y, HIGH);
  }else {
    digitalWrite(r, LOW); //merah laa boii
    digitalWrite(y, LOW); //merah laa boii
  }
  
  delay(100);

}
