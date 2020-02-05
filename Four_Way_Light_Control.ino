/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/
// include the library code:
#include <LiquidCrystal.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F, 16, 2);

bool flag=0;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd1(12, 11, 5, 4, 3, 2);

void led(int a,int b,int c)
{
  digitalWrite(10,a);
  digitalWrite(9,b);
  digitalWrite(8,c);
}

void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd1.begin(16, 2);
  lcd.begin();
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.print("Hello, world!");
}

void printstat()
{
  lcd1.setCursor(0,0);
  lcd.setCursor(0,0);
  digitalWrite(10,HIGH);
  if(flag)
  {
      lcd1.clear();
      lcd1.print("Please Wait...");
      lcd.clear();
      lcd.print("Go...");
      led(1,0,0);
  }
  else
  {
      lcd1.clear();
      lcd1.print("Go...");
      lcd.clear();
      lcd.print("Please Wait...");
      led(0,0,1);
  }
}


void countdown(int x)
{
  if(x<10)
  {
    led(0,1,0);
  }
  lcd1.setCursor(0,1);          
  lcd1.print(x);
  lcd.setCursor(0,1);          
  lcd.print(x);
}

void loop() 
{
  int x;
  printstat();
  x=30;
  while(x--)
  {
    countdown(x);
    delay(1000); 
  }
  flag=!flag;
}

