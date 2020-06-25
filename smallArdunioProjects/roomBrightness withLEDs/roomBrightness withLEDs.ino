/*
// FirstName LastName - UIN
// Conrad Ptasznik - 668073457 - cptasz2 

// Lab x - Title
// Lab 5 - Multiple inputs and outputs

// Description - what is this code supposed to do?
//This is a 2 part arduino lab, the first part is just like lab 4, we take 4 LEDS and a photoresistor and if 
// the room is dark all 4 LED light up, if the room is Bright then all 4 are off if its slighty bright 1 LED is on
//
// The Second part we are using a passive buzzer and the potentiometer We will be controlling the buzzer using 
// the potentiometer. Because the potentiometer can go pass 255 in value, we need to use a map function. The buzzer 
// can only take up to 255. 

// Include any assumptions you may have made, what do you expect from the hardware, pinouts, particular arduino versions, etc.
// I assumened that potentiometer would need a resistor but it didnt which is why my values were off. 

// References -  https://www.arduino.cc/en/Reference/AnalogWrite , https://www.arduino.cc/en/Reference/Map, https://www.arduino.cc/en/Reference/AnalogRead
//  as well as pizzia posts for the buzzer layout 
*/

// All the var to keep track of my arduios outputs pins  
int lightPin = A1;    //Photoresistor
const int LED1 = 12;  //LED 1 
const int LED2 = 11;  //LED 2 
const int LED3 = 10;  //LED 3 
const int LED4 = 9;   //LED 4 
int buzzer = 4;       //Buzzer pin
int potmet = A3;      //Potentiometer


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(LED1, OUTPUT);    //LED 1 
  pinMode(LED2, OUTPUT);    //LED 2
  pinMode(LED3, OUTPUT);    //LED 3
  pinMode(LED4, OUTPUT);    //LED 4
  //pinMode(buzzer, OUTPUT);  
}

void loop() {
  // used to see the values my photoresistor 
  //Serial.println((analogRead(lightPin)));

//------------------ part 2 of the lab
  int val = (analogRead(potmet)); 
  val = map(val, 0, 1023, 0, 255); //make sure it the val doesnt go pass 255 
  Serial.println(val);  // used to see the values my potentiometer
  analogWrite(buzzer, val); //send value to buzzer; 


//----------------- part one of the lab   
    if ((analogRead(lightPin)) > 110) {  //if birght no LEDs are on 
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  } 
  
    //if somewhat bright turn on one LED
    else if ((analogRead(lightPin) <= 100) && (analogRead(lightPin) > 70) ) {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, HIGH);
  } 

    // if a  little bright, turn on 2 LEDs 
    else if ((analogRead(lightPin) <= 70) && (analogRead(lightPin) > 20)) {
    // turn LED on:
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH); 
  } 
  
    //if a little dark turn on 3 LEDs
    else if ((analogRead(lightPin)) > 20) {
    // turn LED on:
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  } 
  
  else {
    // if its just completely dark turn on all LEDs:
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  } 
  
  delay(100); //delay it by a 1/10 of a second
}
