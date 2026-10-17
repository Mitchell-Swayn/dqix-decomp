// Original field/callee argument semantics reviewed; absolute values here are hardware MMIO.
#include <globaldefs.h>
#include <Resource/Script.h>
ARM
#pragma force_active on
struct Bits{unsigned char a:1,b:1,c:6;};extern "C" {void* memcpy(void*,const void*,unsigned);int func_0202cd50(void*,void*,unsigned short);extern char Object_PrepareNameAndSubmitConnectionRecord[],data_020e73b4[];void ClearField18Flag10AndBytes7BAnd9E(void*);void ClearRecordWordsAndByteFlags(void*);int AreWordFlags80039Clear(void*);void Object_AllocateFortyFourByteEntriesAndInvalidateKeys(void*,void*,unsigned short);void AllocateSixtyFourByteRecordArrayAndResetCount(void*,void*,short);extern void* data_02108da8[],*data_02108efc[];}
#pragma optimization_level 4
// Original: arm9/main @ 0x02088CCC; symbol: func_02088ccc; size: 0x28.
extern "C" void Object_SetByte6BToFiveAndFlag8ThenUpdateState(char* p){p[107]=5;p[142]=0;*(unsigned*)(p+24)|=8;ClearField18Flag10AndBytes7BAnd9E(p);}
