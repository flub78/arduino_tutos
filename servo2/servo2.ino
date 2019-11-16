/**
   controle d'un servo moteur
*/
#include <Stepper.h>

int cnt = 0;

// Here to set the stepper motor rotation is how many steps
#define STEPS 100

// attached toSet the step number and pin of the stepper motor
Stepper stepper(STEPS, 8, 9, 10, 11);

// Define variables used to store historical readings
int previous = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Welcome");// envoi d'un message

  // Set the motor at a speed of 90 steps per minute
  stepper.setSpeed(90);
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println(cnt++);

  int val = analogRead(0); // Get sensor readings
  stepper.step(val - previous);// Move the number of steps for the current readings    less historical readings
  previous = val;// Save historical readings

  delay(10);
}


