#include <globaldefs.h>
ARM
extern "C" {void NavigationMessage_MoveQueueEntries(void*,void*,void*,int);
// Original: arm9/main @ 0x02093A98; symbol: func_02093a98; size: 0x40.
void NavigationMessage_RestoreSuspendedQueue(unsigned char* p){NavigationMessage_MoveQueueEntries(p,p+0x1a0,p,*(signed char*)(p+0x3cc));p[0x3cb]=*(signed char*)(p+0x3cc);p[0x3cc]=0;p[0x3cd]&=~4;}}
