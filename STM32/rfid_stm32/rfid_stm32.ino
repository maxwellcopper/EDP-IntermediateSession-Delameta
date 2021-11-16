/*/
 * A9  to RX USBTTL
 * A10 to TX USBTTL
 * PB0 to RESET
 * PB1 to SDA / SS
 * PA5 to CLK
 * PA6 to MISO
 * PA7 to MOSI
 * Tekan Reset sebelum Upload
 * Pilih Board    :fake STM32F10 
 * Upload methode :Serial
 */

/* RFID dengan SMT32
 *  reader detek kartu yg terdaftar 
 lampu akan ijo 
 *  jika ga terdaftar lampu akan merah 
 *  Transisi tiap dari terdaftar ke
 tidak terdaftar akan menyalakan kuning
 lalu mematikannya, 
 *  tapi jika kondisi
 terdaftar atau tidak terdaftar lebih 
 dari 1kali maka tidak ada transisi 
 lampu kuning 
 */
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN PB1 //SDA 
#define RST_PIN PB0 //Reset

String id;

MFRC522 reader(SS_PIN, RST_PIN);

//led display 
int r = PB5;
int y = PB6;
int g = PB7;

bool green = false;
bool red = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  SPI.begin();
  reader.PCD_Init();
  Serial.println("Tempelkan Kartu");

  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);

  digitalWrite(r, LOW);
  digitalWrite(y, LOW);
  digitalWrite(g, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
    if(reader.PICC_IsNewCardPresent()){
      readRFID();
      delay(500);
      if(id == "6A-A7-D5-80"){
        green = true;
        Serial.print("ID : ");
        Serial.println(id);
        Registered();
      }
      else if (id == "4A-51-6E-AE"){
        green = true;
        Serial.print("ID : ");
        Serial.println(id);
        Registered();
      }
      else {
        red = true;
        Serial.print("ID : ");
        Serial.println(id);
        NotRegistered();
      }
    }
}

void readRFID(){
  reader.PICC_ReadCardSerial();
  id = String(reader.uid.uidByte[0], HEX) + "-" +
       String(reader.uid.uidByte[1], HEX) + "-" +
       String(reader.uid.uidByte[2], HEX) + "-" +
       String(reader.uid.uidByte[3], HEX);
       id.toUpperCase(); 
}

void Registered(){
  if(green && red == false){
    digitalWrite(r, LOW);
    digitalWrite(y, LOW);
    digitalWrite(g, HIGH);
  }else if(green && red){
    digitalWrite(r, LOW);
    digitalWrite(y, HIGH);
    delay(250);
    digitalWrite(y, LOW);
    digitalWrite(g, HIGH);
    red = 0;
  }
  Serial.println("Kartu  Terdaftar");
  Serial.println();
}

void NotRegistered(){
    if(green == false && red){
    digitalWrite(r, HIGH);
    digitalWrite(y, LOW);
    digitalWrite(g, LOW);
  }else if(green && red){
    digitalWrite(g, LOW);
    digitalWrite(y, HIGH);
    delay(250);
    digitalWrite(y, LOW);
    digitalWrite(r, HIGH);
    green = 0;
  }

  Serial.println("Kartu Tidak Terdaftar");
  Serial.println();
}
