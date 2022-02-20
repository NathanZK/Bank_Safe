#include "NXP/iolpc2148.h"
#include "keypad.h"
#include "system.h"
#include "delay.h"
#include "LCD.h"
#include "DC_MOTOR.h"
#include "led.h"
void main()
{ 
  
  clock_init();
  keypad_init();
  LCD_init();
  DC_MOTOR_init();
  LED_init();
  
  
  char passkey[6]={'1','2','3','4','5','6'}; //Safe password
  char input[6]={'0','0','0','0','0','0'};  //input from user initialized to zero
  char button;
  int count;
  
  IO0CLR_bit.P0_10 = 1;
  
 
start:           //start mode
  count=0;
  
  LCD_WriteString("WELCOME TO");
  LCD_Newline();
  LCD_WriteString("AAiT BANK SAFE!");
  delay_ms(20); //wait some time
  
  
  while(1)
  {
  
    LCD_Clear();
    LCD_WriteString("ENTER PASSWORD");
    LCD_Newline();
    
pwin:        //pwin mode
    LCD_Newline();
    char flag=1;   //input status initialy correct
    int passlen=0;  // password length
    while(!isButPressed);  //wait until the button pressed
    while(passlen<6 && isButPressed)   //passkey length =6
    {
      button=scanKey();  //which button is pressed
      LCD_WriteChar(button);  //print the button
      input[passlen]=button;  //store the enterd password
      passlen++;
      delay_ms(100);  //button debounce time
      if(passlen==6)break; //when finished break
      while(!isButPressed);  //wait until the next button pressed
    }
    //check the input and pw
    for(int j=0;j<6;j++)
    {
        if(passkey[j]!=input[j])
        {
          flag=0; // if mismatched set flag= 0 and break 
          break;   
        }
            
    }
    if(flag==0)    //if the input didnt matched the passkey
    {
     count++;  //count the trial
      //check the trial
      if(count==3)
      {
        
       
        while(1)
        {
        LED_ON();          //turn on LED
        delay(250000);     //wait ~250ms
        LED_OFF();         //teurn off LED
        delay(250000);     //wait ~25ms
        LCD_Clear();
        LCD_WriteString("INTRUDER_ALERT!");
        }
        LCD_Clear();
        goto start;
      }
      else
      {
       LCD_Clear();
       LCD_WriteString("TRY AGAIN");
        goto pwin;   //take passkey again
      }
    }
    else          //if the input matched
    { 
      
opensafe:
      IO0CLR_bit.P0_9 = 1;
      IO0SET_bit.P0_10 = 1;
      LCD_Clear();
      LCD_WriteString("OPENING SAFE..."); 
      DC_MOTOR_OPEN();
      delay_ms(500);   //wait for some time to open safe
      DC_MOTOR_OFF();
      LCD_Newline();
      LCD_WriteString("SAFE OPENED!");
      delay_ms(1000);  //wait for some time
      LCD_Clear();
      LCD_WriteString("CLOSING SAFE");                //close the door
      DC_MOTOR_CLOSE();
      delay_ms(500);   //wait for some time  (time to close door t)just for simulatiion
      DC_MOTOR_OFF();
      while(1){
        LCD_Clear();
        LCD_WriteString("SAFE IS ");
        LCD_Newline();
        LCD_WriteString("NOT CLOSED");
        DC_MOTOR_CLOSE();
        
        LED_ON();          //turn on LED
        delay(250000);     //wait ~250ms
        LED_OFF();         //teurn off LED
        delay(250000);     //wait ~25ms
     }
    
     DC_MOTOR_CLOSE();   
     delay_ms(50);   //wait for some time just for simulatiion
     DC_MOTOR_OFF();
      LCD_Newline();
      LCD_WriteString("Safe Closed");
      delay_ms(100);  //wait for some time  //just for simulation
      goto start;  //goto the start mode
    }
    
   
  
 
  }// end while(1)  
  
}// end main