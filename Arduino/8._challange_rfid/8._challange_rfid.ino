#include<SPI.h>
#include<MFRC522.h>

//inisialisi variable
#define SS_PIN 10
#define RST_PIN 9

String uidString;
int buzz = 7;
MFRC522 mfrc522(SS_PIN, RST_PIN); //create mfrc522 instance

int ir = 2;
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
  SPI.begin(); //initiate SPI BUS
  mfrc522.PCD_Init();
  pinMode(buzz, OUTPUT);
  Serial.println("Tempelkan Kartu");
  pinMode(ir, INPUT);
  Serial.println("gerbang ketutup");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(mfrc522.PICC_IsNewCardPresent()){
      readRFID();
      Serial.print("ID : ");
      Serial.println(uidString);
      if(uidString== "5-8D-4-AE" || uidString == "5-8F-8E-BF"){ //ktp aing
         bener();
         Serial.println("berhasil1");
         delay(100);
         Serial.println("Masuuuk oii");
         Serial.println("Gerbang Kebuka");
         while(1){
          int state = digitalRead(ir);
          if (state == 1){
            state =1;
          }else {
            Serial.println("Gerbang ketutup");
            break;
          }
         }
      }
      else{
        salah();
        Serial.println("ga terdaftar");
        Serial.println("Gerbang ketutup");
      }
    }

}

  void readRFID(){  
  mfrc522.PICC_ReadCardSerial();
  uidString = String(mfrc522.uid.uidByte[0],HEX) + "-" +
              String(mfrc522.uid.uidByte[1],HEX) + "-" +
              String(mfrc522.uid.uidByte[2],HEX) + "-" +
              String(mfrc522.uid.uidByte[3],HEX);
              uidString.toUpperCase();
  }



   /*
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
}*/
