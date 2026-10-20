#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0215C300; symbol: Church_DecrementDialogDelay; size: 0x2C.
// Subtracts the amount when the signed counter exceeds it, otherwise clears the counter.
extern "C" bool Church_DecrementDialogDelay(unsigned char* self,int amount) {
 if(*(int*)(self+0x598)>amount) { *(int*)(self+0x598)-=amount; }
 else { *(int*)(self+0x598)=0; return false; }
 return true;
}
