
/*
// FirstName LastName - UIN
// Conrad Ptasznik - 668073457 - cptasz2 

// Lab x - Title
// Lab 9 - Graphing sensor data on a PC


// Description - what is this code supposed to do?
// This code is suppose to connect two analog devices to the arduino and plot the data received on the computer using processing.
// data received on the computer using processing. The data will be displayed on one graph 

// Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular arduino versions, etc.
// I assumened that we would need to seperate the two incoming data into 2 different variables in processing

// References -  http://arduino.cc/en/Tutorial/Graph , https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing#introduction, 
//  as well as help from the TA
*/


int varA, varB; 

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
}

void loop() {
  Serial.println(analogRead(A0));  //potentiometer
  Serial.println(analogRead(A1));  //photo resistor

 
  // wait a bit for the analog-to-digital converter to stabilize after the last
  // reading:
  delay(4);
}
