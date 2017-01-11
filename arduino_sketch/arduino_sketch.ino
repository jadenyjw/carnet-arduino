/**************************************
 * Jaden Wang and Aidan Lui
 * CarNet - A self-driving car built with Arduino
 * 
 */



#include <SoftwareSerial.h>

//Declare variables for L293D 
int enableLeft = 10;
int enableRight = 11;
int leftA = 8;
int leftB = 9;
int rightA = 12;
int rightB = 13;

//Setup software serial
SoftwareSerial mySerial(2, 3);


void setup() {
    //Start serial interface
    Serial.begin(115200);
    Serial.setTimeout(50);
    mySerial.begin(115200);
    mySerial.setTimeout(50);

    //Enable pins for motors
    pinMode(enableLeft, OUTPUT);
    pinMode(enableRight, OUTPUT);
    
    pinMode(leftA, OUTPUT);
    pinMode(leftB, OUTPUT);
    pinMode(rightA, OUTPUT);
    pinMode(rightB, OUTPUT);

    //Turn on motors
    digitalWrite(leftA, HIGH);
    digitalWrite(leftB, LOW);
    digitalWrite(rightA, HIGH);
    digitalWrite(rightB, LOW);

}

void loop() {
 //Forever listen to serial from the ESP8266 for actions
 if (mySerial.available()) {
    String direction = mySerial.readString();
    direction.trim();
   

    //Depending on the request, complete a certain action.
    if (direction.equals("forward")){
      forward();
    }
    else if (direction.equals("left")){
      left();
    }
    else if (direction.equals("right")){
      right();
    }
    
  }
  else{
    //stop();
  }
  
}

//Drive forward
void forward(){
  analogWrite(enableLeft, 255);
  analogWrite(enableRight, 255);
}
//Drive left
void left(){
  analogWrite(enableLeft, 127);
  analogWrite(enableRight, 255);
}
//Drive right
void right(){
  analogWrite(enableLeft, 255);
  analogWrite(enableRight, 127);
}
//Stop
void stop(){
  analogWrite(enableLeft, 0);
  analogWrite(enableRight, 0);
}

