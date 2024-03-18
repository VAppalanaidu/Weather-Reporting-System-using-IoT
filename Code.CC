#include <LiquidCrystal.h> 
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() 
{ 
  lcd.begin(16,2); 
  lcd.setCursor(4,0); 
  lcd.print("Monitoring"); 
  lcd.setCursor(7,1); 
  lcd.print("System"); 
  delay(2000); 
}
void loop() 
{ 
 lcd.clear(); 
 float Voltage=analogRead(A0)*0.004882814; 
 float degrees = ( Voltage - 0.5 ) * 100; 
 lcd.setCursor(3,0); 
 lcd.print("Temp:"); 
 lcd.setCursor(8,0); 
 lcd.print(degrees); 
  if (degrees<10) 
  {
    lcd.setCursor(4,1); 
    lcd.print("-TOO COLD"); 
  }
  else if(degrees<18 &&degrees>10 ) 
  {
    lcd.setCursor(4,1); 
    lcd.print("-COLD"); 
  }
  else if(degrees<30 &&degrees>18 ) 
  {
    lcd.setCursor(4,1); 
    lcd.print("-Normal Temp"); 
  }
  else if(degrees<45 &&degrees>30 ) 
  {
    lcd.setCursor(4,1); 
    lcd.print("-Hot"); 
  }
  else if(degrees>45 ) 
  {
    lcd.setCursor(4,1); 
    lcd.print("-TOO HOT"); 
  }
  
  delay(2000); 
  lcd.clear(); 
  
  int ldr=analogRead(A1); 
  
  lcd.setCursor(1,0); 
  lcd.print("Intensity:"); 
  lcd.setCursor(12,0); 
  lcd.print(ldr); 
  if (ldr<230) 
  {
     lcd.setCursor(4,1); 
     lcd.print("-TOO BRIGHT"); 
  }
    else if (ldr<460 && ldr>230 ) 
  {
     lcd.setCursor(2,1); 
     lcd.print("-Medium Light"); 
  }
  
  else if (ldr>460) 
  {
     lcd.setCursor(4,1); 
     lcd.print("-TOO DARK"); 
  }
  
  delay(2000); 
  lcd.clear(); 
}

