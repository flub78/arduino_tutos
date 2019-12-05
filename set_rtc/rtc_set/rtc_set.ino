#include <Wire.h>

/**
   Experimentation on DS3231  Real Time Clock

  SCL is the clock line. It is used to synchronize all data transfers
  over the I2C bus. SDA is the data line. The SCL & SDA lines are connected
  to all devices on the I2C bus.

  Board I2C / TWI pins
  Uno, Ethernet A4 (SDA), A5 (SCL)
  Mega2560  20 (SDA), 21 (SCL).

  https://github.com/NorthernWidget/DS3231/blob/master/DS3231.h

  To initialize the RTC uncomment the mathincg lines in the setup

  Read the current time and display it on the console.

  Set up alarm 1 for the next minute after startup.
  Print a trace when an alarm is triggered.

*/

#include <DS3231.h>

#include <Wire.h>

DS3231 Clock;
RTClib RTC;

byte ADay, AHour, AMinute, ASecond, ABits;
bool ADy, A12h, Apm;


void setup() {
  // Start the I2C interface
  Wire.begin();
  // Start the serial interface
  Serial.begin(9600);

  // set the RTC. Only once,after the time should be kept by the batterry
  //   Clock.setClockMode(0);
  //   Clock.setSecond(0);
  //   Clock.setMinute(8);
  //   Clock.setHour(19);
  //   Clock.setDoW(3);
  //   Clock.setDate(27);
  //   Clock.setMonth(11);
  //   Clock.setYear(19);

  // 
  DateTime now = RTC.now();
  Serial.println ("##########################");

  // void setA1Time(byte A1Day, byte A1Hour, byte A1Minute, byte A1Second, byte AlarmBits, bool A1Dy, bool A1h12, bool A1PM);
  Clock.setA1Time(now.day(), now.hour(), now.minute()+ 1, 0, 0, 0, 0, 0);
}

void loop() {

  // send what's going on to the serial monitor.

  DateTime now = RTC.now();

  char buffer[100];
  sprintf(buffer, "%02u/%02u/%4u %02u:%02u:%02u, ",
          now.day(), now.month(), now.year(),
          now.hour(), now.minute(), now.second()
         );
  Serial.print(buffer);

  // Display the temperature
  Serial.print("T=");
  Serial.print(Clock.getTemperature(), 2);

  // Tell whether the time is (likely to be) valid
  if (Clock.oscillatorCheck()) {
    Serial.print(" O+");
  } else {
    Serial.print(" O-");
  }

  // Indicate whether an alarm went off
  if (Clock.checkIfAlarm(1)) {
    Serial.print(" A1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  }
  if (Clock.checkIfAlarm(2)) {
    Serial.print(" A2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
  }
  // New line on display
  Serial.print('\n');

  // Display Alarm 1 information
  Serial.print("Alarm 1: ");
  Clock.getA1Time(ADay, AHour, AMinute, ASecond, ABits, ADy, A12h, Apm);
  Serial.print(ADay, DEC);
  if (ADy) {
    Serial.print(" DoW");
  } else {
    Serial.print(" Date");
  }
  Serial.print(' ');
  Serial.print(AHour, DEC);
  Serial.print(' ');
  Serial.print(AMinute, DEC);
  Serial.print(' ');
  Serial.print(ASecond, DEC);
  Serial.print(' ');
  if (A12h) {
    if (Apm) {
      Serial.print('pm ');
    } else {
      Serial.print('am ');
    }
  }
  if (Clock.checkAlarmEnabled(1)) {
    Serial.print("enabled");
  }
  Serial.print('\n');
  // Display Alarm 2 information
  Serial.print("Alarm 2: ");
  Clock.getA2Time(ADay, AHour, AMinute, ABits, ADy, A12h, Apm);
  Serial.print(ADay, DEC);
  if (ADy) {
    Serial.print(" DoW");
  } else {
    Serial.print(" Date");
  }
  Serial.print(' ');
  Serial.print(AHour, DEC);
  Serial.print(' ');
  Serial.print(AMinute, DEC);
  Serial.print(' ');
  if (A12h) {
    if (Apm) {
      Serial.print('pm');
    } else {
      Serial.print('am');
    }
  }
  if (Clock.checkAlarmEnabled(2)) {
    Serial.print("enabled");
  }
  // display alarm bits
  Serial.print('\nAlarm bits: ');
  Serial.print(ABits, BIN);

  Serial.print('\n');
  Serial.print('\n');
  delay(1000);
}

