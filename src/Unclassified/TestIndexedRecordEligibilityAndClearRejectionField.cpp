#include <globaldefs.h>
#pragma opt_common_subs off

extern "C" {
ARM void* ReadGlobalValueAt02108844(); int ReadNonnegativeIndexedBit(void*,void*,int);
// Original: arm9/main @ 0x02023A9C; symbol: func_02023a9c; size: 0x70.
 int TestIndexedRecordEligibilityAndClearRejectionField(unsigned char* self,int index) { unsigned char* state=(unsigned char*)ReadGlobalValueAt02108844(); int offset=index*28; unsigned char* entry=self+offset; if(*(unsigned short*)(entry+1932)==0)return 0; if(*(unsigned short*)(entry+1930)==0 && ReadNonnegativeIndexedBit(state,state+140,*(unsigned short*)(entry+1924)+530)) { *(unsigned short*)(self+offset+1934)=0; return 0; }return 1; }
}
