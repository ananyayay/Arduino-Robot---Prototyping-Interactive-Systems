#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);          // select the pins used on the LCD panel
String myStrings[] = {"1. 8th March",  "2. 21st April", "3. 25th December", "4. 1st January"};
int i;
void setup() {
  i = 0;
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.autoscroll();
  lcd.print("Women's Day is Celebrated on?");
}

void loop() {
  i = i+1;
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0,0);
  lcd.scrollDisplayLeft();
  delay(400);
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(myStrings[i%4]);
}
