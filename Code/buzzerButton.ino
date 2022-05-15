#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int melody[]={262, 196, 196, 220, 196, 0, 247, 262};
int noteDurations[]={4, 8, 8, 4, 4, 4, 4, 4};
int buttonAPin= 6;
int buttonBPin= 7;
int buttonCPin= 8;
int buttonDPin= 9;
int buzzerPin = 10;
int buttonStateA;
int buttonStateB;
int buttonStateC;
int buttonStateD;
void setup() {
    pinMode(buttonAPin, INPUT);
    pinMode(buttonBPin, INPUT);
    pinMode(buttonCPin, INPUT);
    pinMode(buttonDPin, INPUT);
    buttonStateA = digitalRead(buttonAPin);
    buttonStateB = digitalRead(buttonBPin);
    buttonStateC = digitalRead(buttonCPin);
    buttonStateD = digitalRead(buttonDPin);
}

void loop() {
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    buttonStateA = digitalRead(buttonAPin);
    buttonStateB = digitalRead(buttonBPin);
    buttonStateC = digitalRead(buttonCPin);
    buttonStateD = digitalRead(buttonDPin);
    if (buttonStateA == 1) {
        Serial.println("A");
        for (int thisNote=0; thisNote <8; thisNote++){

            //to calculate the note duration, take one second. Divided by the note type
            int noteDuration = 1000 / noteDurations [thisNote];
            tone(buzzerPin, melody [thisNote], noteDuration);

            //to distinguish the notes, set a minimum time between them
            //the note's duration +30% seems to work well
            int pauseBetweenNotes = noteDuration * 1.30;
            delay(pauseBetweenNotes);

            //stop the tone playing
            noTone(8);
        }
        buttonStateA = 0;
    }
    else if (buttonStateB == 1) {
        Serial.println("B");
        buttonStateB = 0;
    }
    else if (buttonStateC == 1) {
        Serial.println("C");
        buttonStateC = 0;
    }
    else if (buttonStateD == 1) {
        Serial.println("D");
        buttonStateD = 0;
    }
    else if (buttonStateA == 0 && buttonStateB == 0 && buttonStateC == 0 && buttonStateD == 0){
        Serial.println("N");
    }
    else {
        Serial.println("X");
    }
    delay(400);
}
