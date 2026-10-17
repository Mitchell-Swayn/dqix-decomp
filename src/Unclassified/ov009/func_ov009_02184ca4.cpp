#include <globaldefs.h>
ARM
struct UpdateState { char unknown0[0xc58]; signed char phase; char unknown1[0x143]; unsigned flags; };
extern "C" void func_ov009_02184e58(UpdateState*);
extern "C" void ResetEachIndexedEntryResource(void*),func_0204b088(void*,int);
extern "C" void Graphics_RebuildAlignedRecordDetailText(void*),func_ov023_021d9d34(void*),func_ov023_021d9e60(void*),func_ov023_021da1dc(void*);
// Original: arm9/ov009 @ 0x02184CA4; symbol: func_ov009_02184ca4; size: 0xCC.
extern "C" void func_ov009_02184ca4(UpdateState* state) {
 func_ov009_02184e58(state);signed char phase=state->phase;
 if(phase==0 || phase==12) return;if(state->flags&0x80) return;
 ResetEachIndexedEntryResource((char*)state+0x1f8);ResetEachIndexedEntryResource((char*)state+0x2b4);
 if(state->flags&0x1000) {func_0204b088((char*)state+0x158,0);state->flags&=~0x1000;}
 if(state->flags&0x2000) {func_0204b088((char*)state+0x1b8,0);if((unsigned char)(signed char)(phase-8)<=1)func_0204b088((char*)state+0x198,0);state->flags&=~0x2000;}
 Graphics_RebuildAlignedRecordDetailText(state);func_ov023_021d9d34(state);func_ov023_021d9e60(state);func_ov023_021da1dc(state);
}
