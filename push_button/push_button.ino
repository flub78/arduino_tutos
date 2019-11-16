/**
   Un Hello world Ardino
*/

void setup()
{
  Serial.begin(9600); //Initialisation de la communication avec le moniteur série
  pinMode(10, INPUT_PULLUP); //On indique à l’Arduino le mode du pin (entrée)
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  boolean a = digitalRead(10);// et on l’affecte à la variable "a"

  Serial.println(a); // on l'affiche sur le moniteur

  if (a) {
    digitalWrite(11, LOW); //led1 éteinte
    digitalWrite(12, HIGH); //led2 allumée
  } else {
    digitalWrite(12, LOW); //led1 éteinte
    digitalWrite(11, HIGH); //led2 allumée
  }
}

