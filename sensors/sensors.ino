/**
   Sensors states
*/

const int LED = 6;
const int GPIO = 7;
const int LASER = 8;
const int BUZZER = 9;

const int PHOTO_RESISTOR = A0;
const int POTENTIOMETER = A1;

void setup()
{
  Serial.begin(9600); //Initialisation de la communication avec le moniteur série
  pinMode(GPIO, INPUT_PULLUP); //On Off
  pinMode(LED, OUTPUT);
  pinMode(LASER, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void print_value(char * str, int value) {
  Serial.print(str);
  Serial.println(value);
}

void loop()
{
  boolean push1 = digitalRead(GPIO);// et on l’affecte à la variable "a"
  Serial.print("GPIO 7: ");
  Serial.println(push1); // on l'affiche sur le moniteur

  int a0 = analogRead(PHOTO_RESISTOR);
  int a1 = analogRead(POTENTIOMETER);

  print_value("PHOTO_RESISTOR: ", a0);
  print_value("POTENTIOMETER: ", a1);
  Serial.println("");

  digitalWrite(LED, push1);
  digitalWrite(LASER, ! push1);

  if (!push1) {
    digitalWrite(BUZZER, HIGH);
    delay(a1);
    digitalWrite(BUZZER, LOW);
  }
  delay(a1);

}

