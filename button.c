
/*----------------------------------------------------------------------------
    File name   : button.c
    Description : demonstrates on how to interface a button as a digital input
                  on the GPIO port

    
 
 ----------------------------------------------------------------------------*/
#include "NXP/iolpc2148.h"

void button_init(void)
{
  IO0DIR_bit.P0_14 = 0; //button port direction is input
}

