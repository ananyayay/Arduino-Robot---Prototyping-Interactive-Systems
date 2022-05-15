#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String Questions[] = {"1. What is the capital of India?", "2. What is the capital of France?", "3. What is the capital of Germany?", "4. What is the capital of Italy?"};
String options[][] = {{"1. Delhi",  "2. Paris", "3. Berlin", "4. Rome"},
                        {"1. Paris",  "2. London", "3. Berlin", "4. Rome"},
                        {"1. London",  "2. Berlin", "3. Paris", "4. Rome"},
                        {"1. Paris",  "2. London", "3. Rome", "4. Berlin"}};
String ans[] = {"A", "A", "B", "C"}
int melody[]={262, 196, 196, 220, 196, 0, 247, 262};
int noteDurations[]={4, 8, 8, 4, 4, 4, 4, 4};
int i;
int quesNum;
int buttonAPin= 1;
int buttonBPin= 6;
int buttonCPin= 7;
int buttonDPin= 9;
int buzzerPin = 8;
int score;
int Lost;
void setup() {
    Lost = 0;
    i = 0;
    score = 0;
    quesNum = 0;
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.autoscroll();
    lcd.print(Questions[quesNum]);
}

void loop() {
    i = i+1;
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0):
    int buttonStateA = digitalRead(buttonAPin);
    int buttonStateB = digitalRead(buttonBPin);
    int buttonStateC = digitalRead(buttonCPin);
    int buttonStateD = digitalRead(buttonDPin);
    if (buttonStateA == 1 && ans[quesNum] == "A") {
        score = score + 1;
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
    else if (buttonStateB == 1 && ans[quesNum] == "B") {
        score = score + 1;
    }
    else if (buttonStateC == 1 && ans[quesNum] == "C") {
        score = score + 1;
    }
    else if (buttonStateD == 1 && ans[quesNum] == "D") {
        score = score + 1;
    }
    else if (buttonStateA == 0 && buttonStateB == 0 && buttonStateC == 0 && buttonStateD == 0){
        continue;
    }
    else {
        score = 0;
        Lost = 1;
        lcd.print("YOU LOST");
    }
    lcd.setCursor(0,0);
    lcd.scrollDisplayLeft();
    delay(400);
    lcd.setCursor(0, 1);
    if (lost == 0){
        lcd.print(options[quesNum][i%4]);
    }
}
