#include <globaldefs.h>
ARM
// Original: arm9/ov025 @ 0x021ED35C; symbol: func_ov025_021ed35c; size: 0x24.
// Clears the observed state bytes and halfwords at offsets 0x150 through 0x15e.
extern "C" void Combat_ClearPendingAndActiveMessages(unsigned char* self) {
 *(unsigned short*)(self+0x15e)=0;
 self[0x150]=0;
 *(unsigned short*)(self+0x152)=0;
 *(unsigned short*)(self+0x154)=0;
 self[0x151]=0;
 *(unsigned short*)(self+0x15c)=0;
}
