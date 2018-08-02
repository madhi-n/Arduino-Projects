int motorPin1  = 3;  
int motorPin2  = 5;  
int motorPin3  = 6;
int motorPin4  = 9;  

int trigPin = 12;
int echoPin = 13;
int duration = 0;
int distance = 100;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width

}


void loop() {
  // Output pulse with 1ms width on trigPin
  digitalWrite(trigPin, HIGH);
  delay(1);
  digitalWrite(trigPin, LOW);
  // Measure the pulse input in echo pin
  duration = pulseIn(echoPin, HIGH);
  // Distance in cm is half the duration devided by 29.1 (from datasheet)
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Serial.print(" cm\n");

  //roomba algorithm
  delay(5000); //for person to get ready once started
  forward_car();
  delay(3000);
  right_car();
  delay(1000);
  forward_car();
  delay(5000);
  left_car();
  delay(1000);
  forward_car();
  delay(3000);  
  left_car();
  delay(1000);
  forward_car();
  delay(3000);
   
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
void stop_car()
{
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
}


void safety_stop()
{
    if (distance <=20 && distance > 0) {
    stop_car();
    delay(2000);
    back_car();
    delay(1500);
    stop_car();
    left_car();
  }
}

