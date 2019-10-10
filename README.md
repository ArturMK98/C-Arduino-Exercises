# C-Arduino-Exercises (Update README)
My work from EE108R (Computing for Engineers)

## Assignment 1 (Grade UNKNOWN)
- [A1_BitsToBarLeds](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Assignment%201/A1_BitsToBarLeds/A1_BitsToBarLeds.ino): Each time the loop function runs the program executes the following steps:
    - Light Bar LEDs 1 and 2 only for 300ms and print the binary ledStates value that corresponds to these LEDs.
    - Light Bar LEDs 3, 5, and 7 only for 600ms and print the binary ledStates value that corresponds to these LEDs.
    - Blink Bar LEDs 9 and 10 on and off twice, on for 50 ms, off for 250 ms and print the binary ledStates value that corresponds to these LEDs.
    - Choose a random set of Bar LEDs (different each time the loop function runs), and blink those LEDs on and off 5 times, on for 10 ms, off for 140 ms. Print the binary ledStates value that corresponds to these LEDs.
    - Outputs each execution of the loop function giving information about the LED states.

## Assignment 2 (Grade 85%)
- [A2_SevenSegment](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Assignment%202/A2_SevenSegment/A2_SevenSegment.ino): A program that generates random numbers between 0-F (hex) inclusive and to display the corresponding digit on the 7-segment display by lighting the correct pattern of LEDs and works as follows:
    - Each time the loop function runs, generate a random number between 0x0 to 0xF inclusive.
    - Print this number to serial output and display the number on the 7-segment display.

- [A2_SevenSegmentAnimation](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Assignment%202/A2_SevenSegmentAnimation/A2_SevenSegmentAnimation.ino)(Extra credit question): A program that uses an array lookup table to create a simple [animation](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Assignment%202/MOV_1004.mp4) using the 7 segment display showing each pattern for approximately 150ms.

## Assignment 3 (Grade 95%)
- [A3_ClickArrays](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Assignment%203/A3_ClickArrays/A3_ClickArrays.ino): The program has 2 arrays and will operate as follows. Whenever SW1 is normally clicked the two arrays will be printed. When SW1 is long-clicked, array1 will be updated with random values. Whenever SW1 is very-long-clicked, array1 will be updated with zeros. Finally, whenever SW1 is double-clicked, the contents of array1 will be copied into array2. The contents of both arrays must be printed after any of the above changes takes place.

    Click guidelines:
    - Normal click: Pressed for less than 1 second.
    - Long click: Pressed for 1-3 seconds.
    - Very long click: Pressed for more than 3 seconds.
    - Double-click: Two complete clicks detected in less than 1 second.
 
- [A3_LIFO](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Assignment%203/A3_LIFO/A3_LIFO.ino): A program that implements a last-in-first-out buffer (using an array) and uses this  to dynamically add and later remove values from the end of the array.

    When SW1 is clicked:
    - Check if there are unused slots in the buffer
    - If there is space, generate a random number (any integer between 0 and +99 inclusive) and add it to the end of the buffer. Then print the new contents of the buffer. 
    - Otherwise (no space in the buffer), prints a message letting the user know that there is no space.
    
    Whenever SW2 is clicked:    
    -  Check if there are any used slots in the buffer.
    -  If there are elements in use, remove the last element (the one that had been most recently added) and print its value. Then print the new contents of the buffer.
    - Otherwise (no elements in use), print a message letting the user know that there is no elements in use.
     
## Assignment 4 (Grade UNKNOWN)
- [A4_AverageDirection](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Assignment%204/A4_AverageDirection/A4_AverageDirection.ino): This program reads direction keys (J, K, L, and I), calculate the resultant direction of the most recent 8 keys, and match that to a one of a limited set of compass directions.

## Lab 1 (Grade 90%)
- [Lab1_3_BlinkDaughterboard](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%201/Lab1_3_BlinkDaughterboard/Lab1_3_BlinkDaughterboard.ino): A modified blink program which blinks a daughterboardLED instead of an Arduino motherboard LED.

- [Question 4](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%201/Question4/Question4.ino): A program that prints the time in milliseconds (since the Arduino board was last reset) and the value of a global, static, and local variable to serial output, once every 2 seconds.

## Lab 2 (Grade 70%)
- [Lab2_1_NestedIf](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%202/Lab2_1_NestedIf/Lab2_1_NestedIf.ino): A program that loops every 100 ms checking SW1 and then lights LED1 or LED2 depending on how long SW1 has been pressed.

- [Lab2_2_WrapTutorial](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%202/Lab2_2_WrapTutorial/Lab2_2_WrapTutorial.ino): A program which wraps or resets a couter at a specified value.

- [Lab2_3_CascadedIf](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%202/Lab2_3_CascadedIf/Lab2_3_CascadedIf.ino): A program that increments a counter once per loop and lights a particular pattern of LED1 and LED2 according to the counter value.

## Lab 3 (Grade 90%)
- [Lab3_BarLedScan_1](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%203/Lab3_BarLedScan_1/Lab3_BarLedScan_1.ino): A program that prompts the user to click SW1, waits until SW1 is clicked, once clicked blinks BAR_LED_1 10 times and prints placeholder text to the serial monitor.

- [Lab3_BarLedScan_2](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%203/Lab3_BarLedScan_2/Lab3_BarLedScan_2.ino): Modified version of [Lab3_BarLedScan_1](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%203/Lab3_BarLedScan_1/Lab3_BarLedScan_1.ino) which skips to the next iteration if SW2 is pressed.

- [Lab3_BarLedScan_3](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%203/Lab3_BarLedScan_3/Lab3_BarLedScan_3.ino): Modified version of [Lab3_BarLedScan_2](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%203/Lab3_BarLedScan_2/Lab3_BarLedScan_2.ino) which replaces the placeholder text with a nested loop that scans over all the bar LEDs from 2 to 10 blinking each one on and off in succession (on for 100ms and off for 50ms).

- [Lab3_BarLedScan_4](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%203/Lab3_BarLedScan_4/Lab3_BarLedScan_4.ino): Modified version of [Lab3_BarLedScan_3](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%203/Lab3_BarLedScan_3/Lab3_BarLedScan_3.ino) that lets the user stop the bar LED scans immediately when the user presses SW1 in any way.

## Lab 4 (Grade 80%)
- [Lab4_PureFunctions](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%204/Lab4_PureFunctions/Lab4_PureFunctions.ino): A program that generates 4 random integers, p, q, r, and s, each between 0 and 100, prints each one, calculates the absolute difference between p & q as well as r & s and prints the result to the serial monitor.

- [Lab4_BlinkFunctions](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%204/Lab4_BlinkFunction/Lab4_BlinkFunction.ino): Each time the main loop executes in this program:
    - BarLED1 blinks once using a long pattern (1200ms on, 600ms off)
    - BarLED8 blinks three times using a short pattern (100ms on, 500ms off)
    - BarLED4 blinks twice using a medium pattern (500ms on, 700ms off) 
    - Information about BarLED and on/off pattern is printed out to the serial monitor

## Lab 5 (Grade 90%)
- [Lab5_BasicArrays](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%205/Lab5_BasicArray/Lab5_BasicArray.ino): Program that demonstrates declaring an array with initial values, iterating over an array to get the value of each element, and iterating over and array to set the value of each element.

- [Lab5_ArraysAndFunctions](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%205/Lab5_ArraysAndFunctions/Lab5_ArraysAndFunctions.ino): Modified version of [Lab5_BasicArrays](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%205/Lab5_BasicArray/Lab5_BasicArray.ino) that works the same way but uses functions.

## Lab 6 (Grade 50%)
- [Lab6_RectOutputParams](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%206/Lab6_RectOutputParams/Lab6_RectOutputParams.ino): A program that demonstrates the use of the address of operator and the dereference operator by using a function that calculates the area and perimeter of a rectangle given its length and width.

- [Lab6_AnalogInoutAndFifo](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%206/Lab6_AnalogInoutAndFifo/Lab6_AnalogInoutAndFifo.ino): A program that uses an array as a first-in-first-out (FIFO) buffer.

## Lab 7 (Grade 70%)
- [Lab7_BasicArrayPointers](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%207/Lab7_BasicArrayPointers/Lab7_BasicArrayPointers.ino): A program that demonstrates the use of pointer arithmetic by iterating through an array and printing out values.

- [Lab7_UpdateArrayPointerArithmetic](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%207/Lab7_UpdateArrayPointerArithmetic/Lab7_UpdateArrayPointerArithmetic.ino): A program that demonstrates the use of pointer arithmetic by modifying elements in an array. Whenever SW1 is clicked, the program does the following: 
   - Chooses a random position between 0 and length of array minus 2 and print this value.
   - Call updateElement to modify the array at that position.
   - Prints the updated array contents

## Lab 8 (Grade 90%)
- [Lab8_StructLineSlope](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%208/Lab8_StructLineSlope/Lab8_StructLineSlope.ino): A program that demonstrates the use of structure variables and accessing structure fields by calculating the slope of a line given two points x and y.

- [Lab8_PasswordGen](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%208/Lab8_PasswordGen/Lab8_PasswordGen.ino): A password generator program that can create a new random alphabetic word whenever a button is long-clicked and save it as the current password. Whenever the button is normally clicked the programme will print the current password without changing it.

## Lab Test 1 (Grade 90%)
- [LT1_BinaryInspector](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%20Test%201/LT1_BinaryInspector/LT1_BinaryInspector.ino): A program that represent 10 bit numbers using the bar LEDs on the Arduino board. 

## Other Files
The [EE108](https://github.com/ArturMK98/C-Arduino-Exercises/tree/master/_EE108) folder contains files required for all the exercises to work.
