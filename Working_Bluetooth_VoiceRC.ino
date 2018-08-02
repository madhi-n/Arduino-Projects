//Coded By: Yash Malik
//Voice Activated Arduino (Bluetooth + Android)
#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11); // RX | TX

String voice;
int motorPin1  = 3;  
int motorPin2  = 5;  
int motorPin3  = 6;
int motorPin4  = 9;  

int trigPin = 12;
int echoPin = 13;


void setup() {
BT.begin(9600);
Serial.begin(9600);

pinMode (trigPin, OUTPUT);
pinMode (echoPin, INPUT);

}
//-----------------------------------------------------------------------//  
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = BT.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
  
  if (voice.length() > 0){
    if(voice == "*go forward"){
      forward_car();
      }
    else if(voice == "*go back"){
      back_car();
      }
    else if(voice == "*turn right") {
      right_car();
    }
    else if(voice == "*turn left") {
      left_car();
    }
    else if(voice == "*stop") {
      stop_car();
    }
    
  voice=""; //Reset the variable after initiating
  }

  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);
  int dur = pulseIn(echoPin, HIGH);
  int dis = (dur/2) / 29.1; 
  
  Serial.print(dis);
  Serial.print(" cm\n");

  if (dis <= 10){
    stop_car();
    delay(500);
    back_car();
    delay(500);
  }
  

}


void forward_car()
{
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 157);
    analogWrite(motorPin4, 0);  
}
  
void back_car()
{
    
    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 157); 
}
  
void right_car()
{
    
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
    delay(1100);
    stop_car();    
}
  
void left_car()
{
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);   
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);
    delay(1250);
    stop_car();       

}
void stop_car ()
{
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
}
