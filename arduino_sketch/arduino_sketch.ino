int enableLeft = 10;
int enableRight = 11;

int leftA = 8;
int leftB = 9;
int rightA = 12;
int rightB = 13;


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(enableLeft, OUTPUT);
    pinMode(enableRight, OUTPUT);
 
    pinMode(leftA, OUTPUT);
    pinMode(leftB, OUTPUT);
    pinMode(rightA, OUTPUT);
    pinMode(rightB, OUTPUT);
    
    stop();
    
    digitalWrite(leftA, HIGH);
    digitalWrite(leftB, LOW);
    digitalWrite(rightA, HIGH);
    digitalWrite(rightB, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  

  
}

void forward(){
  analogWrite(enableLeft, 255);
  analogWrite(enableRight, 255);
  

}
void left(){
  
  analogWrite(enableLeft, 153);
  analogWrite(enableRight, 255);
  
}
void right(){
  
  analogWrite(enableLeft, 255);
  analogWrite(enableRight, 153);

}
void stop(){
  analogWrite(enableLeft, 0);
  analogWrite(enableRight, 0);
}

