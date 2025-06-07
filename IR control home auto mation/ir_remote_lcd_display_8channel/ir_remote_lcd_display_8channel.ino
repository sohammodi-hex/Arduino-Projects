//SL IDEAS
//https://www.youtube.com/channel/UCsa_AZGAnWCcgYGkkGd_r4w/?sub_confirmation=1


#include <EEPROM.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);



#include <IRremote.h>
#define PIN 2
#define Relay1 3
#define Relay2 4
#define Relay3 5
#define Relay4 6
#define Relay5 7
#define Relay6 8
#define Relay7 9
#define Relay8 10
IRrecv irrecv(PIN);
decode_results results;
 
#define remotevalue1 16724175   //code for IR remote button 1 (change this)
#define remotevalue2 16718055   //code for IR remote button 2 (change this)
#define remotevalue3 16743045   //code for IR remote button 3 (change this)
#define remotevalue4 16716015   //code for IR remote button 4 (change this)
#define remotevalue5 16726215   //code for IR remote button 5 (change this)
#define remotevalue6 16734885   //code for IR remote button 6 (change this)
#define remotevalue7 16728765   //code for IR remote button 7 (change this)
#define remotevalue8 16730805   //code for IR remote button 8 (change this)

 
 
 
byte relay1 = 0;
byte relay2 = 0;
byte relay3 = 0;
byte relay4 = 0;
byte relay5 = 0;
byte relay6 = 0;
byte relay7 = 0;
byte relay8 = 0;
long value;
 
void setup() {

  lcd.init();
  lcd.print("LIGHTED BULBS..");

  
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  pinMode(Relay5, OUTPUT);
  pinMode(Relay6, OUTPUT);
  pinMode(Relay7, OUTPUT);
  pinMode(Relay8, OUTPUT);
 
  for (int a = 3; a <= 10; a++ ) {
    digitalWrite(a, HIGH);
  }
 
}
 
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    value = (results.value);
    irrecv.resume();
  }
  delay(400);
 
  if (value == remotevalue1  && relay1 == 0 ) {
    digitalWrite(Relay1, LOW);
    relay1 = 1;
    value = 0;

    lcd.setCursor(0, 1); 
    lcd.print("1,");
    
  } else if (value == remotevalue1 && relay1 == 1 ) {
    digitalWrite(Relay1, HIGH);
    relay1 = 0;
    value = 0;
    
    lcd.setCursor(0, 1); 
    lcd.print("  ");
    
  }
 if (value == remotevalue2 && relay2 == 0 ) {
    digitalWrite(Relay2, LOW);
    relay2 = 1;
    value = 0;

    lcd.setCursor(2, 1); 
    lcd.print("2,");
  
  } else if (value == remotevalue2 && relay2 == 1 ) {
    digitalWrite(Relay2, HIGH);
    relay2 = 0;
    value = 0;

    lcd.setCursor(2, 1); 
    lcd.print("  ");
 
  }
 if (value == remotevalue3 && relay3 == 0 ) {
    digitalWrite(Relay3, LOW);
    relay3 = 1;
    value = 0;

    lcd.setCursor(4, 1); 
    lcd.print("3,");
    
  } else if (value == remotevalue3 && relay3 == 1 ) {
    digitalWrite(Relay3, HIGH);
    relay3 = 0;
    value = 0;

    lcd.setCursor(4, 1); 
    lcd.print("  ");
  }
 if (value == remotevalue4 && relay4 == 0 ) {
    digitalWrite(Relay4, LOW);
    relay4 = 1;
    value = 0;

    lcd.setCursor(6, 1); 
    lcd.print("4,");
    
  } else if (value == remotevalue4 && relay4 == 1 ) {
    digitalWrite(Relay4, HIGH);
    relay4 = 0;
    value = 0;

   
    lcd.setCursor(6, 1); 
    lcd.print("  "); 
  }
 if (value == remotevalue5 && relay5 == 0 ) {
    digitalWrite(Relay5, LOW);
    relay5 = 1;
    value = 0;

    lcd.setCursor(8, 1); 
    lcd.print("5,");
    
  } else if (value == remotevalue5 && relay5 == 1 ) {
    digitalWrite(Relay5, HIGH);
    relay5 = 0;
    value = 0;

   lcd.setCursor(8, 1); 
   lcd.print("  ");
    
  }
 if (value == remotevalue6 && relay6 == 0 ) {
    digitalWrite(Relay6, LOW);
    relay6 = 1;
    value = 0;

    lcd.setCursor(10, 1); 
    lcd.print("6,");
    
  } else if (value == remotevalue6 && relay6 == 1 ) {
    digitalWrite(Relay6, HIGH);
    relay6 = 0;
    value = 0;

    lcd.setCursor(10, 1); 
    lcd.print("  ");
    
  }
 
  if (value == remotevalue7 && relay7 == 0 ) {
    digitalWrite(Relay7, LOW);
    relay7 = 1;
    value = 0;

    lcd.setCursor(12, 1); 
    lcd.print("7,");
    
  } else if (value == remotevalue7 && relay7 == 1 ) {
    digitalWrite(Relay7, HIGH);
    relay7 = 0;
    value = 0;

    lcd.setCursor(12, 1); 
    lcd.print("  ");
    
  }
  if (value == remotevalue8 && relay8 == 0 ) {
    digitalWrite(Relay8, LOW);
    relay8 = 1;
    value = 0;

    lcd.setCursor(14, 1); 
    lcd.print("8,");
    
  } else if (value == remotevalue8 && relay8 == 1 ) {
    digitalWrite(Relay8, HIGH);
    relay8 = 0;
    value = 0;

    lcd.setCursor(14, 1); 
    lcd.print("  ");  
  }
}
