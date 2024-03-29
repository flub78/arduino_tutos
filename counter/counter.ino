/**
   Un Hello world Ardino

   Clignotement de la diode 13
   et affiche la valeur d'un compteur sur la console
*/

const int LED = 13;
int cnt = 0;
int on = 0;
const int DELAY = 2000;

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
  delay(DELAY);                  // stopping the program for 1000 milliseconds
}
