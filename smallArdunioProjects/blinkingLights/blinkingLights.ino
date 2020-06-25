/*
// FirstName LastName - UIN
// Conrad Ptasznik - 668073457 - cptasz2 

// Lab x - Title
// Lab 1 - Get started with Arduino

// Description - what is this code supposed to do?
// Using the onboard LED on pin 13 making it blink for one second, then a red LED on digital 7 to blink, and then a green LED on digital pin 3 
// to blink having this loop until Arduino is unplug.

// Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular arduino versions, etc.
// I expect the power to move to the the resistor from digital pin 3 to the LED then to the ground as shown in the Schematic on the tutoring site. This is 
//the same with the Green LED. 

// References -  https://www.arduino.cc/en/Tutorial/Blink as well as help from TAs from lab and the Built-In Example.  

*/

int LED_Red = 7;                    //digital pin  7
int LED_Green = 3;                  //digital pin  3

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN, LED_Red and LED_Green as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_Red, OUTPUT);
  pinMode(LED_Green, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);                        // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(100);                        // wait for a second
  
  digitalWrite(LED_Red, HIGH);       // turn the Red LED on (HIGH is the voltage level)
  delay(100);                        // wait for a second
  digitalWrite(LED_Red, LOW);        // turn the Red LED off by making the voltage LOW
  delay(100);                        // wait for a second
  
  digitalWrite(LED_Green, HIGH);     // turn the Green LED on by making the voltage High
  delay(100);                        // wait for a second
  digitalWrite(LED_Green, LOW);      // turn the Green LED off by making the voltage LOW
  delay(100);                        // wait for a second
}
