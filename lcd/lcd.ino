/**
   temperature and pressure on LCD

   Température and pression from DHT11 or BMP280

*/
#include <LiquidCrystal.h>
#include <Wire.h>
#include "SPI.h"
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP280.h"

#include "DHT.h"

// LCD in 4 bits mode
// LiquidCrystal nomDeVariable(RS, E, d4, d5, d6, d7);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int LED = 13;
int cnt = 0;
int on = 0;

const int DHTPIN = 9;     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

float temp = 0.0;
long lmVal = 0;

// BMP280
float pressure;
float temperature;
float altitude;

Adafruit_BMP280 bmp;


void setup() {
  pinMode(LED, OUTPUT);         // the led PIN is declared as digital output
  Serial.begin(9600);
  Serial.println("LCD + pressure");// envoi d'un message

  lcd.begin(16, 2); //on initialise la communication avec 16 colonnes et deux lignes
  lcd.clear(); // on efface l'écran

  dht.begin();
}

void loop() {
  Serial.println(cnt++);

  lmVal = analogRead(A0);
  temp = (lmVal * 0.0048828125 * 100);



  on = (on + 1) % 2;
  if (on) {
    digitalWrite(LED, HIGH);      // switching on the led
  } else {
    digitalWrite(LED, LOW);       // switching off the led
  }

  // read without samples.
  byte temperature = 0;
  byte humidity = 0;

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);

  Serial.println(F("°C "));

  lcd.clear(); // on efface l'écran
  lcd.print("Temp : ");
  lcd.setCursor(7, 0); //on passe à la ligne suivante
  lcd.print(t); //
  lcd.print(char(223));

  lcd.setCursor(0, 1); //on passe à la ligne suivante
  lcd.print("Humidity: "); // on finit d'écrire
  lcd.print(h);
  lcd.print('%');


  // DHT11 max sampling rate is 1HZ.
  delay(1000);                  // stopping the program for 1000 milliseconds
}
