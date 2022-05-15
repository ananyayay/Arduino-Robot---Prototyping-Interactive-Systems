// Read 4 Servo Inputs
// 4 Servo Pins
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
}

void loop() {
    // Move all Servoes from 0 to 45
    for (int i = 0; i <= 45; i++) {
        servo1.write(i);
        servo2.write(i);
        servo3.write(i);
        servo4.write(i);
        delay(10);
    }
}
