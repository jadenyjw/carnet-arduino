int enableLeft = 10;
int enableRight = 11;

int leftA = 8;
int leftB = 9;
int rightA = 12;
int rightB = 13;


void setup() {
  // put your setup code here, to run once:
    pinMode(enableLeft, OUTPUT);
    pinMode(enableRight, OUTPUT);
 
    pinMode(leftA, OUTPUT);
    pinMode(leftB, OUTPUT);
    pinMode(rightA, OUTPUT);
    pinMode(rightB, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void forward(){
  
}
void left(){

}
void right(){

  
}
void stop(){
  analogWrite(enableLeft, 0)
  analogWrite(enableRight, 0)
}

