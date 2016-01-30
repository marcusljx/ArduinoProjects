#include "MorseBlinker.h"
/* BLINKS A STRING IN MORSE CODE ON A LOOP */


//============================================= GLOBALS
// using pin 13
int led = 13;

// default blink on/off delay
int unit = 250;
int dot_value = unit;
int dash_value = 3*unit;

int component_delay = unit;
int char_delay = 3*unit;
int word_delay = 7*unit;

String MESSAGE = "HELLO WORLD";

//============================================================== FUNCTION ROUTINES
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

void on_LED(int time) {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(time);               // wait for a second
}

void off_LED(int time) {
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(time);          
}

int findStringPos(String letter) {
  for(int i=0; i<CHARSET_SIZE; i++) {
    if(characters[i] == letter) return i;
  }
  return -1;
}



void morse_blinkCode(String code) {
  for(int i=0; i<code.length(); i++) {
    if(code.charAt(i) == '.') {
      on_LED(dot_value);
    } 
    else if(code.charAt(i) == '-') {
      on_LED(dash_value);
    }

    // standard delay between each component
    off_LED(component_delay);
  }
}

void morse_blinkChar(String input) {
  if(input == " ") {
    off_LED(word_delay);
  } 
  else {
    int pos = findStringPos(input);   // find corresponding morse code of character
    morse_blinkCode(morseSequences[pos]);  // blink the code
    off_LED(char_delay);
  }
}

void morse_blinkString(String input) {
  for(int i=0; i<input.length(); i++) {  // blink every character
    morse_blinkChar(String(input[i]));
  }
}

// the loop routine runs over and over again forever:
void loop() {  // wait for a second
  morse_blinkString(MESSAGE);
  off_LED(word_delay);
}
