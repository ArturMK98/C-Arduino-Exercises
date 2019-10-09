/**
 * Header file with common constants and functions required for EE108 daughterboard
 * used with Arduino Uno.
 */

#ifndef __EE108_CONSTANTS_H // prevent multiple inclusion
#define __EE108_CONSTANTS_H
 
#include <Arduino.h>

// Analog input pins used by daughterboard

#define POT_PIN				A0
#define AUDIO_IN_PIN		A1
#define TEMP_SENSOR_PIN		A2
#define LDR_PIN				A2

// digital switch inputs

#define SW1_PIN		A5
#define SW2_PIN		A4

// active (pressed) or inactive (not pressed) for active-low switches
#define SW_ACTIVE	LOW
#define SW_INACTIVE	HIGH
 
// ordinary LEDs

// red
#define LED1_PIN		A3
// green
#define LED2_PIN		2

// Bar LED

#define NUM_BAR_LEDS	10
 
#define BAR_LED_1_PIN	3
#define BAR_LED_2_PIN	4
#define BAR_LED_3_PIN	5
#define BAR_LED_4_PIN	6
#define BAR_LED_5_PIN	7
#define BAR_LED_6_PIN	8
#define BAR_LED_7_PIN	9
#define BAR_LED_8_PIN	10
#define BAR_LED_9_PIN	11
#define BAR_LED_10_PIN	12

// 7-segment LEDs

#define SEG_DP_PIN	12
#define SEG_A_PIN	11
#define SEG_B_PIN	10
#define SEG_C_PIN	9
#define SEG_D_PIN	8
#define SEG_E_PIN	7
#define SEG_F_PIN	6
#define SEG_G_PIN	5

// individual bit values (useful for OR'ing together to create a bit pattern)
// e.g. the following means that someVar holds the binary value: 1000 1000 0000 0011
// someVar = BIT15 | BIT11 | BIT1 | BIT0; 

#define BIT0	0x1
#define BIT1	0x2
#define BIT2	0x4
#define BIT3	0x8
#define BIT4	0x10
#define BIT5	0x20
#define BIT6	0x40
#define BIT7	0x80
#define BIT8	0x100
#define BIT9	0x200
#define BIT10	0x400
#define BIT11	0x800
#define BIT12	0x1000
#define BIT13	0x2000
#define BIT14	0x4000
#define BIT15	0x8000

#endif // __EE108_CONSTANTS_H