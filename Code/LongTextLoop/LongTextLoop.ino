#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);          // select the pins used on the LCD panel

void setup(){
    lcd.begin(16, 2);                                 // set up a 2x16 character display
    lcd.print("Hello World!");                       // print a message to the LCD
    lcd.setCursor(0, 1);                             // set the cursor to column 0, line 1
    lcd.print("Hello World!");                       // print a message to the LCD
}

void loop(){
  // Scroll Text
    lcd.scrollDisplayLeft();                           // scroll the text one space to the left
    delay(500);                                       // wait 500ms
}
