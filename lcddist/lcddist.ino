#include <Ultrasonic.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Ultrasonic ultrasonic(7,8);

void setup() {
lcd.begin(16, 2);
lcd.print("testing...");
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Target Distance");
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(ultrasonic.Ranging(CM));
  lcd.print("cm");
    
  delay(100);
}


