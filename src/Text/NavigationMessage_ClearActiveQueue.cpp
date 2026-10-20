#include <globaldefs.h>
extern "C" {
void NavigationMessage_ClearEntry(void *);
// Original: arm9/main @ 0x02093A14; symbol: func_02093a14; size: 0x44.
void NavigationMessage_ClearActiveQueue(unsigned char *p){for(unsigned char i=0;i<8;i++)NavigationMessage_ClearEntry(p+i*52);p[0x3cb]=0;p[0x3cd]&=~4;}
}
