int melody[]={262, 196, 196, 220, 196, 0, 247, 262};
int noteDurations[]={4, 8, 8, 4, 4, 4, 4, 4};
int buttonAPin= 1;
int buttonBPin= 6;
int buttonCPin= 7;
int buttonDPin= 9;
int buzzerPin = 8;
void setup() {
    pinMode(buttonAPin, INPUT);
    pinMode(buttonBPin, INPUT); 
    pinMode(buttonCPin, INPUT);
    pinMode(buttonDPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
}

void loop() {
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    int buttonStateA = digitalRead(buttonAPin);
    int buttonStateB = digitalRead(buttonBPin);
    int buttonStateC = digitalRead(buttonCPin);
    int buttonStateD = digitalRead(buttonDPin);
    if (buttonStateA == 1) {
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
    }
    else if (buttonStateB == 1) {
    }
    else if (buttonStateC == 1) {
    }
    else if (buttonStateD == 1) {
    }
}
