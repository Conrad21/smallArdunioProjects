/*
// FirstName LastName - UIN
// Conrad Ptasznik - 668073457 - cptasz2 

// Lab x - Title
// Lab 3 - Scrolling output
 
// Description - what is this code supposed to do?
// The code should display my name and one of my favorite quotes to appear on the 16x2 display, name on first line and quote on the second line. 
// The quote should not all fit on the screen and so should scroll across the screen. Your name should not scroll across the screen, only the quote should scroll.  
//

// Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular arduino versions, etc.
// I expect it to be an easy build however I had over 4 wires that were defected so it would only display squares I also assumed that the 
// 16X2 display worked liked an 2D array but it didnt. 

// References -  https://www.arduino.cc/en/Tutorial/LiquidCrystalScroll as well as help from a TA

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//put my name and quote into a string var 
String quote = " \"It just works\" - Todd Howard"; 
String myName = "Conrad Ptasznik";

void setup() {
  // set up the number of columns and rows on the LSD screen:
  lcd.begin(16, 2);
  lcd.setCursor(0,1);                               // use to print second row
  lcd.print(quote);
}

void loop() {
  lcd.setCursor(0,0); //set the cursor to the top if the 16X2
  lcd.print(myName);  //print my name

// Each time it loops it will have to reset the Cursor to the 2nd row and print out the qutoe usesing a pointer 
//without the pointer it will not display the full quote 
  lcd.setCursor(0,1);  //Then set it to the second row
  for (int positionCounter = 0; positionCounter < 12; positionCounter++) {
      lcd.setCursor((0-positionCounter),1);                               
      lcd.print(&quote[positionCounter]);  
      delay(500);
    }
    
  lcd.clear(); //Clear the screen to set it back to the begining of the quote 
}
