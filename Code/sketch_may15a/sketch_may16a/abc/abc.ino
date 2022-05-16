/*
  IR Receiver Demonstration 1
  IR-Rcv-Demo1.ino
  Demonstrates IR codes with IR Receiver
  Displays results on Serial Monitor

  DroneBot Workshop 2017
  http://dronebotworkshop.com
*/
#include <IRremote.h>
#define Button1 0xFF18E7
#define Button2 0xFF38C7
// Include IR Remote Li;brary by Ken Shirriff
int noteDurationsWin[]={4, 8, 8, 4, 4, 4, 4, 4};
int melodyWin[]={262, 196, 196, 220, 196, 0, 247, 262};
// Define sensor pin
const int RECV_PIN = 7;
uint32_t Previous;
// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;
int buzzerPin = 6;

void setup(){
  // Serial Monitor @ 9600 baud
  Serial.begin(9600);
  // Enable the IR Receiver
  irrecv.enableIRIn();
//  Previous = 0;
}

void loop(){
  if (irrecv.decode(&results)){
        PlayWin()
        irrecv.resume();
  }
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
