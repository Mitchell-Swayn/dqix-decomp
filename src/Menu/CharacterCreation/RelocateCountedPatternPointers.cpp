#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma opt_arithtransformation off
#pragma always_inline on
static inline unsigned RelocatePatternPointer(unsigned* state,const char* pointer,const char* origin) {
 int offset=pointer-origin;
 bool invalid=true;
 if(offset!=-1 && state[2])invalid=false;
 if(invalid)return 0;
 return state[2]+offset;
}
// Original: arm9/ov009 @ 0x0218A420; symbol: func_ov009_0218a420; size: 0x64.
// Rebases count-byte-selected pattern pointers against state word8, mapping absent offsets to null.
extern "C" int RelocateCountedPatternPointers(unsigned* state,unsigned* record) {
 for(int i=0;i<*(unsigned char*)((char*)record+0x1e);i++)record[i]=RelocatePatternPointer(state,(const char*)record[i],0);
 return 1;
}
