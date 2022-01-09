/**
   Un Hello world Ardino
*/

const int LED = 13;
int cnt = 0;
int on = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);         // the led PIN is declared as digital output
  Serial.begin(9600);
  Serial.println("Welcome");// envoi d'un message
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(cnt++);

  on = (on + 1) % 2;

  if (on) {
    digitalWrite(LED, HIGH);      // switching on the led
  } else {
    digitalWrite(LED, LOW);       // switching off the led
  }
  delay(1000);                  // stopping the program for 1000 milliseconds
}
