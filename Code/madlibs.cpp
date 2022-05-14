#include <arduino.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void setup() {
    Serial.begin(9600);
    Serial.println("Hello World!");
}

    
void loop() {
    Serial.println("Hello World!");
    delay(1000);
}