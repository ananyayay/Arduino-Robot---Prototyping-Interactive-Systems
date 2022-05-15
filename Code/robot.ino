// Read 4 Servo Inputs
// 4 Servo Pins
// Add Infrared Sensor
#include <IRremote.h>  //including infrared remote header file     
int RECV_PIN = 7; // the pin where you connect the output pin of IR sensor     
IRrecv irrecv(RECV_PIN);     
decode_results results;  
int servoPin1 = 3;
int servoPin2 = 4;
int servoPin3 = 5;
int servoPin4 = 6;
void setup() {
    // put your setup code here, to run once:
    pinMode(servoPin1, OUTPUT);
    pinMode(servoPin2, OUTPUT);
    pinMode(servoPin3, OUTPUT);
    pinMode(servoPin4, OUTPUT);
    irrecv.enableIRIn();
}

void loop() {
    // Move all Servoes from 0 to 45
    if (irrecv.decode(&results))// Returns 0 if no data ready, 1 if data ready.     
    {     
    int results.value = results;// Results of decoding are stored in result.value     
    Serial.println(" ");     
    Serial.print("Code: ");     
    Serial.println(results.value); //prints the value a a button press     
    Serial.println(" ");     
    if (results.value == 1){
        Serial.println("Button 1 Pressed");
        servo1.write(45);
        servo2.write(45);
        servo3.write(45);
        servo4.write(45);
    }
    if (results.value == 2){
        Serial.println("Button 2 Pressed");
        servo1.write(10);
        servo2.write(10);
        servo3.write(10);
        servo4.write(10);
    }
    irrecv.resume(); // Restart the ISR state machine and Receive the next value     
    } 
}
