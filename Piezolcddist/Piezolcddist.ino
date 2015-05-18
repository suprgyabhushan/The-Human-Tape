#include "Ultrasonic.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Ultrasonic ultrasonic(7,8);
// variables to take x number of readings and then average them
const int sensorPin=0;
const int numOfReadings = 1; // number of readings to take/ items in the array
const int ledPin=13;
const int threshold=5;
int index;
long distance;
long readings[numOfReadings]; // stores the distance readings in an array
int arrayIndex = 0; // arrayIndex of the current item in the array
long total = 1; // stores the cumlative total
long averageDistance = 0; // stores the average value
long volume;
long total1=1;


void setup()
{
  lcd.begin(16, 2);
  // create array loop to iterate over every item in the array
  
pinMode(ledPin,OUTPUT);
}

void loop()
{
  for (index = 0; index <= numOfReadings; index++)
  {
  readings[index] = 0;
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   THE HUMAN TAPE ");
  distance=ultrasonic.Ranging(CM);
  int var2;//for array traversal
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print("cm");
  int val=analogRead(sensorPin);
  if(val>threshold)
  {
  while(arrayIndex <= numOfReadings)
  {
    distance=ultrasonic.Ranging(CM);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print("cm");
    readings[arrayIndex] = distance; // add distance reading to array
    //total= total * readings[arrayIndex]; // add the reading to the total
    arrayIndex = arrayIndex + 1; // go to the next item in the array
    // At the end of the array (3 items) then start again
    //if (arrayIndex > numOfReadings) {
    //arrayIndex = 0;
    //digitalWrite(ledPin,LOW);
    //delay(000);
    delay(500);
    digitalWrite(ledPin,HIGH);
    delay(500);
    digitalWrite(ledPin,LOW);
    lcd.setCursor(0,1);
    lcd.print("To exit press");
    val=0;
    delay(2000);
    val=analogRead(sensorPin);
    if(val>threshold)//2D if loop starting
    {
      lcd.clear();
      lcd.print("YAHOO");
      for(var2=arrayIndex;var2<=numOfReadings;var2++)
      {
        readings[var2]=0;
      }
      break;
    }
    
  }
  delay(2000);
  int var;
  int radius;
  int count=0;
  
  for(var=0;var<=1;var++)
  {
    if(readings[var]!=0)
    {
      count=count+1;
    }
  }
  
  if(count==2)
  {
    total=readings[0]*readings[1];
    if(readings[0]==readings[1])
    {
      lcd.clear();  
      lcd.setCursor(0,0);
      lcd.print("SQuare");
      lcd.setCursor(0,1);
      lcd.print("Area:");
      lcd.print(total);
      lcd.print(" cm^2");
    }
    else
    {
      lcd.clear(); 
      lcd.setCursor(0,0);
      lcd.print("Rectangle");
      lcd.setCursor(0,1);
      lcd.print("Area:");
      lcd.print(total);
      lcd.print(" cm^2");
    }
  }  
  if(count==1)
  {
    radius = readings[0]/2;
    total=(22*radius*radius)/7;
    lcd.clear();  
    lcd.setCursor(0,0);
    lcd.print("Circle");
    lcd.setCursor(0,1);
    lcd.print("Area:");
    lcd.print(total);
    lcd.print(" cm^2");
  }
  delay(5000);
  arrayIndex=0; 
  total=1;
  total1=1;
  volume=1;
  }
  delay(1000);
  val=0;
}




  //volume=readings[0]*readings[1]*readings[2];
  
 // delay(5000);
  
 // lcd.setCursor(0,1);
  //lcd.print("Volume:");
  //lcd.print(volume);
  //lcd.print("cm^3");
  
//averageDistance = total / numOfReadings; // calculate the average distance
// if the distance is less than 255cm then change the brightness of the LED
//if (averageDistance < 255) {
//redLEDValue = 255 - averageDistance; // this means the smaller the distance the
//brighterthe LED.
//}
//analogWrite(redLEDPin, redLEDValue); // Write current value to LED pins
//Serial.println(readings[0], DEC);
//Serial.println(readings[1], DEC);
//Serial.println(readings[2], DEC);
//Serial.println(averageDistance, DEC); // print out the average distance to the
//debugger
//delay(10000); // wait 10 seconds before looping
//again*/
  /*total1=2*(readings[0]*readings[1]+readings[1]*readings[2]+readings[2]*readings[0]);
    volume=readings[0]*readings[1]*readings[2];
    delay(100);
    lcd.clear();
    if((readings[0]==readings[1])&&(readings[1]==readings[2])&&(readings[0]==readings[2]))
    {
  
  
    lcd.setCursor(0,0);
    lcd.print("Its Cube");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("TSA:");
    lcd.print(total1);
    lcd.print(" cm^2 ");
    lcd.setCursor(0,1);
    lcd.print("Volume:");
    lcd.print(volume);
    lcd.print(" cm^3");
    }
    else
    {
    lcd.setCursor(0,0);
    lcd.print("Its Cuboid" );
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("TSA:");
    lcd.print(total1);
    lcd.print(" cm^2");
    lcd.setCursor(0,1);
    lcd.print("Volume:");
    lcd.print(volume);
    lcd.print(" cm^3");
    }*/


  
  
  
  






