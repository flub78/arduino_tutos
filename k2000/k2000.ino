/**
   Oeil de K2000
   OpenClassroom
   Arduino - Partie 1
*/

// les pins du montage
const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;

// Temp d'allumage des diodes
const int DELAY = 100;

// les LEDs dans l'ordre
int led[5] = {LED1, LED2, LED3, LED4, LED5};

void setup() {
  // put your setup code here, to run once:

  for (int i = 0; i <= 5; i++) {
    pinMode(led[i], OUTPUT);         // the PIN is declared as digital output
  }

  Serial.begin(9600);
  Serial.println("K2000 is watching you ...");// envoi d'un message

  // just in case
  all_leds_off();
}

void loop() {
  // put your main code here, to run repeatedly:

  // Going forward all the leds are switched on
  for (int i = 0; i < 5; i++) {
    digitalWrite(led[i], LOW);      // switching on the LED
    delay(DELAY);
    digitalWrite(led[i], HIGH);      // switching off the LED
  }

  // Going backward only the center LEDs are managed
  // to avoid the ends to be switched on twice
  for (int i = 3; i >= 1; i--) {
    digitalWrite(led[i], LOW);      // switching on the LED
    delay(DELAY);
    digitalWrite(led[i], HIGH);      // switching off the LED
  }

}

void all_leds(int state) {
  for (int i = 0; i <= 5; i++) {
    digitalWrite(led[i], state);      // switching on the LED1
  }
}

void all_leds_on() {
  all_leds(LOW);
}

void all_leds_off() {
  all_leds(HIGH);
}


