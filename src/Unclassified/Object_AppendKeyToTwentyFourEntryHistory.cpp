#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02099554; symbol: func_02099554; size: 0x5C.
extern "C" void Object_AppendKeyToTwentyFourEntryHistory(unsigned short* p,unsigned key){for(int i=0;i<24;i++){if(!p[i]){p[i]=key;return;}}for(int i=0;i<23;i++)p[i]=p[i+1];p[23]=key;}
