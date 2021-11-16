int ldr = PA1;
int ir = PA2;
int r = PA3;
int y = PA4;
int g = PA5;

int vir = 0;
int key = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ldr, INPUT);
  pinMode(ir, INPUT);

  pinMode(r, OUTPUT);
  pinMode(y, OUTPUT);
  pinMode(g, OUTPUT);

  digitalWrite(r, HIGH);
  digitalWrite(y, HIGH);
  digitalWrite(g, HIGH); 
  delay(1000000);

}

int convert(int x){
  if (x == 1){
    x = 0;
  }else {
    x = 1;
  }
  return x;
}

void loop() {
  // put your main code here, to run repeatedly:
  
  vir = digitalRead(ir);
  vir = convert(vir);

  Serial.print("ir = ");
  Serial.print(vir);

  
  if(vir == 1 && key == 0){
    delay(500);
    while(1){
    vir = digitalRead(ir);
    vir = convert(vir);
    int vldr = analogRead(ldr);
    vldr = map(vldr, 0, 4095, 255, 0);
    
    Serial.print("  ldr =  ");
    Serial.println(vldr);
    
    if(vldr >= 0 && vldr <=100){
      digitalWrite(r, HIGH);
      digitalWrite(y, LOW);
      digitalWrite(g, LOW);
    }
    else if(vldr>100 && vldr <=200){
      digitalWrite(y, HIGH);
      digitalWrite(r, LOW);
      digitalWrite(g, LOW);
    }
    else if(vldr>200){
      digitalWrite(r, LOW);
      digitalWrite(y, LOW);
      digitalWrite(g, HIGH);
    }
    
    if(vir == 1){
        break;
      }
    else {
        continue;
      }
   }
    key = 1;
 } 
  if (vir == 1 && key == 1){
    delay(500);
    digitalWrite(r, LOW);
    digitalWrite(y, LOW);
    digitalWrite(g, LOW);
    key = 0; 
  }

  
}
