// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 13; 
// Create a servo object 
int i = 0;
Servo Servo1; 
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(0); 
}
void loop(){ 
  
  for (int i =0; i<10;i++){
    Servo1.write(0.3);
    delay(10000);
    
  }
  
  
  delay(1000);
  Servo1.write(0);
  Serial.print("here");
}
