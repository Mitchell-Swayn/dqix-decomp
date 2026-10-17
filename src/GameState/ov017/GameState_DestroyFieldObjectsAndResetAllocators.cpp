#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void GameState_ClearObjectByIndex(void*,unsigned);
void* _ZN9GameState20GetGameObjectByIndexEi(void*,int);
void* _ZN9GameState27GetMaybeFieldMonsterByIndexEi(void*,int);
void* ReadSignedWordField32C(void*);
void* Object_ReadWordAtOffset330(void*);
unsigned char* ReadGlobalValueAt020FB3F0();
void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
void _ZN13SafeAllocator5ResetEv(void*);
void _ZN13SafeAllocator7DestroyEv(void*);
void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
void _ZN8Object3D7DestroyEv(void*);
unsigned char* Object_GetGlobalThirtyTwoEntryContainer();
void ResetThreeEmbeddedObjectsAndClearOwnerBuffer(unsigned char*);
void SnapshotBlockAndVolatileWordPair(char*);
void _ZN13ZoneState26645ResetEv(void*);
void ResourceLoader_RemoveFourTasksAndDestroyAllocator(void*);
void GameState_ClearDisplayObjectsAndResetSlots(void*);
extern unsigned char data_ov017_021d82fc[];
}
// Original: arm9/ov017 @ 0x021A316C; symbol: func_ov017_021a316c; size: 0x1CC.
extern "C" void GameState_DestroyFieldObjectsAndResetAllocators(unsigned char* p) {
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned char* global=ReadGlobalValueAt020FB3F0();
 if(_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0x11c0)) { _ZN13SafeAllocator7DestroyEv(p+0x11c0); _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x11c0); }
 if(_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0x113c)) { _ZN13SafeAllocator7DestroyEv(p+0x113c); _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x113c); }
 if(_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0x113c)) { _ZN13SafeAllocator7DestroyEv(p+0x113c); _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x113c); }
 if(_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0x1244)) { _ZN13SafeAllocator7DestroyEv(p+0x1244); _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x1244); }
 ResourceLoader_RemoveFourTasksAndDestroyAllocator(data_ov017_021d82fc);
 GameState_ClearDisplayObjectsAndResetSlots(p);
 for(int i=0;i<0x30;i++) {
  void* object=_ZN9GameState27GetMaybeFieldMonsterByIndexEi(state,i+0x70);
  if(object) _ZN8Object3D7DestroyEv(object);
 }
 _ZN13SafeAllocator5ResetEv(p+0xc4);
 SnapshotBlockAndVolatileWordPair((char*)p+0x5dc);
 for(int i=0;i<0x30;i++) {
  void* object=_ZN9GameState27GetMaybeFieldMonsterByIndexEi(state,i+0x70);
  if(object) _ZN8Object3D7DestroyEv(object);
 }
 ResetThreeEmbeddedObjectsAndClearOwnerBuffer(Object_GetGlobalThirtyTwoEntryContainer());
 _ZN13ZoneState26645ResetEv(global+0x2664);
 if(ReadSignedWordField32C(state)) GameState_ClearObjectByIndex(state,0xc9);
 if(Object_ReadWordAtOffset330(state)) GameState_ClearObjectByIndex(state,0xca);
 for(int i=1;i<4;i++) if(_ZN9GameState20GetGameObjectByIndexEi(state,i+0xca)) GameState_ClearObjectByIndex(state,i+0xca);
 GameState_ClearObjectByIndex(state,0xce);
}
