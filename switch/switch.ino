/**
   Switch
*/

int switch_state = 0;
boolean a = false;
boolean previous_a = false;

void setup()
{
  Serial.begin(9600); //Initialisation de la communication avec le moniteur série
  pinMode(10, INPUT_PULLUP); //On indique à l’Arduino le mode du pin (entrée)
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  a = digitalRead(10);// et on l’affecte à la variable "a"

  // Serial.println(a); // on l'affiche sur le moniteur

  /**
   * The problem is that when the button is pushed, two state changes 
   * are detected. The first when the button is pressed, the second when it is released.
   * So only one out of two should be taken into account
   */
  boolean state_change = (a != previous_a);
  if (state_change && a) {
    // Serial.println("state change detected");
    // Serial.println(switch_state);
    switch_state = ! switch_state;
    // Serial.println(switch_state);
  }
  previous_a = a;

  if (switch_state) {
    digitalWrite(11, LOW); //led1 éteinte
    digitalWrite(12, HIGH); //led2 allumée
  } else {
    digitalWrite(12, LOW); //led1 éteinte
    digitalWrite(11, HIGH); //led2 allumée
  }
  delay(100);
}

