
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



import processing.serial.*;

  Serial myPort;        // The serial port
  int xPos = 1;         // horizontal position of the graph
  float inByte = 0;
  float inByte2 = 0; 
  void setup () {
    // set the window size:
    size(400, 300);

    // List all the available serial ports
    // if using Processing 2.1 or later, use Serial.printArray()
    println(Serial.list());

    // I know that the first port in the serial list on my Mac is always my
    // Arduino, so I open Serial.list()[0].
    // Open whatever port is the one you're using.
    myPort = new Serial(this, Serial.list()[1], 9600);

    // don't generate a serialEvent() unless you get a newline character:
    myPort.bufferUntil('\n');

    // set initial background:
    background(0);
  }

  void draw () {
    // draw the line:
    stroke(127, 34, 255);
    line(xPos, height, xPos, height - inByte);

    // at the edge of the screen, go back to the beginning:
    if (xPos >= width) {
      xPos = 0;
      background(0);
    } else {
      // increment the horizontal position:
      xPos++;
    }
  }

  void serialEvent (Serial myPort) {
    // get the ASCII string:
    String inString = myPort.readStringUntil('\n');
   // String inString2 = myPort.readStringUntil('\n');
      println(inString);
     //  println(inString2);
    if (inString != null) {
      // trim off any whitespace:
      inString = trim(inString);
      // convert to an int and map to the screen height:
      inByte = float(inString);
   //   println(inString);
     // inByte2 = float(inString2);
      //println(inByte);
      inByte = map(inByte, 0, 1023, 0, height);
      //inByte2 = map(inByte, 0, 1023, 0, height);
    }
  }
