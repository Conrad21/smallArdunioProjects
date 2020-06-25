/*
// FirstName LastName - UIN
// Conrad Ptasznik - 668073457 - cptasz2 

// Lab x - Title
// Lab 4 - More complicated input
 
// Description - what is this code supposed to do?
// The code should read in photo resistor and the arduino will produce a number based on how much sun light there
// is in room. Based on how much the number is will deteremine how bright the room is. Using if statement to display 
// how bright is it based on what range the number the photo resistor gives. Loop till turned off.  

// Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular arduino versions, etc.
// I expect the photo resistor to keep track of how much power in moving through, the more sun light there is  the more the power will  
// flow  through, the higher the number it will produce. 

// References -  http://learn.adafruit.com/photocells and http://playground.arduino.cc/Learning/PhotoResistor 

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// my setup 
String myName = "Conrad Ptasznik";
int lightPin = A2;  // pin for photo resistor


void setup() {
  // set up the number of columns and rows on the LSD screen:
  lcd.begin(16, 2);
  lcd.setCursor(0,1); 
  Serial.begin(9600);  // used to keep track of what number is being made
  
}

void loop() {
  //lcd.setCursor(0,0); //set the cursor to the top if the 16X2
  //lcd.print(myName);  //print my name
  Serial.println((analogRead(lightPin)/2)); //write what number the photo resistor is making in the serial 
 
  if ((analogRead(lightPin))/2 > 80){     // if larger then 80, its very bright in the room
     lcd.clear();
     lcd.print("Fully Lit" ); 
  }

   else if ((analogRead(lightPin)/2 <= 80) && (analogRead(lightPin)/2 > 70) ){   //if between 80 and 70, it partially light in the room 
     lcd.clear();
     lcd.print("Partially Light" ); 
  }
        

    else if ((analogRead(lightPin)/2 <= 70) && (analogRead(lightPin)/2 > 40) ){  // if between 40 and 70, medium light
     lcd.clear();
     lcd.print("Medium Light" ); 
     
  }
     else if ((analogRead(lightPin)/2 <= 40) && (analogRead(lightPin)/2 > 10) ){   //if between 40 and 10, partially dark
      lcd.clear();
      lcd.print("Partially Dark" ); 
     
  }
     else if ((analogRead(lightPin)/2 <= 10) ){    // if less then 10, its dark in the room 
      lcd.clear();
      lcd.print("Dark" ); 
  }
   
  delay(1000); //a dalay so it doesnt change too fast. 
  lcd.clear(); //Clear the screen and loop back to the begining 
}
