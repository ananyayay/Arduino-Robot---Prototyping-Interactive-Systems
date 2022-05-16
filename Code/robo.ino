// ---------------------------------------------------------------- //
// Arduino Ultrasoninc Sensor HC-SR04
// Re-writed by Arbi Abdul Jabbaar
// Using Arduino IDE 1.8.7
// Using HC-SR04 Module
// Tested on 17 September 2019
// ---------------------------------------------------------------- //

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 

//attach pin D3 Arduino to pin Trig of HC-SR04
#include <Servo.h>
// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
Servo myServo;
Servo secondServo;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  myServo.attach(7);
  
  secondServo.attach(11);
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;  // Speed of sound wave divided by 2 (go and back)
  // Displays the distance on the Serial Monitor
  if (distance < 5 ){
      int pos =  0;
      for (pos = 0; pos < 110 ;pos+=4){
         Serial.print("Servos should be moving because distance is : ");
         Serial.print(distance);
         Serial.println(" cm");
        myServo.write(pos);
        secondServo.write(90-pos);
        delay(1);
      }

      while(pos > 20){
        pos-=4;
        myServo.write(pos);
        secondServo.write(pos);
        delay(10);
      }
    }
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}