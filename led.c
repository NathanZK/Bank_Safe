/*--------------------------------------------------------------
 File:      led.c
 Purpose:   To control the LED connected to P0.8
 Compiler:  IAR EW 5.5
 Processor: Philips LPC2148 with ARM7TDMI-s Core
----------------------------------------------------------------*/

#include "NXP/iolpc2148.h"
#include "led.h"

// initialize led port (PIO)
void LED_init(void) 
{
  IO0DIR_bit.P0_8 = 1;    // Make Port P0.8 output---this is where LED is connected
  IO0SET_bit.P0_8 = 1;    // turn off led  --- see schematic on Proteus how LED is connected
  
  IO0DIR_bit.P0_9 = 1;    // Make Port P0.9 output---this is where LED is connected
  IO0SET_bit.P0_9 = 1;    // turn off led  --- see schematic on Proteus how LED is connected
  
  IO0DIR_bit.P0_10 = 1;    // Make Port P0.10 output---this is where LED is connected
  IO0SET_bit.P0_10 = 1;    // turn off led  --- see schematic on Proteus how LED is connected
}

// turn on led 
void LED_ON(void) 
{
  IO0CLR_bit.P0_8 = 1;    //turn on the LED (clear the led pin to logic '0')
}

// turn off led 
void LED_OFF(void) 
{
  IO0SET_bit.P0_8 = 1;    //turn off LED (set the led pin to logic '1')
}

