#include <HX711_ADC.h> // [https://github.com/olkal/HX711_ADC](https://github.com/olkal/HX711_ADC)
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h> 

#define ir1 7
#define ir2 6
#define ir3 5

int smallfruit = 0;
int bigfruit = 0;
int readir1;
int readir2;
int readir3;
float i;
LiquidCrystal_I2C lcd(0x27,16,2);  //Change the HEX address

HX711_ADC LoadCell(3, 2);

Servo myservo1;
Servo myservo2;

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
Wire.begin();
lcd.init();
lcd.backlight();
LoadCell.begin(); // start connection to HX711
LoadCell.start(1000); // load cells gets 1000ms of time to stabilize 
LoadCell.setCalFactor(500);
myservo1.attach(8);
myservo2.attach(9);
myservo1.write(100);
myservo2.write(40);
pinMode(ir1 , INPUT);
pinMode(ir2 , INPUT);
pinMode(ir3 , INPUT);
lcd.setCursor (0,0);
lcd.print("     Fruit      ");
lcd.setCursor (0,1);
lcd.print("    Sorting    ");
delay(1500);
lcd.clear();
lcd.setCursor (0,0);
lcd.print("Small");
lcd.setCursor (12,0);
lcd.print("Big");
lcd.setCursor (7,0);
lcd.print("Wt");
}

void loop() {
  // put your main code here, to run repeatedly:
LoadCell.update(); // retrieves data from the load cell
i = LoadCell.getData();
lcd.setCursor (2,1);
lcd.print(smallfruit);
lcd.setCursor (13,1);
lcd.print(bigfruit);
lcd.setCursor (6,1);
lcd.print(i);
 readir1 = digitalRead(ir1);
 readir2 = digitalRead(ir2);
 readir3 = digitalRead(ir3);
Serial.print(i);
if(readir3 == 0)
{
for(int a =0; a<10;a++)
{
  LoadCell.update(); // retrieves data from the load cell
i = LoadCell.getData();
delay(150);
}
}
//Serial.print(readir2);
 if(i > 100)
{
  myservo1.write(0);
  delay(1500);
  myservo1.write(150);
}
 if(i < 50 && i > 40)
  {
  myservo2.write(170);
  delay(1500);
  myservo2.write(40);
  }
if(readir1 == 0)
{
    Serial.print("Small ");
    Serial.println(smallfruit);
    Serial.print(" ");
    smallfruit = smallfruit + 1;  
}
 if (readir2 == 0)
{
  bigfruit = bigfruit + 1;
  Serial.print("big ");
  Serial.println(bigfruit);
  Serial.print(" ");
}
delay(50);

} 
