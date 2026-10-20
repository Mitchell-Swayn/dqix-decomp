#include <globaldefs.h>
ARM
extern "C" int Util_TestSplitWordBit(unsigned long long*,unsigned int);
// Original: arm9/ov000 @ 0x02159F7C; symbol: func_ov000_02159f7c; size: 0x88.
extern "C" int Util_TestSelectedSplitWordFlags(void*,unsigned long long* p){
 if((*p & 0x20ULL) || (*p & 0x40ULL) || (*p & 0x200ULL) || (*p & 0x400ULL) || (*p & 0x1000ULL) || Util_TestSplitWordBit(p,38))return 1;
 return 0;
}
