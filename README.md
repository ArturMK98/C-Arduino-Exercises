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

## Assignment 3


## Lab 1 (Grade 90%)
- [Lab1_3_BlinkDaughterboard](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%201/Lab1_3_BlinkDaughterboard/Lab1_3_BlinkDaughterboard.ino): A modified blink program which blinks a daughterboardLED instead of an Arduino motherboard LED.

- [Question 4](https://github.com/ArturMK98/C-Arduino-Exercises/blob/master/Lab%201/Question4/Question4.ino): A program that prints the time in milliseconds (since the Arduino board was last reset) and the value of a global, static, and local variable to serial output, once every 2 seconds.

## Lab 2 (Grade 70%)
