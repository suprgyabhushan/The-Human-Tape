#include "Ultrasonic.h"
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Ultrasonic ultrasonic(7,8);
// variables to take x number of readings and then average them
const int sensorPin=1;
const int sensorPin1=2;
const int numOfReadings = 2; // number of readings to take/ items in the array
const int numOfReadings1 = 1;
const int ledPin=13;
const int threshold=10;
int index;
long distance;
long readings[numOfReadings]; // stores the distance readings in an array
long readings1[numOfReadings1];
int arrayIndex = 0; // arrayIndex of the current item in the array
long total = 1; // stores the cumlative total
long averageDistance = 0; // stores the average value
long volume;
long total1=1;


void setup()
{
  lcd.begin(20, 4);
  // create array loop to iterate over every item in the array
  //Serial.begin(9600);
pinMode(ledPin,OUTPUT);
}

void loop()
{
  for (index = 0; index <= numOfReadings; index++)
  {
  readings[index] = 0;
  }
  int var;
  int radius;
  int count=0;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("   THE HUMAN TAPE ");
  distance=ultrasonic.Ranging(CM);
  int var2;//for array traversal
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distance);
  //Serial.println(distance);
  lcd.print("cm");
 
  int val=analogRead(sensorPin);
  if(val>threshold)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Taking Distance :");
    delay(2000);
  while(arrayIndex <= numOfReadings)
  {
    distance=ultrasonic.Ranging(CM);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
    //Serial.println(distance);
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
    if(arrayIndex<=numOfReadings)
    {
    lcd.setCursor(0,1);
    lcd.print("To exit press");
    delay(1000);
    val=0;
    val=analogRead(sensorPin);
    delay(2000);

    if(val>threshold)//3D if loop starting
    {
      lcd.clear();
      lcd.print("Shape and Dimensions :");
      for(var2=arrayIndex;var2<=numOfReadings;var2++)
      {
        readings[var2]=0;
      }
      break;
    }
    }
    delay(2000);
    
  }
  delay(2000);
 
  

  
  for(var=0;var<=numOfReadings;var++)
  {
    if(readings[var]!=0)
    {
      count=count+1;
    }
  }
  
  if(count==3)
  {
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Shape & Dimensions :");
  delay(2000);
    total1=2*(readings[0]*readings[1]+readings[1]*readings[2]+readings[2]*readings[0]);
    volume=readings[0]*readings[1]*readings[2];
    delay(100);
    lcd.clear();
    if((readings[0]==readings[1])&&(readings[1]==readings[2])&&(readings[0]==readings[2]))
    {  
    lcd.setCursor(0,0);
    lcd.print("Its Cube");
    
    lcd.setCursor(0,1);
    lcd.print("TSA:");
    lcd.print(total1);
    lcd.print(" cm^2 ");
    lcd.setCursor(0,2);
    lcd.print("Volume:");
    lcd.print(volume);
    lcd.print(" cm^3");
    }
    else
    {
    lcd.setCursor(0,0);
    lcd.print("Its Cuboid" );
    
    lcd.setCursor(0,1);
    lcd.print("TSA:");
    lcd.print(total1);
    lcd.print(" cm^2");
    lcd.setCursor(0,2);
    lcd.print("Volume:");
    lcd.print(volume);
    lcd.print(" cm^3");
    }
  }
   if(count==2)
  {
    radius = readings[0]/2;
    total1=2*(22/7)*(radius)*(radius+readings[1]);
    volume=(22/7)*(radius^2)*(readings[1]);
    lcd.clear();  
    lcd.setCursor(0,0);
    lcd.print("Cylinder");    
    lcd.setCursor(0,1);
    lcd.print("TSA:");
    lcd.print(total1);
    lcd.print(" cm^2");
    lcd.setCursor(0,2);
    lcd.print("Volume:");
    lcd.print(volume);
    lcd.print("cm^3");
      
  }
 
   if(count==1)
  {
    radius= readings[0]/2;
    total1=4*(22/7)*(radius^2);
    volume=(4/3)*(22/7)*(radius^3);
    lcd.clear();  
    lcd.setCursor(0,0);
    lcd.print("Sphere");
    
    lcd.setCursor(0,1);
    lcd.print("TSA:");
    lcd.print(total1);
    lcd.print(" cm^2");
    lcd.setCursor(0,2);
    lcd.print("Volume:");
    lcd.print(volume);
    lcd.print("cm^3");
      
  }
  delay(5000);
  
  }
  delay(1000);
  

int val1=analogRead(sensorPin1);
  if(val1>threshold)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Taking Distance :");

    delay(2000);
  while(arrayIndex <= numOfReadings1)
  {
    distance=ultrasonic.Ranging(CM);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distance);
    //Serial.println(distance);
    lcd.print("cm");
    readings1[arrayIndex] = distance; // add distance reading to array
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
    if(arrayIndex<=numOfReadings1)
    {
    lcd.setCursor(0,1);
    lcd.print("To exit press");
    delay(1000);
    val1=0;
    val1=analogRead(sensorPin1);
    delay(2000);
    
    if(val1>threshold)//2D if loop starting
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Shape & Dimensions :");
      for(var2=arrayIndex;var2<=numOfReadings1;var2++)
      {
        readings1[var2]=0;
      }
      break;
    }
    
    }
    delay(2000);
  }
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Shape & Dimensions :");
  delay(2000);
  
  
  for(var=0;var<=1;var++)
  {
    if(readings1[var]!=0)
    {
      count=count+1;
    }
  }
  
  if(count==2)
  {
    total=readings1[0]*readings1[1];
    if(readings1[0]==readings1[1])
    {
      lcd.clear();  
      lcd.setCursor(0,0);
      lcd.print("SQuare");
      lcd.setCursor(0,1);
      lcd.print("Length:");
      lcd.print(readings1[0]);
      lcd.print(" cm");
      lcd.setCursor(0,2);
      lcd.print("Breadth:");
      lcd.print(readings1[1]);
      lcd.print(" cm");
      lcd.setCursor(0,3);
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
      lcd.print("Length:");
      lcd.print(readings1[0]);
      lcd.print(" cm");
      lcd.setCursor(0,2);
      lcd.print("Breadth:");
      lcd.print(readings1[1]);
      lcd.print(" cm");
      lcd.setCursor(0,3);
      lcd.print("Area:");
      lcd.print(total);
      lcd.print(" cm^2");
    }
  }  
  if(count==1)
  {
    radius = readings1[0]/2;
    total=(22*radius*radius)/7;
    lcd.clear();  
    lcd.setCursor(0,0);
    lcd.print("Circle");
    lcd.setCursor(0,1);
    lcd.print("Radius:");
    lcd.print(radius);
    lcd.print(" cm");
    lcd.setCursor(0,2);
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
  arrayIndex=0; 
  total=1;
  total1=1;
  volume=1;
  
  var=0;
  var2=0;


  
}






