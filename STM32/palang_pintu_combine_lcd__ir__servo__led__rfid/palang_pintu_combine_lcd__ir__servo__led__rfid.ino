#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <LiquidCrystal_I2C.h>

//rfid 
#define SS_PIN PB1
#define RST_PIN PB0
String id;
MFRC522 reader(SS_PIN, RST_PIN);


//LCD 
LiquidCrystal_I2C lcd(0x27, 16, 2); 

//ir 
int ir = PA1;

//LED 
int r = PA11;
int y = PA12;
int g = PA15;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SPI.begin();
  reader.PCD_Init();

  lcd.begin();

  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tempelkan kartu");

}



void loop() {
  // put your main code here, to run repeatedly:
  
  if(reader.PICC_IsNewCardPresent()){
    readRFID();
    delay(500);
    if(id == "6A-A7-D5-80"){
      Serial.println(id);
      opengate();
    }
    else if (id == "4A-51-6E-AE"){
      Serial.println(id);
      opengate();
    }
    else {
      Serial.println(id);
      closegate();
    }
  }

}

void opengate(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Berhasil!");
  delay(200);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Gerbang Terbuka");
  lcd.setCursor(0,1);
  lcd.print("Silahkan Masuk");

  while(1){
    int vir = digitalRead(ir);
    vir = !vir;
    if(vir == 1){
      delay(200);

      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Gerbang Tertutup");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Tempelkan Kartu");

      break;
    }else {
      continue;
    }
  }
}

void closegate(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Kartu Tidak Terdaftar");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Gerbang Tertutup");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Tempelkan Kartu!");
}

void readRFID(){
  reader.PICC_ReadCardSerial();
  id = String(reader.uid.uidByte[0], HEX) + "-" +
       String(reader.uid.uidByte[1], HEX) + "-" +
       String(reader.uid.uidByte[2], HEX) + "-" +
       String(reader.uid.uidByte[3], HEX);
       id.toUpperCase(); 
}
