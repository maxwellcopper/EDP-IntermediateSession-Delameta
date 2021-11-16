#include<SPI.h>
#include<MFRC522.h>

//inisialisi variable
#define SS_PIN 10
#define RST_PIN 9

int buzz = 7;
MFRC522 mfrc522(SS_PIN, RST_PIN);

void bener(){
  digitalWrite(buzz, HIGH);
  delay(150);
  digitalWrite(buzz, LOW);
  delay(50);
  digitalWrite(buzz, HIGH);
  delay(150);
  digitalWrite(buzz, LOW);
  delay(50);
}

void salah(){
  digitalWrite(buzz, HIGH);
  delay(300);
  digitalWrite(buzz,LOW);
  delay(50);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SPI.begin();
  mfrc522.PCD_Init();

  pinMode(buzz, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!mfrc522.PICC_IsNewCardPresent()){return;}
  if(!mfrc522.PICC_ReadCardSerial()){return;}

  //Show UID on Serial Monitor
  Serial.print("UID tag :");
  String content = "";
  byte letter;
  for(byte i = 0; i<mfrc522.uid.size; i++){
//    Serial.print(mfrc522.uid.uidByte[i],HEX);
//    content.concat(String(mfrc522.uid.uidByte[i]<0x10?"0"));
//    content.concat(String(mfrc522.uid.uidByte[i],HEX));
 Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : "");
 Serial.print(mfrc522.uid.uidByte[i], HEX);
 content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : ""));
 content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
 Serial.print("Message : ");
 content.toUpperCase();
 if (content.substring(1) == "058D 04AEAB71 00") //Sesuaikan dengan ID kartu anda
 {
 bener();
 Serial.println("Seep valid");
 delay(2000);
 }else if (content.substring(1) == "058F8EBF5DC1 00"){
   bener();
 Serial.println("Seep valid2");
 delay(2000);  
 }
 else{
  salah();
 Serial.println("Kartu Belum Terdaftar!");
 }
 Serial.println("Tempelkan Kartu!");
 delay(500); //Jeda waktu perulagan seama 500 mili detik
}
