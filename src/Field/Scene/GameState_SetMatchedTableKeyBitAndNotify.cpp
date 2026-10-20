#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d6638; symbol: data_ov017_021d6638.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 4c04b00464001405274edc05a8160807a4066c07c800d00734089808fc08a42144169001.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned short GameStateSetMatchedTableKeyBitAndNotify_UnknownRoleInitializedBytes[];
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" void* GameState_GetSerializedProgressState();
extern "C" void BitArray_SetIndexedBoolean(void*,unsigned char*,int,int);
extern "C" void Network_QueueConnectionValueRecord(int,int,unsigned short,int);
// Original: arm9/ov017 @ 0x0219E290; symbol: func_ov017_0219e290; size: 0x80.
extern "C" void GameState_SetMatchedTableKeyBitAndNotify(void* unused,int key) {
 unsigned char* object=(unsigned char*)GameState_GetSerializedProgressState();
 int match=-1;
 for(unsigned i=0;i<18;i++) { if(key==GameStateSetMatchedTableKeyBitAndNotify_UnknownRoleInitializedBytes[i]) match=i; }
 if(match<0) return;
 BitArray_SetIndexedBoolean(object,object+0x8c,match+0x200,1);
 if(Network_IsParentOrOffline((unsigned*)Network_GetConnectionManager()))
  Network_QueueConnectionValueRecord(1,0,(unsigned short)match,1);
}
