#include <IRremote.h>  //including infrared remote header file     
int RECV_PIN = 7; // the pin where you connect the output pin of IR sensor     
IRrecv irrecv(RECV_PIN);     
decode_results results;     
void setup() {     
Serial.begin(9600);     
irrecv.enableIRIn();     
}  
void loop() {     
if (irrecv.decodedIRData.command){     
 int results.value = results;// Results of decoding are stored in result.value     
 Serial.println(" ");     
 Serial.print("Code: ");     
 Serial.println(results.value); //prints the value a a button press     
 Serial.println(" ");     
 irrecv.resume(); // Restart the ISR state machine and Receive the next value     
}   
}
