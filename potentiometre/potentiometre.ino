/**
   Gestion d'un joystick (double potentiometre)
*/

// les numéros de broche (pin)

const int LED_CENTRE = 4;

// la broche du bouton
const int BUTTON = 7;

/**
 * Initialisation
 */
void setup()
{
  // Les broches en sortie pour les diodes
  pinMode(LED_CENTRE, OUTPUT);
 
  // La broche en entrée pour le bouton
  pinMode(BUTTON, INPUT_PULLUP); 

  Serial.begin(9600);
  Serial.println("Welcome");// envoi d'un message
  
}

/**
 * Boucle principale du programme
 */
void loop()
{
  int ailerons; //déclaration de la variable qui va stocker la valeur numérique de la tension du potentiomètre
  int profondeur;

  ailerons = analogRead(A0); 
  profondeur = analogRead(A1); 

  Serial.print("ailerons: ");
  Serial.println(ailerons);
  Serial.print("profondeur: ");
  Serial.println(profondeur);

  digitalWrite(LED_CENTRE, LOW);
  delay(ailerons + 20);
  digitalWrite(LED_CENTRE, HIGH);
  delay(ailerons + 20);
}



