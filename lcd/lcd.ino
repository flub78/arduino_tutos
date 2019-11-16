/**
   Un Hello world sur écran LCD
*/
#include <LiquidCrystal.h>
#include <Wire.h>
#include "SPI.h"
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP280.h"

// LiquidCrystal nomDeVariable(RS, E, d4, d5, d6, d7);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int LED = 13;
int cnt = 0;
int on = 0;

float temp = 0.0;
long lmVal = 0;

// BMP280
float pressure;
float temperature;
float altitude;

Adafruit_BMP280 bmp;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);         // the led PIN is declared as digital output
  Serial.begin(9600);
  Serial.println("LCD + pressure");// envoi d'un message

  lcd.begin(16, 2); //on initialise la communication avec 16 colonnes et deux lignes
  lcd.clear(); // on efface l'écran
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(cnt++);

  lmVal = analogRead(A0);
  temp = (lmVal * 0.0048828125 * 100);

  lcd.clear(); // on efface l'écran
  lcd.print("Temp: "); // on écrit Bonjour
  lcd.setCursor(6, 0); //on passe à la ligne suivante
  lcd.print(temp); // on écrit Bonjour
  lcd.print(char(223));

  lcd.setCursor(0, 1); //on passe à la ligne suivante
  lcd.print("Pression: "); // on finit d'écrire
  lcd.print(cnt); // on finit d'écrire


  on = (on + 1) % 2;

  //Read values from the sensor:
  // pressure = bmp.readPressure();
  // temperature = bmp.readTemperature();
  // altitude = bmp.readAltitude (1013.00); //Change the "1050.35" to your city current barrometric pressure (https://www.wunderground.com)

  if (on) {
    digitalWrite(LED, HIGH);      // switching on the led
  } else {
    digitalWrite(LED, LOW);       // switching off the led
  }

  //Print values to serial monitor:
  Serial.print(F("Pressure: "));
  Serial.print(pressure);
  Serial.print(" Pa");
  Serial.print("\t");
  Serial.print(("Temp: "));
  Serial.print(temperature);
  Serial.print(" oC");
  Serial.print("\t");
  Serial.print("Altimeter: ");
  Serial.print(altitude); // this should be adjusted to your local forcase
  Serial.println(" m");

  delay(1000);                  // stopping the program for 1000 milliseconds
}
