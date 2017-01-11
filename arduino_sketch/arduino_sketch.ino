#include <SoftwareSerial.h>

int enableLeft = 10;
int enableRight = 11;

int leftA = 8;
int leftB = 9;
int rightA = 12;
int rightB = 13;

SoftwareSerial mySerial(2, 3);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    Serial.setTimeout(50);
    mySerial.begin(115200);
    mySerial.setTimeout(50);
    
    pinMode(enableLeft, OUTPUT);
    pinMode(enableRight, OUTPUT);
 
    pinMode(leftA, OUTPUT);
    pinMode(leftB, OUTPUT);
    pinMode(rightA, OUTPUT);
    pinMode(rightB, OUTPUT);
   
    digitalWrite(leftA, HIGH);
    digitalWrite(leftB, LOW);
    digitalWrite(rightA, HIGH);
    digitalWrite(rightB, LOW);

}

void loop() {
  
 if (mySerial.available()) {
    String direction = mySerial.readString();
    direction.trim();
    Serial.print(direction);
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

void forward(){
  analogWrite(enableLeft, 255);
  analogWrite(enableRight, 255);
}
void left(){
  analogWrite(enableLeft, 127);
  analogWrite(enableRight, 255);
}
void right(){
  analogWrite(enableLeft, 255);
  analogWrite(enableRight, 127);
}
void stop(){
  analogWrite(enableLeft, 0);
  analogWrite(enableRight, 0);
}

