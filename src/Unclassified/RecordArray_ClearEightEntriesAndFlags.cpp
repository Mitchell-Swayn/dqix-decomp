#include <globaldefs.h>
#pragma optimization_level 2
ARM
#pragma optimize_for_size off
extern "C" void ClearFourBytes_Main020E303C(void*);
// Original: arm9/main @ 0x020E3004; symbol: func_020e3004; size: 0x38.
extern "C" void RecordArray_ClearEightEntriesAndFlags(char* p){char* flags=p+32;int i=0;while(i<8){ClearFourBytes_Main020E303C(p);*flags=0;i++;p+=4;flags++;}}
