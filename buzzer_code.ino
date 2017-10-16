/*
This code should work to get warning cross the buzzer when something be closer than 0.5 meter
 Circuit is ultrasonic sensor and buzzer +5v and Arduino uno is used
 a_atef45@yahoo.com
 www.zerosnones.net
 +201153300223
 */
// Define pins for ultrasonic and buzzer
int const trigPin = 10;
int const echoPin = 9;
int const buzzPin = 3; // Use a PWM output pin so tone instruction will work
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // trig pin will have pulses output
  pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
  pinMode(buzzPin, OUTPUT); // buzz pin is output to control buzzering
}


// Duration will be the input pulse width and distance will be the distance to the obstacle in centimeters
int duration, distance;


void loop()
{
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
  

  /*****
   * // if distance less than 10cm and more than 0 (0 or less means over range)
   * if (distance < 10 && distance > 0) {
   * // Buzz
   * //digitalWrite(buzzPin, HIGH);
   * tone(buzzPin, 2000, 500); // 2000 Hz for 500 ms
   * } 
   * else {
   * // Don't buzz
   * //digitalWrite(buzzPin, LOW);
   * tone(buzzPin, 1000, 500); // 1000 Hz for 500 ms
   * }
   *****/

  tone(buzzPin, 8000/distance);  // Tone freq in Hz is 8000/dist in cm (so closer gives higher freq)

  // Waiting 10 ms won't hurt any one
  delay(10);
}



