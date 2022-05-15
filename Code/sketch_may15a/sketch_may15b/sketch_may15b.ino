//Michael Klements
//The DIY Life
//17 May 2019 
int melody[]={262, 196, 196, 220, 196, 0, 247, 262};
int noteDurations[]={4, 8, 8, 4, 4, 4, 4, 4};
int ledPin = LED_BUILTIN;    // choose the pin for the LED
int input5Pin = 6;       // define push button input pins
int input4Pin = 7;
int input3Pin = 8;
int input2Pin = 9;
int buzzerPin = 10;
void setup()
{
  pinMode(ledPin, OUTPUT);   // declare LED as output
  pinMode(input5Pin, INPUT); // declare push button inputs
  pinMode(input4Pin, INPUT);
  pinMode(input3Pin, INPUT);
  pinMode(input2Pin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
//  digitalWrite(ledPin, LOW);
  for(int i=6 ; i<=9 ; i++)
    checkPush (i);
}

void checkPush(int pinNumber)
{
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
