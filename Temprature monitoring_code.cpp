#include <LiquidCrystal.h>

// LCD pins: RS, EN, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// tempin
int tempPin = A0;
// function to setup 
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("Temp Monitor");




  delay(5000);
  lcd.clear();
}

void loop() {
  int sensorValue = analogRead(tempPin);

  float voltage = sensorValue * (5.0 / 1023.0);
  float tempC = voltage * 100.0;          // LM35: 10mV per °C
  float tempF = (tempC * 9.0 / 5.0) + 32; // Celsius to Fahrenheit

  lcd.setCursor(0, 0);
  lcd.print("Temp in C = ");
  lcd.print(tempC);

  lcd.setCursor(0, 1);
  lcd.print("Temp in F = ");
  lcd.print(tempF);

  Serial.print("Temp in C: ");


  Serial.print(tempC);
  Serial.print("  Temp in F: ");

  Serial.println(tempF);



  delay(5000);
}
