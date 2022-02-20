
#define   col0   IO0PIN_bit.P0_19 
#define   col1   IO0PIN_bit.P0_18
#define   col2   IO0PIN_bit.P0_17

#define   ButtonPressed     scanKey()
#define   isButPressed     (col0 || col1 || col2)
char scanKey(void);
void keypad_init(void);