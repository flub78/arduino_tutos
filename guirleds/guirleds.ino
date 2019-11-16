/**
   Animation d'une sequence de LED
*/

const int RED_LED = 8;
const int GREEN_LED = 12;
const int BLUE_LED = 7;
const int GREEN_2_LED = 10;
const int BLUE_2_LED = 11;

const int DELAY = 1000;

// le tableau de leds
int led[5] = {BLUE_LED, GREEN_LED, RED_LED, BLUE_2_LED, GREEN_2_LED};

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);         // the RED_LED PIN is declared as digital output
  pinMode(GREEN_LED, OUTPUT);         // the RED_LED PIN is declared as digital output
  pinMode(BLUE_LED, OUTPUT);         // the RED_LED PIN is declared as digital output
  pinMode(BLUE_2_LED, OUTPUT);         // the RED_LED PIN is declared as digital output
  pinMode(GREEN_2_LED, OUTPUT);         // the RED_LED PIN is declared as digital output

  Serial.begin(9600);
  Serial.println("Guirleds...");// envoi d'un message
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Welcome");
  for (int i = 0; i <= 5; i++) {
    Serial.println("new cycle");

    first();
    second();
    third();
    fourth();
  }
}

void first() {

  all_leds_off();
  delay(DELAY);

  for (int i = 0; i <= 5; i++) {
    digitalWrite(led[i], LOW);      // switching on the RED_LED
    delay(DELAY);
  }

}

void second() {
  all_leds_off();
  delay(DELAY);

  for (int i = 0; i <= 5; i++) {
    digitalWrite(led[4 - i], LOW);      // switching on the RED_LED
    delay(DELAY);
  }

}

void third() {

  all_leds_on();
  delay(DELAY);

  for (int i = 0; i <= 5; i++) {
    digitalWrite(led[i], HIGH);      // switching on the RED_LED
    delay(DELAY);
  }

}

void fourth() {
  all_leds_on();
  delay(DELAY);

  for (int i = 0; i <= 5; i++) {
    digitalWrite(led[4 - i], HIGH);      // switching on the RED_LED
    delay(DELAY);
  }

}

void all_leds(int state) {
  for (int i = 0; i <= 5; i++) {
    digitalWrite(led[i], state);      // switching on the RED_LED
  }
}

void all_leds_on() {
  all_leds(LOW);
}

void all_leds_off() {
  all_leds(HIGH);
}

void one_on(int led) {
  all_leds_off();
  digitalWrite(led, LOW);
}


