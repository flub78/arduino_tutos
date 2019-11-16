/**
   Tirage aléatoire d'un dé sur l'appui d'un boutton.

   Lorsque vous appuyez sur le bouton poussoir, les LEDs s'allument
   à des intervalles de plus en plus lents en affichant un nombre aléatoire (entre 0 et 5)
   pour s'arrêter sur un nombre final entre 0 et 5. Les LEDs seront disposées comme le 5 d'un dé.

   Note: les leds toutes eteintes correspondent à la face 6 du dés.
*/

// les numéros de broche (pin)
const int LED_HAUT_GAUCHE = 2;
const int LED_HAUT_DROIT = 3;
const int LED_CENTRE = 4;
const int LED_BAS_GAUCHE = 5;
const int LED_BAS_DROIT = 6;

// la broche du bouton
const int BUTTON = 7;

// Le tableau des leds
const int led[5] = {LED_HAUT_GAUCHE, LED_BAS_GAUCHE, LED_CENTRE, LED_HAUT_DROIT, LED_BAS_DROIT};

// la topologie des constellations
int constellation[6][5] =
  {  LOW,  LOW,  LOW,  LOW,  LOW,  // 0
     LOW,  LOW, HIGH,  LOW,  LOW,  // 1
    HIGH,  LOW,  LOW,  LOW, HIGH,  // 2
     LOW, HIGH, HIGH, HIGH,  LOW,  // 3
    HIGH, HIGH,  LOW, HIGH, HIGH,  // 4
    HIGH, HIGH, HIGH, HIGH, HIGH}; // 5

/**
 * Initialisation
 */
void setup()
{
  // Initialisation de l'aléa
  randomSeed(analogRead(0)); 

  // Les broches en sortie pour les diodes
  for (int i = 0; i < 5; i++) {
    pinMode(led[i], OUTPUT);
  }

  // La broche en entrée pour le bouton
  pinMode(BUTTON, INPUT_PULLUP); 

  // appel de la fonction setZero() pour tout éteindre
  setZero();
}

/**
 * Boucle principale du programme
 */
void loop()
{
  if (appui_boutton()) {

    // On lance le dé qui va afficher 10 faces aléatoires avant de s'arreter
    for (int i = 0; i < 10; i++) {

      // exctinction brève des LEDs (100ms)
      setZero();
      delay(100);

      // tirage d'un nombre aléatoire avec la fonction random()
      // En cas réel il faudrait retirer le dé si on tombe deux fois sur la même face.
      // Un dé qui roule ne passe pas deux fois de suite sur la même face
      int alea = random(6);

      // appel de la fonction d'allumage des LEDs 
      affichage(alea);
      
      // Au début le dé roule vite, affichage pendant 1/10 sec, puis de
      // plus en plus lentement
      delay(100 * (i + 1));
    }
  }
}

/**
 * Eteint toutes les diodes
 */
void setZero() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(led[i], LOW); //led éteinte
  }  
}

/**
 * Allume la constellation correspondant à une face
 */
void affichage(int n) {
  for (int i = 0; i < 5; i++) {
    digitalWrite(led[i], constellation[n][i]);
  }
}

/**
 * Retourne vrai quand on appuie sur le boutton
 */
boolean appui_boutton () {
  return (digitalRead(BUTTON) == LOW);
}


