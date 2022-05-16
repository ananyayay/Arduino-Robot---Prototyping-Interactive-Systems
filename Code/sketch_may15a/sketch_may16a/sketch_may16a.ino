#include <IRremote.h> // include the IRremote library
int IR_RECEIVE_PIN = 7;
long data = 0; 
int noteDurationsWin[]={4, 8, 8, 4, 4, 4, 4, 4};
int melodyWin[]={262, 196, 196, 220, 196, 0, 247, 262};
int buzzerPin = 6;
void setup() {
  Serial.begin(9600); // begin serial communication with a baud rate of 9600
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  pinMode(buzzerPin, OUTPUT);
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
void loop() {
  if (IrReceiver.decode()) {
    Serial.println("HELO");
    if (IrReceiver.decodedIRData.decodedRawData != 0) {
      data = IrReceiver.decodedIRData.decodedRawData;
      Serial.println(data);
    }
 
    if (data == -217252096){
        Serial.println("1, Red");
        PlayWin();
    }
    else if (data == -417792256){
        Serial.println("2, Orange");
        PlayWin();
    }
    else if (data == -1587609856){
        Serial.println("3, Yellow");
        PlayWin();
    }
    else if (data == -150405376){
        Serial.println("4, Green");
        PlayWin();
    }
    else if (data == -484638976){
        Serial.println("5, Blue");
        PlayWin();
    }
    else if (data == -1520763136){
        Serial.println("6, Intigo");
        PlayWin();
    }
    else if (data == -1119682816){
        Serial.println("7, Violet");
        PlayWin();
    }
    }
    IrReceiver.resume();
  }
