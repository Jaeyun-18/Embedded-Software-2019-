#include <Time.h>
#include <TimeLib.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

char CLASS1[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
char CLASS2[19]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,19,20};
char CLASS3[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

int sw1=9;
int sw2=10;
int sw3=11;
int read1,read2,read3;
int ho, mi, se, da, mo, ye;
long time=0;
long debounce = 2;

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(sw1, INPUT_PULLUP);
  pinMode(sw2, INPUT_PULLUP);
  pinMode(sw3, INPUT_PULLUP);
  ho=18;
  mi=0;
  se=0;
  da=22;
  mo=11;
  ye=19;
  setTime(ho,mi,se,da,mo,ye); //시 분 초 일 월 년
}

void loop()
{
  read1=digitalRead(sw1);
  read2=digitalRead(sw2);
  read3=digitalRead(sw3);
  if(millis()-time > debounce)
  {
    if(read1 == HIGH && read2 == HIGH && read3 == HIGH) {
      lcd.init();
      lcd.setCursor(0,0);
      digitalClockDisplay();
      lcd.setCursor(0,1);
      lcd.print("  PRESS BUTTON  ");
    }
    
    else if(read1 == LOW && read2 == HIGH && read3 == HIGH) {
      lcd.init();
      lcd.setCursor(0,0); 
      lcd.print("     TOILET     ");
      lcd.setCursor(0,1);
      lcd.print("   Good Time!   ");
      Serial.print(hour());
      if(minute()<10)
      {
        Serial.print('0');
        Serial.print(minute());
      }
      else Serial.print(minute());
      Serial.println(0);
      delay(2000);
    }
    
    else if(read1 == HIGH && read2 == LOW && read3 == HIGH) {
      lcd.init();
      lcd.setCursor(0,0);
      lcd.print("     WATER     ");
      lcd.setCursor(0,1);
      Serial.print(hour());
      if(minute()<10)
      {
        Serial.print('0');
        Serial.print(minute());
      }
      else Serial.print(minute());
      Serial.println(1);
      delay(2000);
    }
    
    else if(read1 == HIGH && read2 == HIGH && read3 == LOW) {
      lcd.init();
      lcd.setCursor(0,0);
      lcd.print("    SANGDAM    ");
      lcd.setCursor(0,1);
      lcd.print(" God bless you! ");
      Serial.print(hour());
      if(minute()<10)
      {
        Serial.print('0');
        Serial.print(minute());
      }
      else Serial.print(minute());
      Serial.println(2);
      delay(2000);
    }
  } 
}

 void digitalClockDisplay(){
  lcd.print("  ");
  printDigits(month());
  lcd.print(".");
  printDigits(day());
  lcd.print("  ");
  printDigits(hour());
  lcd.print(":");
  printDigits(minute());
  lcd.print("   ");
}

void printDigits(int digits){
  if (digits < 10)
     lcd.print('0');
  lcd.print(digits);
}
