#include "globaldefs.h"
#pragma optimize_for_size off
ARM
struct Entry{int words[13];};extern "C" void NavigationMessage_ClearEntry(Entry*);extern "C" void NavigationMessage_CopyEntry(Entry*,Entry*);
// Original: arm9/main @ 0x02093AD8; symbol: func_02093ad8; size: 0x7C.
extern "C" void NavigationMessage_MoveQueueEntries(void*,Entry*src,Entry*dst,int count){for(int i=0;i<8;i++)NavigationMessage_ClearEntry(dst+i);for(int i=0;i<count;i++)NavigationMessage_CopyEntry(dst+i,src+i);for(int i=0;i<8;i++)NavigationMessage_ClearEntry(src+i);}
