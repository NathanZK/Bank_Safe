#include "NXP/iolpc2124.h"
#include "delay.h"

void delay_ms(unsigned int millis)
{
  T0TCR_bit.CE=1;//enable timer
  for(int i=0;i<millis;i++)
  {
    //l ms delay
    T0TC = 0;//clear timer
    while(T0TC<48000);//wait for 1ms, assuming 48MHz CPU clock
  }
  
}