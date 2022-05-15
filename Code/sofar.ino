#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int melody[]={262, 196, 196, 220, 196, 0, 247, 262};
String Questions[4] = {"1. What is the capital of India?", 
                      "2. What is the capital of France?", 
                      "3. What is the capital of Germany?", 
                      "4. What is the capital of Italy?"};
String options[4] = {"1. Delhi 2. Paris 3. Berlin 4. Rome",
                        "1. Paris 2. London 3. Berlin 4. Rome",
                        "1. London 2. Berlin 3. Paris 4. Rome",
                        "1. Paris 2. London 3. Rome 4. Berlin"};
String ans[4] = {"A", "A", "B", "C"};
int noteDurations[]={4, 8, 8, 4, 4, 4, 4, 4};
int ledPin = LED_BUILTIN;    // choose the pin for the LED
int input5Pin = 6;       // define push button input pins
int input4Pin = 7;
int input3Pin = 8;
int input2Pin = 9;
int buzzerPin = 10;
int score;
int Lost;
int optionNum;
int quesNum;
void setup()
{
  pinMode(ledPin, OUTPUT);   // declare LED as output
  pinMode(input5Pin, INPUT); // declare push button inputs
  pinMode(input4Pin, INPUT);
  pinMode(input3Pin, INPUT);
  pinMode(input2Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
    Lost = 0;
    optionNum = 0;
    score = 0;
    quesNum = 0;
    // set up the LCD's number of columns and rows:
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.print(Questions[quesNum]);
}

void loop()
{
  optionNum++;
//  digitalWrite(ledPin, LOW);
  for(int i=6 ; i<=9 ; i++)
    checkPush (i);
}

void checkPush(int pinNumber)
{
  lcd.scrollDisplayLeft();
  lcd.setCursor(0, 1);  
  lcd.print(options[quesNum]);  
  delay(400);
  int pushed = digitalRead(pinNumber);  // read input value
  if (pushed == HIGH) {// check if the input is HIGH (button released)
    digitalWrite(ledPin, LOW);  // turn LED OFF
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
  else
    digitalWrite(ledPin, HIGH);  // turn LED ON
}