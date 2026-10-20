#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void NavigationMessage_MoveQueueEntries(char*,char*,char*,int);
// Original: arm9/main @ 0x02093A58; symbol: func_02093a58; size: 0x40.
extern "C" void NavigationMessage_SuspendActiveQueue(char* p){
    NavigationMessage_MoveQueueEntries(p,p,p+0x1a0,*(signed char*)(p+0x3cb));
    p[0x3cc]=p[0x3cb];
    p[0x3cb]=0;
    *(unsigned char*)(p+0x3cd)&=~4;
}
