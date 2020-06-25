/*
/ FirstName LastName - UIN
// Conrad Ptasznik - 668073457 - cptasz2 

// Lab x - Title
// Lab 6 -  Communication

// Description - what is this code supposed to do?
// This lab is suppose to use the downloaded funtion <Time.h> and <TimeLib.h> in order for the arduino to produce a clock and incerment  
// that clock by 1 second every second until it is turned off. This code must also be able to take in user input via a seral connection
// and be able to error check as well due to the Time lib not being able to error check for us. 

// Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular arduino versions, etc.
// I assumed that arduinos would have a scanf function like in C but instead it loops until there is something in the serial

/// References - http://arduino.cc/en/Reference/Serial#.UwYyzfldV8E, http://arduino.cc/en/Serial/Available#.UwYy2PldV8E, http://arduino.cc/en/Serial/ReadBytesUntil#.UwYy6_ldV8E
// as well as the time libary http://playground.arduino.cc/Code/Time#.UwYyQPldV8E and help from the TAs 

 
*/

//--------- include the library code:
#include <LiquidCrystal.h>
#include <Time.h>
#include <TimeLib.h> 


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int themonth= 1;
int days;
int yr;
int hr;
int mins = -1;
int sec;
int flag = 0; 

//-------Set up the data for the time fuction and error check it as well 

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
   Serial.begin(9600);
  // Print on LCD to make sure its works 
  lcd.print("You got this far"); //error check for LCD
  Serial.print("Please Enter date mm/dd/yyyy\n");
  String incomingByte;


 //-------------------- Three flags in the while loops if it 
 //-------------------- passes all 3 it means its a vaild date 
  
  while(flag < 3){
    flag = 0; //rest flag and check for errors for new input 
    incomingByte = Serial.read();
    
    if (Serial.available()>0) {
      themonth = Serial.parseInt();
      days = Serial.parseInt();
      yr = Serial.parseInt();

//------------------------ if the mouth is not between 1 and 12
        if(themonth > 12 || themonth < 1 ){
          Serial.print("Invalid month\n");
        }
        else {
          flag++; 
        }

 //------if the month is between 1 and 12, check to make sure it has a vaild mouth  
       if(days < 32 && days > 0 ){
          if( (themonth  == 1 || themonth  == 3 || themonth  == 5 || themonth  == 7 || themonth  == 8 || themonth  == 10 || themonth  == 12) &&  (days <= 31)){
               flag = flag  + 1; 
          }

          else if( (themonth  == 4 || themonth  == 6 || themonth  == 9 || themonth  == 11) &&  (days <= 30)){
              flag = flag + 1; 
          }
        
          else if( (themonth  == 2 &&  days <= 28)){
              flag = flag+ 1; 
          }

          else{
            Serial.print("Invalid day for that month!\n");
          }
       }
       else{
           Serial.print("Invalid day for that month\n");
       }
       
//----------- set time doesnt work with years less then 1970, so it has check to
// make sure its not below that 

       if( yr <= 1970 ){
          Serial.print("Invalid year\n");
        }
       else {
         flag = flag + 1; 
       }
       //  Serial.print(flag);
     }//if
  }//while
   
flag = 0; //reset flag for next while loop

Serial.print("\nPlease Enter the time Hour/Mins/Seconds\n");
  while(flag < 3){
    flag = 0;
    incomingByte = Serial.read();
        if (Serial.available()>0) {
           hr = Serial.parseInt();
           mins = Serial.parseInt();
           sec = Serial.parseInt();
           
 //-------------------------- Check to see if the hour is between 0 and 24           
            if(hr < 0 || hr > 24){
                 Serial.print("Invalid time for hours\n");
            }
            else{
              flag = flag + 1; 
            }

 //------------------------- Check to see if the mins are between 0 and 60           
            if( mins > 0 && mins < 60){
                  flag= flag + 1; 
            }
            else{
              Serial.print("Invalid time for mins\n");
            }

   //------------------  Check to see if the seconds are between 0 and 60 
             if(sec < 0 || sec > 60){
                 Serial.print("Invalid time for seconds\n");
            }
            else{
              flag= flag + 1; 
            }
      }//if 
  }//while 
     
Serial.print("Inputing time data to LCD\n");  //for error checking to make sure I get out of set up 
setTime(hr,mins,sec, days,themonth,yr); //set the time on the time function 
}


void loop() {
  lcd.clear(); //clear the screen

 //get the current time on the clock and extract all the 
 // hr,mins,sec, days,themonth and yr
 
 time_t t = now();
 sec = second(t); 
 
 //Serial.print(sec);
 hr = hour(t); // Returns the hour for the given
 mins = minute(t); // Returns the minute for the given
 days = day(t); // The day for the given time t
 themonth = month(t); // The month for the given time t
 yr = year(t); // The year for the given time t

 //print it out on the LCD screen 
 lcd.print(themonth);
 lcd.print("/");
 lcd.print(days);
 lcd.print("/");
 lcd.print(yr);
 
 lcd.setCursor(0,1);
 lcd.print(hr);
 lcd.print(":");
 lcd.print(mins);
  lcd.print(":");
 lcd.print(sec);
 
 // delay at the end of the loop
  delay(1000);

}
