# C-Arduino-Exercises (Update README)
My work from EE108R (Computing for Engineers)

## Assignment 1 (Grade UNKNOWN)
- [A1_BitsToBarLeds](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Assignment%201/A1_BitsToBarLeds/A1_BitsToBarLeds.ino): Each time the loop function runs the program executes the following steps:
    - Light Bar LEDs 1 and 2 only for 300ms and print the binary ledStates value that corresponds to these LEDs 
    - Light Bar LEDs 3, 5, and 7 only for 600ms and print the binary ledStates value that corresponds to these LEDs 
    - Blink Bar LEDs 9 and 10 on and off twice, on for 50 ms, off for 250 ms and print the binary ledStates value that corresponds to these LEDs
    - Choose a random set of Bar LEDs (different each time the loop function runs), and blink those LEDs on and off 5 times, on for 10 ms, off for 140 ms. Print the binary ledStates value that corresponds to these LEDs 
    - Outputs each execution of the loop function giving information about the LED states.

## Assignment 2 (Grade 85%)
- [A2_SevenSegment](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Assignment%202/A2_SevenSegment/A2_SevenSegment.ino): A program that generates random numbers between 0-F (hex) inclusive and to display the corresponding digit on the 7-segment display by lighting the correct pattern of LEDs and works as follows:
    - Each time the loop function runs, generate a random number between 0x0 to 0xF inclusive.
    - Print this number to serial output and display the number on the 7-segment display

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
- [A4_AverageDirection](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Assignment%204/A4_AverageDirection/A4_AverageDirection.ino): This program reads direction keys (J, K, L, and I), calculate the resultant direction of the most recent 8 keys, and match that to a one of a limited set of compass directions. These are 

## Lab 1 (Grade 90%)
- [Lab1_3_BlinkDaughterboard](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%201/Lab1_3_BlinkDaughterboard/Lab1_3_BlinkDaughterboard.ino): A modified blink program which blinks a daughterboardLED instead of an Arduino motherboard LED.

- [Question 4](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%201/Question4/Question4.ino): A program that prints the time in milliseconds (since the Arduino board was last reset) and the value of a global, static, and local variable to serial output, once every 2 seconds.

## Lab 2 (Grade 70%)
