/**
   Unit testing
*/

#include <AUnit.h>

// The 32 bits integer in the Atmel AVR overflows after F[47], 
// so we will calculate up to this number
#define MAX_NUMBER 47
 
// Cache array
unsigned long f[MAX_NUMBER+1] = { 0 };
 
/*
 * Calculates and returns the n-th Fibonacci Number
 */
unsigned long fibonacci(unsigned long n) {
    if (0 == n) return 0;
    if (1 == n) return 1;
    if (0 == f[n]) {
        f[n] = fibonacci(n-2) + fibonacci(n-1);
    }
    return f[n];
}

test(fibonacci) {
    // Expected values taken from https://www.tools4noobs.com/online_tools/fibonacci/
    assertEqual(fibonacci(0 ), (unsigned long) 0);
    assertEqual(fibonacci(1 ), (unsigned long) 1);
    assertEqual(fibonacci(2 ), (unsigned long) 1);
    assertEqual(fibonacci(3 ), (unsigned long) 2);
    assertEqual(fibonacci(5 ), (unsigned long) 5);
    assertEqual(fibonacci(10), (unsigned long) 55);
    assertEqual(fibonacci(20), (unsigned long) 6765);
    assertEqual(fibonacci(30), (unsigned long) 832040);
 
}    

        
const int LED = 13;
int cnt = 0;
int on = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);         // the led PIN is declared as digital output
  Serial.begin(9600);
  Serial.println("Welcome");// envoi d'un message
  

}

void loop() {
  // For some reason, it works better inthe loop.
  // When called from the setup routine, tests are started but never complete
  aunit::TestRunner::run();

  Serial.println(cnt++);

  on = (on + 1) % 2;

  if (on) {
    digitalWrite(LED, HIGH);      // switching on the led
  } else {
    digitalWrite(LED, LOW);       // switching off the led
  }
  delay(2000);                  // stopping the program for 1000 milliseconds

}
