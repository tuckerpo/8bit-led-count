/*  C Arduino sketch implemented to cycle through the bits in a byte and display them as LED output.
 *  Author: Tucker J. Polomik; github.com/thenergal
 *  Total uses 1,202 bytes of memory, runtime delimited by the delay() function.
 */






/* global member space */
const unsigned int maximum = 256;    //using 8 LEDs, 2^8 = 256 maximum iterations to be shown on board
const long debounce = 100;           //100 ms debounce added in case of button activation
byte bytepins[] = {5, 6, 7, 8, 9, 10, 11, 12};



void setup() {
    for (int i = 0; i < 9; ++i) {
        pinMode(bytepins[i], OUTPUT);
    }
}

void loop() {
    for (int currentBinaryCount = 0; currentBinaryCount < maximum; ++currentBinaryCount) {
        binaryToLED(currentBinaryCount);
        delay(300);
    }

}


/*  Helper function to convert a decimal number to binary and display it as digital output
 *  implements the bitRead(x,n) function -- read more about it: 
 *  https://www.arduino.cc/en/Reference/bitRead
 */

 void binaryToLED(byte input) {
    for (int i = 0; i < 8; ++i) {
      if (bitRead(input, i) == 1) {
          digitalWrite(bytepins[i], HIGH);
      } 
      else {
        digitalWrite(bytepins[i], LOW);
      }
    }
 }

