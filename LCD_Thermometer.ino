/*
  Arduino Starter Kit example
 Project 4  - Color Mixing Lamp

 This sketch is written to accompany Project 3 in the
 Arduino Starter Kit

 Parts required:
 1 RGB LED
 three 10 kilohm resistors
 3 220 ohm resistors
 3 photoresistors
 red green and blue colored gels

 Created 13 September 2012
 Modified 14 November 2012
 by Scott Fitzgerald
 Thanks to Federico Vanzati for improvements

 http://arduino.cc/starterKit

 This example code is part of the public domain
 */
 
 // RGD -- Modified the code of Projects 4 and 3.

#include <LiquidCrystal.h>

const int SENSORPIN = A0;  // pin with the temperature sensor

int sensorValue; // variable to hold the value read from the temperature sensor
float voltage;
float celsiusTemp;
float avgCelsiusTemp;
int numTemps;

const int TEMPERATUREADJUST = 1.9; // Change to calibrate against a thermometer reading
const int REFRESHDELAY = 2000;  // Delay in ms for reading and displaying next temperature
const int NUMTEMPSTOAVG = 250;
const int BPS = 9600;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



void setup() {
  
  // initialize serial communications at 9600 bps:
  //Serial.begin(BPS);
  
  numTemps = 0;
  avgCelsiusTemp = 0;
  
  lcd.begin(16, 2); // 16 cols, 2 rows
  lcd.noAutoscroll();
  lcd.noBlink();
  lcd.noCursor();
  lcd.clear();

  lcd.print("Celsius temp");

}  // end setup()



void loop() {
  
  // Read the sensor first:
  sensorValue = analogRead(SENSORPIN);
  // give the ADC a moment to settle
  delay(5);  // 5 ms

  // print out the sensor value to the serial monitor
  //Serial.print("Raw sensor value \t : ");
  //Serial.println(sensorValue);

  voltage = sensorValue / 1024.0 * 5.0;
  //Serial.print("Voltage \t\t : ");
  //Serial.println(voltage);
  
  celsiusTemp = ((voltage - 0.5) * 100);
  //Serial.print("Celsius temperature \t\t\t : ");
  //Serial.println(celsiusTemp);
  //Serial.println("");
  
  avgCelsiusTemp = avgCelsiusTemp + celsiusTemp;
  numTemps++;
  
  if ((numTemps % NUMTEMPSTOAVG) == 0) {
      avgCelsiusTemp = (avgCelsiusTemp / NUMTEMPSTOAVG) + TEMPERATUREADJUST;
      lcd.setCursor(0, 1);  // col 0, row 1
      lcd.print(avgCelsiusTemp, DEC);
      numTemps = 0;
      avgCelsiusTemp = 0;  
  
      delay(REFRESHDELAY);
}
      
}  // end loop()

