/*
// FirstName LastName - UIN
// Conrad Ptasznik - 668073457 - cptasz2 

// Lab x - Title
// Lab 8 -  Interrupts

// Description - what is this code supposed to do?
// This lab is suppose to utilizes interrupts. When no button has been pressed the 16x2 display 
// will say "We have been waiting for X seconds", where X will be updated as time goes on.
// The buttons stop will interrupt the time and button resume will go back and reset the time back to 0

// Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular arduino versions, etc.
// I assumed we needed to use pins 2 and 3 for the buttons interrupts, I thought you would be able to reset milli()   

// References - http://arduino.cc/en/Reference/attachInterrupt and https://www.arduino.cc/en/Reference/Millis
//  as well as help from the TAs
*/


// include the library code:
#include <LiquidCrystal.h>
#include <TimeLib.h>

//--------- declare the variables 
const int rs = 12, en = 11, d4 = 10, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

unsigned long time1;
const int buttonPinStop = 2;     // the number of the pushbutton pin
const int buttonPinResume = 3; 
const int ledPin =  13;        // the number of the LED pin
int pressesCounterUp;          // helped to know when the button is being released.  
int pressesCounterDown; 
int buttonStateUp = 0;
int buttonStateDown = 0;
boolean flag = false; 
 
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
 
 // pinMode(ledPin, OUTPUT);
  pinMode(buttonPinStop, INPUT_PULLUP);
  pinMode(buttonPinResume, INPUT_PULLUP); 
  attachInterrupt(digitalPinToInterrupt(buttonPinStop), interrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(buttonPinResume), resumetime, CHANGE);
  time1 = millis(); 
  
}//setup

void loop() {
  lcd.clear();
  
//--if the flag isnt triggered show the time else show the intrupet message 
  if(flag == false) { 
    //time1 = second();

    long time2 = ((millis() - time1)/1000);
    lcd.setCursor(0,0);
    lcd.print("We have Been waiting for ");
    lcd.setCursor(0,1);     
    lcd.print(time2);  
    lcd.print(" seconds");     
    delay(500);  
 }

  else{
    lcd.print("Interrupt received!"); 
    lcd.setCursor(0,1); 
    lcd.print("Press button 2");  
     delay(500);
  } 
}//loop

//------ helper funtions to reset the flags
void resumetime() {
   if (flag == true){
     flag = false; 
     time1 = millis();
   }
}

void interrupt() {
  flag = true;
}
