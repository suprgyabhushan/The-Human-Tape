// these constants won't change:
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int ledPin = 13;      // led connected to digital pin 13
const int knockSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 50;  // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin
int ledState = LOW;         // variable used to store the last LED status, to toggle the light

void setup() {
 pinMode(ledPin, OUTPUT); // declare the ledPin as as OUTPUT
 lcd.begin(16,2);
 Serial.begin(9600);       // use the serial port
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  lcd.clear();
  sensorReading = analogRead(knockSensor);    
  lcd.setCursor(0,1);
  // if the sensor reading is greater than the threshold:
  if (sensorReading > threshold) {
    // toggle the status of the ledPin:
    ledState = !ledState;   
    // update the LED pin itself:        
    
    digitalWrite(ledPin, HIGH);
    lcd.print("detected");
    delay(1000);
    digitalWrite(ledPin, LOW);
    
  }
  else{
    lcd.print("not detected");
     delay(1000); 
  }
  delay(100);  // delay to avoid overloading the serial port buffer
}
