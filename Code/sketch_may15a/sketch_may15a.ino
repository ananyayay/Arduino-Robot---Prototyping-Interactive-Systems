#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int melodyWin[]={262, 196, 196, 220, 196, 0, 247, 262};
int melodyLose[] = {262,294,330,349,392,880,988,523};
String Questions[4] = {"1. What is the capital of India?", 
                      "2. What is the capital of France?", 
                      "3. What is the capital of Germany?", 
                      "4. What is the capital of Italy?"};
String options[4] = {"1. Delhi 2. Paris 3. Berlin",
                        "1. Paris 2. London 3. Berlin",
                        "1. London 2. Berlin 3. Paris",
                        "1. Paris 2. London 3. Rome"};
String ans[4] = {"A", "A", "B", "C"};
int noteDurationsWin[]={4, 8, 8, 4, 4, 4, 4, 4};
int noteDurationsLose[] = {2,2,2,2,2,2,2,2};
int ledPin = LED_BUILTIN;    // choose the pin for the LED
int inputC = 6;       // define push button input pins
int inputB = 7;
int inputA = 8;
int ScoreButton = 9;
int buzzerPin = 10;
int score;
int Lost;
int quesNum;
int wonflag = 0;
int scorePressed = 0;
int clearFlag = 0;
void setup()
{
  Serial.begin( 9600 );
  pinMode(ledPin, OUTPUT);   // declare LED as output
  pinMode(inputC, INPUT); // declare push button inputs
  pinMode(inputB, INPUT);
  pinMode(inputA, INPUT);
  pinMode(ScoreButton, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Lost = 0;
  score = 0;
  quesNum = 0;
  WriteQuestion();
}

void loop()
{
  lcd.scrollDisplayLeft();
  delay(400);
  if (quesNum == 4){
    wonflag = 1;
    lcd.setCursor(0, 0); 
    lcd.print("YOU WIN WITH SCORE");
    lcd.setCursor(0, 1); 
    lcd.print("                        ");
    lcd.print(score);
  }
  if (digitalRead(ScoreButton) == HIGH && wonflag == 0){
    if (scorePressed == 1){
      WriteQuestion();
      scorePressed = 0;
      clearFlag = 0;
    }
    else{
      if (scorePressed == 0){
        scorePressed = 1;
      }
      if (clearFlag == 0){
        lcd.clear();
      }
      clearFlag = 1;
      lcd.setCursor(0, 0); 
      lcd.print("SCORE");
      lcd.setCursor(0, 1); 
      lcd.print(score);
    }
//    delay(10);
//    lcd.begin(16, 2);
//    lcd.setCursor(0, 0);
//    lcd.print(Questions[quesNum]);
//    lcd.setCursor(0, 1);  
//    lcd.print(options[quesNum]);
  }
  if (digitalRead(inputA) == HIGH && ans[quesNum] == "A" && wonflag == 0){
    clearFlag = 0;
    WriteQuestion();
    PlayWin();
    quesNum++;
    score++;
    WriteQuestion();
  }
  else if (digitalRead(inputB) == HIGH && ans[quesNum] == "B" && wonflag == 0){
    clearFlag = 0;
    WriteQuestion();
    PlayWin();
    quesNum++;
    score++;
    WriteQuestion();
  }
  else if (digitalRead(inputC) == HIGH && ans[quesNum] == "C" && wonflag == 0){
    clearFlag = 0;
    WriteQuestion();
    PlayWin();
    quesNum++;
    score++;
    WriteQuestion();
  }
  else if (wonflag == 0 && (digitalRead(inputA) == HIGH && ans[quesNum] != "A") || (digitalRead(inputB) == HIGH && ans[quesNum] != "B") || (digitalRead(inputC) == HIGH && ans[quesNum] != "C")){
    clearFlag = 0;
    WriteQuestion();
    PlayLose();
    quesNum = 0;
    score = 0;
    WriteQuestion();
  }
  Serial.println(digitalRead(inputA));
  Serial.println(digitalRead(inputB));
  Serial.println(digitalRead(inputC));
  for(int i=6 ; i<=8 ; i++){
    checkPush(i);
  }
}

void checkPush(int pinNumber)
{

  int pushed = digitalRead(pinNumber);  // read input value
  if (pushed == HIGH) {// check if the input is HIGH (button released)
    Serial.println(pinNumber);
    digitalWrite(ledPin, LOW);  // turn LED OFF
    PlayWin();
  }
  else
    digitalWrite(ledPin, HIGH);  // turn LED ON
}

void PlayWin(){
  for (int thisNote=0; thisNote <8; thisNote++){

    //to calculate the note duration, take one second. Divided by the note type
    int noteDuration = 1000 / noteDurationsWin [thisNote];
    tone(buzzerPin, melodyWin[thisNote], noteDuration);

    //to distinguish the notes, set a minimum time between them
    //the note's duration +30% seems to work well
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    //stop the tone playing
    noTone(8);
  }
}

void PlayLose(){
  for (int thisNote=0; thisNote <8; thisNote++){

    //to calculate the note duration, take one second. Divided by the note type
    int noteDuration = 1000 / noteDurationsLose [thisNote];
    tone(buzzerPin, melodyLose [thisNote], noteDuration);

    //to distinguish the notes, set a minimum time between them
    //the note's duration +30% seems to work well
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    //stop the tone playing
    noTone(8);
  }
}

void WriteQuestion(){
  lcd.begin(16, 2);
  lcd.print(Questions[quesNum]);
  lcd.setCursor(0, 1);  
  lcd.print(options[quesNum]);
}
