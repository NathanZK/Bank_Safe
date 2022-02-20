/*
interface dc motor with port P1_29 using 5v coil relay

*/
#include "NXP/iolpc2148.h"
#include "DC_MOTOR.h"

void DC_MOTOR_init(void)
{
  IO0DIR_bit.P0_0 =0;
 //IO0DIR &=~(1<<0);      
 IO0DIR |=(1<<3)|(1<<2);  
 IO0PIN &= ~((1<<3)|(1<<2));  
 
}
void DC_MOTOR_OPEN(void)
{
 IO0PIN &= ~(1<<3);   //01
 IO0PIN |=(1<<2); 
}
void DC_MOTOR_CLOSE(void)
{
 IO0PIN &= ~(1<<2);   //10
 IO0PIN |=(1<<3); 
}
void DC_MOTOR_OFF(void)
{
  IO0PIN &= ~((1<<3)|(1<<2));  //00
}