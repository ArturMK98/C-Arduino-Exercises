/**
 * Name: Artur Karolewski
 * Student Number: 17388976
 * Question 4: Serial monitor output
 */

const unsigned long SUPERLOOP_MS = 2000;
int unsigned gLoopNumber = 0;  // unsigned global variable (loops will never be negative)

void setup() {
 Serial.begin(9600);
}
void loop() {

 unsigned long onTime = millis();      // time in ms since board is on
 static unsigned int loopNumber = 0;   // static local variable that counts the number of loops
 unsigned int ordinaryLoopNumber = 0;  // ordinary local variable that counts the number of loops

 //adds 1 to each variable
 gLoopNumber++;
 loopNumber++;
 ordinaryLoopNumber++;

 //prints out the information to serial monitor
 Serial.print(onTime);
 Serial.print(" ms: ");
 Serial.print("Global variable = ");
 Serial.print(gLoopNumber);
 Serial.print(", ");
 Serial.print("Static variable = ");
 Serial.print(loopNumber);
 Serial.print(", ");
 Serial.print("Local variable = ");
 Serial.print(ordinaryLoopNumber);
 Serial.println();
 delay(SUPERLOOP_MS);
 
}
