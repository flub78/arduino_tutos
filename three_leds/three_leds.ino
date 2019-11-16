/**
   Un Hello world Ardino
*/

const int RED_LED = 8;
/**
const int GREEN_LED = 12;
const int BLUE_LED = 7;
*/
const int GREEN_LED = 10;
const int BLUE_LED = 11;

const int SHORT_DELAY = 3000;


void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);         // the RED_LED PIN is declared as digital output
  pinMode(GREEN_LED, OUTPUT);         // the RED_LED PIN is declared as digital output
  pinMode(BLUE_LED, OUTPUT);         // the RED_LED PIN is declared as digital output
  
  Serial.begin(9600);
  Serial.println("3 LEDs...");// envoi d'un message
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Welcome");
  for (int i = 0; i <= 5; i++) {
      Serial.println("new cycle");
      int t = (1000 - i * 200);

      all_leds_off();
      delay(SHORT_DELAY);
      all_leds_on();
      delay(t * 3);

      sub_sma(RED_LED, t);
      sub_sma(GREEN_LED, t);
      sub_sma(BLUE_LED, t);
  }
}

int sub_sma(int led, int t) {
      all_leds_off();
      delay(SHORT_DELAY);
      one_on(led);
      delay(t);   
}

void all_leds(int state) {
  digitalWrite(RED_LED, state);      // switching on the RED_LED
  digitalWrite(GREEN_LED, state);      // switching on the RED_LED
  digitalWrite(BLUE_LED, state);      // switching on the RED_LED  
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


