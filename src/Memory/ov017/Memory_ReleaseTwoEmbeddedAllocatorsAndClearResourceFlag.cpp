#include <globaldefs.h>
ARM
struct GameResources; struct GameState;
extern "C" unsigned char data_02114e20[];
extern "C" GameResources* GameResources_GetInstance();
extern "C" void World_UpdateAndSnapshotObjectState(GameResources*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetField3B0ObjectWithFlag4(GameState*);
extern "C" void Object_SetWordAtOffset23CTo1(void*);
extern "C" void ClearWordAtOffset4MaskedBits(int,unsigned);
// Original: arm9/ov017 @ 0x021BF490; symbol: func_ov017_021bf490; size: 0xA4.
extern "C" void Memory_ReleaseTwoEmbeddedAllocatorsAndClearResourceFlag(unsigned char* self) {
 GameResources* resources=GameResources_GetInstance();
 if(self[0x48] && resources) { World_UpdateAndSnapshotObjectState(resources); self[0x48]=0; }
 void* storage=_ZNK13SafeAllocator18GetSignedAllocatorEv(self+0x34);
 if(storage) { _ZN13SafeAllocator7DestroyEv(self+0x34); Memory_FreeThroughAllocatorUnion(data_02114e20,storage); }
 storage=_ZNK13SafeAllocator18GetSignedAllocatorEv(self+0x4c);
 if(storage) { _ZN13SafeAllocator7DestroyEv(self+0x4c); Memory_FreeThroughAllocatorUnion(data_02114e20,storage); }
 void* object=GameState_GetField3B0ObjectWithFlag4((GameState*)_ZN9GameState11GetInstanceEv());
 if(object) Object_SetWordAtOffset23CTo1(object);
 if(resources) ClearWordAtOffset4MaskedBits((int)resources,0x80);
}
