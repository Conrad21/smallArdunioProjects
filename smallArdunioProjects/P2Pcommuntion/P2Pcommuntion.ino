/*
////////                       ~~~~~HEADER~~~~~                                          ////////
////////  Conrad Ptasznik - 668073457 - cptasz2                                            ////////
////////  Nicole Laczny - 655989470 - nlaczn2                                                ////////
////////  Lab 7 - Arduino to Arduino communication                                         ////////

////////  Lab Description:
////////    work with a partner, or if you have two arduino devices you can work alone     ////////
////////    connect two arduino's via a hardwired serial connection (no usb cable)         ////////
////////    (digital pins 0 and 1) connect a button and an external LED to each device     ////////
////////    pressing the button on one arduino should cause the other arduino's LED to     ////////
////////    change state (on to off, or off to on)Button press on one arduino should       ////////
////////    toggle the state of the LED on the other (on/off) and not keep the LED lit     ////////
////////    while being pressed utilize the 16x2 display for debugging refer to lab 6 for  ////////
////////    all the info about serial communication and lab2 for maintaining led states    ////////
////////    with button presses.                                                           ////////
////////  Hints:
////////    Both boards have to share the same ground in order for the serial              ////////
////////    communication to work properly. The same code should run on both arduinos.     ////////
////////    You and your partner may submit the same code, if you both have worked on it   ////////
////////    together.                                                                      ////////
////////  Assumptions:                                                                     ////////
////////    we assumed that digital write/read will send tata over to the pins on the      ////////
////////    other arduino, but it turned out that pin 0/pin 1 are hard wired and that      ////////
////////    analog.write/read will automatically send data to each other                   ////////
////////  Setup:                                                                           ////////
////////    const int buttonPinUp = 7;     // the number of the pushbutton pin             ////////
////////    const int ledPin =  13;        // the number of the LED pin                    ////////
////////    const int LED1 = 8;            //What set pins the LED are using               ////////
////////    rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;                              ////////
////////    LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                                     //////// 
////////  References:                                                                      ////////
////////    - http://arduino.cc/en/Reference/Serial#.UwYyzfldV8E                           ////////
////////    - http://arduino.cc/en/Serial/Available#.UwYy2PldV8E                           ////////
////////    - http://arduino.cc/en/Serial/ReadBytesUntil#.UwYy6_ldV8E                      ////////
////////    - help from the TAs(ALEX)                                                      ////////
*/
// include the library code:
#include <LiquidCrystal.h>

//--------- declare the variables 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int buttonPinUp = 7;     // the number of the pushbutton pin
const int ledPin =  13;        // the number of the LED pin
const int LED1 = 8;            //What set pins the LED are using
int pressesCounterUp;          // helped to know when the button is being released.  
int pressesCounterDown; 
int buttonStateUp = 0;
int buttonStateDown = 0;
int checker; 
int byte2; 


//SETUP 
void setup() {
  // initialize the LED pin as an output:
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(LED1, OUTPUT);    //For LED that represents 1
  pinMode(buttonPinUp, INPUT); //initialize the pushbutton pin as an input:
  lcd.print("hello"); 
}//setup()


//MAIN CODE
void loop() {
  lcd.clear();
  buttonStateUp = digitalRead(buttonPinUp);
  
  //TURN LED ON/OFF
  if (Serial.available()>0)  {
    byte2 = Serial.read();
    if(digitalRead(LED1) == HIGH) digitalWrite(LED1, LOW);
    else digitalWrite(LED1, HIGH);  // delay(200); 
  }
//else  digitalWrite(LED1, LOW); //used for debugging 

  //CHECK TO SEE IF BUTTON BEING HELD DOWN
  if( checker !=  buttonStateUp){        //if the counter and the button isnt pressed
    if (buttonStateUp == HIGH) {                    // if they are the same it means that button is being held    
//      Serial.print("Read UP switch input: ");     //used for debugging 
//      lcd.print(digitalRead(buttonPinUp));        //used for debugging 
//      Serial.print("Read DOWN switch input: ");   //used for debugging 
//      lcd.print(digitalRead(buttonPinUp));        //used for debugging 
//      Serial.println(digitalRead(buttonPinDown)); //used for debugging 
//      digitalWrite(LED1, HIGH);                   //used for debugging 
      Serial.write("1");
     //delay(500);  //if you hold it   
   }//if 
   checker = buttonStateUp; 
  }//if

}//loop()
