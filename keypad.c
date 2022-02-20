#include "NXP/iolpc2148.h"
#include "keypad.h"
 
void keypad_init(void)
{
 //make the rows out put p0.20,p0.21,p0.22,p0.23,
  
  IO0DIR|=(1<<20)|(1<<21)|(1<<22)|(1<<23);
  IO0SET=0xF00000;  //set the rows high 
 
}
char  scanKey(void)
{
  char keys[4][3]={ {'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'},
                    {'*','0','#'}};
  int column=0,row=0;
  int clr=20,rw=0;
  IO0SET=0xF00000;  //set the rows high 
 
  while(isButPressed)
  {
    if(col0)column=0;
    if(col1)column=1;
    if(col2)column=2;
    
    
    IO0CLR=1<<clr;   //determine the row by making each 0 and see the difference
    row=rw;
    clr++;
    rw++;
    
  }
  IO0SET=0xF00000;  //set the rows high when the meyhod called again
  return  keys[row][column];
}