#include <globaldefs.h>
ARM
extern "C" void Ssl_BufferIncomingFragments(void*);
// Original: arm9/ov031 @ 0x0220A800; symbol: RefreshStateAndReadCounterDifference; size: 0x7c.
// Refreshes inactive state and returns the difference of counters 828 and 82c.
extern "C" int Ssl_GetAvailableApplicationDataLength(char *self) {
 char *state=*(char**)(self+12);
 if(!*(int*)(state+0x824) || !*(unsigned char*)(state+0x456)) Ssl_BufferIncomingFragments(self);
 if(*(int*)(state+0x824) && *(unsigned char*)(state+0x456)) return *(int*)(state+0x828)-*(int*)(state+0x82c);
 if(!*(int*)(state+0x824) && (*(unsigned char*)(self+8)!=4 || *(unsigned char*)(state+0x455)==9)) return -1;
 return 0;
}
