/**
 *  Student Name: Artur Karolewski
 *  Student Number: 17388976
 *  Lab Test: 1
 * 
 *    This program works as follows:
 *    - When switch 1 is long-clicked a random 10 bit number is generated,
 *      the value of this number is printed out to the screen in decimal, hex
 *      and binary. The number is represented using the barLed on the daughterboard
 *      where switched on bars represent 1s and switched off ones represent 0s.
 *    - When switch 2 is clicked it increases the value of the index and flashes the
 *      the bar led at that index 3 times. If switch 2 is long clicked then it decreases
 *      the value of the index and also flashes the bar led at that index 3 times.
 *    - If switch 1 is clicked then the bar led at the current index flashes 3 times
 *      without increasing the index.
 *  
 *  Still to do:
 *  - Get the potentiometer to work so brightness of barLeds can be changed
 */


#include <ee108.h>

// Global variables
const int FLASH_MS = 60;

// Function declerations
void setupBarLeds();
void setupLeds();
void mapBits();
void flashBarLed();
void ledOnOff();

// Top level functions
void setup() {
  
  Serial.begin(9600);
  Serial.println("====== LT1_BinaryInspector Starting ========");

  setupBarLeds();
  setupLeds();

}

void loop() {
  
  int sw1Event = readSwitchEvent(sw1Object);
  int sw2Event = readSwitchEvent(sw2Object);
  int inspectionNumber;
  static int currentBit;
  unsigned static int bitIndex;
  
  if(sw1Event == SW_CLICK_LONG){    // Checks if switch 1 is long clicked

    inspectionNumber = random(1024);
    bitIndex = 0;
    currentBit = bitRead(inspectionNumber, bitIndex);
    
    Serial.print("Number generated: ");
    Serial.println(inspectionNumber);
    Serial.print("In hexadecimal: ");
    Serial.println(inspectionNumber, HEX);
    Serial.print("In binary: ");
    Serial.println(inspectionNumber, BIN);
    Serial.println("---------------------------");
    
    mapBits(inspectionNumber);
  }

  if(sw1Event == SW_CLICK){   // Checks if switch 1 is clicked

    if(bitIndex == 0){

      flashBarLed(bitIndex);
      
    }else{

      flashBarLed(bitIndex -1);
    }

    if(currentBit == 0){

      digitalWrite(BAR_LED_1_PIN + (bitIndex -1), LOW);
    }
  }

  if(sw2Event == SW_CLICK){   // Checks if switch 2 is clicked

    if(bitIndex > 9){   // If > 9 then at barLed 10 and must go back to index 0

      bitIndex = 0;
    }

    currentBit = bitRead(inspectionNumber, bitIndex);

    ledOnOff(bitRead(inspectionNumber, bitIndex));
    
    Serial.print("Current bit index: ");
    Serial.println(bitIndex);
    Serial.print("Value of current bit: ");
    Serial.println(currentBit);
    Serial.println("---------------------------");

    flashBarLed(bitIndex);

    if(currentBit == 0){

      digitalWrite(BAR_LED_1_PIN + bitIndex, LOW);
    }
    
    bitIndex++;
  }

  if (sw2Event == SW_CLICK_LONG){   // Checks if switch 2 is long clicked

    if (bitIndex == 65535){   // If at 65535 then < 0 because unsigned int

      bitIndex = 9;   // Reset back to index 9
    }

    currentBit = bitRead(inspectionNumber, bitIndex);

    ledOnOff(bitRead(inspectionNumber, bitIndex));
    
    Serial.print("Current bit index: ");
    Serial.println(bitIndex);
    Serial.print("Value of current bit: ");
    Serial.println(currentBit);
    Serial.println("---------------------------");

    flashBarLed(bitIndex);
    
    if (currentBit == 0){

      digitalWrite(BAR_LED_1_PIN + bitIndex, LOW);
    }

    bitIndex--;
  }
}

// Helper functions
void setupBarLeds(void){    // Sets up barLed

  int ledIndex;

  for (ledIndex = 0; ledIndex < NUM_BAR_LEDS; ledIndex++){

    pinMode(BAR_LED_1_PIN + ledIndex, OUTPUT);
  }
}

void setupLeds(void){   // Sets up leds
  
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT); 
}

void mapBits(int num){    // Maps bits to the bar led 
                          // If 1 then barLed on if 0 then off
  int x;

  for (int index = 9; index >= 0; index--){

    x = bitRead(num, index);
    
    if (x == 1){

      digitalWrite(BAR_LED_1_PIN + index, HIGH);
      
    } else {

      digitalWrite(BAR_LED_1_PIN + index, LOW);
    }
  }
}

void flashBarLed(int index){    // Function that flashes required bar led 3 times

  for (int i = 3; i > 0; i--){

      digitalWrite(BAR_LED_1_PIN + index, LOW);
      delay(FLASH_MS);
      digitalWrite(BAR_LED_1_PIN + index, HIGH);
      delay(FLASH_MS);
    }
}

void ledOnOff(int x){   // Switches the led on or off depending if bit
                        // bit value is 1 or 0
  if(x == 1){

      digitalWrite(LED1_PIN, HIGH);
      
    } else {

      digitalWrite(LED1_PIN, LOW);
    }
  
}
