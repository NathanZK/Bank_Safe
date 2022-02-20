/*--------------------------------------------------------------
 File:      led.h
 Purpose:   header file for the led driver
 Compiler:  IAR EW 5.5
 MCU:       Philips LPC2148 with ARM7TDMI-s Core
----------------------------------------------------------------*/

/*---- Function prototypes ------- */

// init led port
void LED_init(void);

// turn on led 
void LED_ON(void);

// turn off led 
void LED_OFF(void);


