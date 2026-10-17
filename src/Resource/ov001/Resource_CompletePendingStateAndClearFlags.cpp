#include <globaldefs.h>
#include <Resource/GameResources.h>
ARM
struct Object;
extern "C" Object data_02109bf4;
extern "C" int Object_ReadWordAtOffsetB0(Object*);
extern "C" void CompletePendingObjectStateAndClearPendingId(Object*);
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" void ClearWordAtOffset4MaskedBits(int,unsigned int);
extern "C" void Flags_ClearWordMask(unsigned int*,unsigned int);
// Original: arm9/ov001 @ 0x02156B20; symbol: func_ov001_02156b20; size: 0x80.
extern "C" void Resource_CompletePendingStateAndClearFlags() {
 GameResources* res=GameResources_GetInstance();
 if(Object_ReadWordAtOffsetB0(&data_02109bf4)==2) CompletePendingObjectStateAndClearPendingId(&data_02109bf4);
 if(*(unsigned short*)ReadGlobalValueAt020FB3F0()!=10000) ClearWordAtOffset4MaskedBits((int)res,4);
 ClearWordAtOffset4MaskedBits((int)res,0x40);
 ClearWordAtOffset4MaskedBits((int)res,0x10);
 ClearWordAtOffset4MaskedBits((int)res,2);
 Flags_ClearWordMask((unsigned int*)res,4);
}
