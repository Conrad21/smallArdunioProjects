
// constants won't change. They're used here to set pin numbers:
const int buttonPinUp = 12;     // the number of the pushbutton pin
const int buttonPinDown = 2; 
const int ledPin =  13;      // the number of the LED pin
const int LED1 = 7;
const int LED2 = 5;
const int LED4 = 3;

// variables will change:
int buttonStateUp = 0;// variable for reading the pushbutton status
int buttonStateDown = 0;
int LED1state = 0;  
int LED2state = 0;  
int LED4state = 0;  

int changeLED = 0; 
void setup() {
  // initialize the LED pin as an output:
   pinMode(ledPin, OUTPUT);
   pinMode(LED1, OUTPUT);    //1
   pinMode(LED2, OUTPUT);    //2
   pinMode(LED4, OUTPUT);    //4
   
  //initialize the pushbutton pin as an input:
  pinMode(buttonPinUp, INPUT);
  pinMode(buttonPinDown, INPUT);
  Serial.begin(9600);
  
}

void loop() {
  // read the state of the pushbutton value:
  
  buttonStateUp = digitalRead(buttonPinUp);
  buttonStateDown = digitalRead(buttonPinDown);
  
  Serial.print("Read UP switch input: ");
  Serial.println(digitalRead(buttonPinUp)); 
  Serial.print("Read DOWN switch input: ");
  Serial.println(digitalRead(buttonPinDown)); 
  delay(200);  //if you hold it 

  LED1state = digitalRead(LED1);
  LED2state = digitalRead(LED2);
  LED4state = digitalRead(LED4);

 
//-----------------------------------Button Press incr
  if (buttonStateUp == HIGH) {   
    if (LED1state == LOW ) {                             // +1
      digitalWrite(ledPin, HIGH);
      digitalWrite(LED1, HIGH);      //turn one LED 1 
    }

    else if (LED1state == HIGH && LED2state == LOW ) {    //1 to 2
     digitalWrite(ledPin, HIGH);
     digitalWrite(LED2, HIGH);      //turn one LED 2
     digitalWrite(LED1, LOW);   
    }
    
   else if (LED1state == HIGH && LED2state == HIGH ) {     // 3 to 4
    digitalWrite(LED4, HIGH); 
    digitalWrite(LED1, LOW); 
    digitalWrite(LED2, LOW); 
    }
   }
//-----------------------------------Button Press dec
    
  if (buttonStateDown == HIGH) { 
     if (LED1state == HIGH ) {      // -1
        digitalWrite(ledPin, LOW);
        digitalWrite(LED1, LOW);      //turn one LED 1 
     }

     else if (LED1state == LOW && LED2state == LOW && LED4state == HIGH) { //4 to 3 SP CASE
        digitalWrite(LED1, HIGH);      
        digitalWrite(LED2, HIGH);  
        digitalWrite(LED4, LOW);  
     }
     
    else if (LED1state == HIGH && LED2state == HIGH  ) {  // 7 to 6   
      digitalWrite(LED1, LOW);  
      digitalWrite(LED2, LOW);
      
    }

     
     else if (LED1state == LOW && LED2state == HIGH) {  //  6 to 5 
        digitalWrite(LED1, HIGH);      
        digitalWrite(LED2, LOW); 
         
     }

  }
  

 
}
