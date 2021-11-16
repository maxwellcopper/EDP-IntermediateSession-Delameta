#include <LiquidCrystal_I2C.h>
 
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  Serial.begin(115200);
  lcd.begin();
}

 
void loop()
{
  lcd.clear(); //Menghapus Karakter di LCD
  lcd.setCursor(0,0);
  lcd.print("0123456789012345");
  lcd.setCursor(0,1);
  lcd.print("Nuhuun");
  delay(3000);

  lcd.clear();
  (2000);
  lcd.setCursor(0,0);
  lcd.print("cek ke2");
  lcd.setCursor(0,1);
  lcd.print("baris ke2");
  delay(1000);

}
