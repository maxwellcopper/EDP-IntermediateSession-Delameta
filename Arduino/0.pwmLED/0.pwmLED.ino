int r = 3;
int y = 5;
int g = 6;
int x = 500;
void setup() {
  // put your setup code here, to run once:
  for (int i=2; i<=6; i++){
    pinMode(i, OUTPUT);
  }
  
  /*pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);
  */

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
/* dimmer bareng2 satu waktu
  for (int i=0; i<=255; i++){
    analogWrite(3, i);
    analogWrite(5, i);
    analogWrite(6, i);
    delay(20);
  }
  for(int y=255; y>=0; y--){
    analogWrite(3, y);
    analogWrite(5, y);
    analogWrite(6, y);
    delay(20);    
  }
*/ 

//nge dimmer gantoam2 boii
  for(int l=3; l<=6; l++){
    if(l == 4){
      l++;
    }
   for (int i=0; i<=255; i++){
    analogWrite(l, i);
    //float volt = map(i,0,255,0,5);
    float volt =(5.0/255);
    float ukuran = volt*i;
    Serial.println("tegangan : " + String(ukuran) + " v");
    delay(20);
  }
  for(int i=255; i>=0; i--){
    analogWrite(l, i);
    float volt =(5.0/255);
    float ukuran = volt*i;
    Serial.println("tegangan : " + String(ukuran) + " v");
    delay(20);    
  } 
  }



  
}
