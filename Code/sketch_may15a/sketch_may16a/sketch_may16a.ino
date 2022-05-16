/*      
*  IR read codes     
*  by Hanie kiani     
*  https://electropeak.com/learn/        
*/     
#include <IRremote.h>  //including infrared remote header file     
int RECV_PIN = 13; // the pin where you connect the output pin of IR sensor     
IRrecv irrecv(RECV_PIN);     
decode_results results;     
void setup()     
{     
Serial.begin(9600);     
irrecv.enableIRIn();     
}
void loop() {     
//  Serial.println("HEre");
if (irrecv.decode(&results)){     
 Serial.println(" ");     
 Serial.print("Code: ");     
 Serial.println(results.value, HEX); //prints the value a a button press     
 Serial.println(" ");     
 irrecv.resume(); // Restart the ISR state machine and Receive the next value     
}   
}
