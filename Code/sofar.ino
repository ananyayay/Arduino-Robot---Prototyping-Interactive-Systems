#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int melody[]={262, 196, 196, 220, 196, 0, 247, 262};
String Questions[4] = {"1. What is the capital of India?", 
                      "2. What is the capital of France?", 
                      "3. What is the capital of Germany?", 
                      "4. What is the capital of Italy?"};
String options[4] = {"1. Delhi 2. Paris 3. Berlin",
                        "1. Paris 2. London 3. Berlin",
                        "1. London 2. Berlin 3. Paris",
                        "1. Paris 2. London 3. Rome"};
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
int quesNum;

void setup()
{
  Serial.begin( 9600 );
  pinMode(ledPin, OUTPUT);   // declare LED as output
  pinMode(input5Pin, INPUT); // declare push button inputs
  pinMode(input4Pin, INPUT);
  pinMode(input3Pin, INPUT);
  pinMode(input2Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Lost = 0;
  score = 0;
  quesNum = 0;
  lcd.begin(16, 2);
  lcd.print(Questions[quesNum]);
  lcd.setCursor(0, 1);  
  lcd.print(options[quesNum]);
}

void loop()
{
  if (digitalRead(input2Pin) == HIGH){
    Serial.println("HELLOOOOO");
    lcd.setCursor(0, 0); 
    lcd.print("                                      ");
    lcd.print("SCORE");
    lcd.setCursor(0, 1); 
    lcd.print("                                      ");
    lcd.print(score);
  }
  if (digitalRead(input3Pin) == HIGH || digitalRead(input4Pin) == HIGH || digitalRead(input5Pin) == HIGH || digitalRead(input2Pin) == LOW){
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print(Questions[quesNum]);
    lcd.setCursor(0, 1);  
  lcd.print(options[quesNum]);
  }
  Serial.println(digitalRead(input3Pin));
  Serial.println(digitalRead(input4Pin));
  Serial.println(digitalRead(input5Pin));
  for(int i=6 ; i<=8 ; i++){
    checkPush(i);
  }
}

void checkPush(int pinNumber)
{
  lcd.scrollDisplayLeft();
  delay(400);
  int pushed = digitalRead(pinNumber);  // read input value
  if (pushed == HIGH) {// check if the input is HIGH (button released)
    Serial.println(pinNumber);
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