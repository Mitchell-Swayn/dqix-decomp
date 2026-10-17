#include <globaldefs.h>
ARM
struct GameResources;struct MapGameObject;struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void* GameState_GetField3B0ObjectWithFlag4(GameState*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void SetByteFieldAtOffset253ToOne(void*);
extern "C" void ClearWordAtOffset4MaskedBits(int,unsigned);
extern "C" void SetField238Enabled(void*);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void World_UpdateAndSnapshotObjectState(GameResources*);
extern "C" char data_02114e20[];
// Original: arm9/ov017 @ 0x021B5A30; symbol: func_ov017_021b5a30; size: 0xBC.
extern "C" void Memory_DestroyTwoAllocatorsAndRestoreGameFlags(unsigned char* p){
 GameResources* resources=GameResources_GetInstance();
 if(p[0x54] && resources){World_UpdateAndSnapshotObjectState(resources);p[0x54]=0;}
 void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0x40);
 if(allocation){_ZN13SafeAllocator7DestroyEv(p+0x40);Memory_FreeThroughAllocatorUnion(data_02114e20,allocation);}
 allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(p+0x58);
 if(allocation){_ZN13SafeAllocator7DestroyEv(p+0x58);Memory_FreeThroughAllocatorUnion(data_02114e20,allocation);}
 void* gs=_ZN9GameState11GetInstanceEv();
 void* object=_ZN9GameState20GetUnknownGameObjectEv(gs);
 if(object)SetByteFieldAtOffset253ToOne(object);
 object=GameState_GetField3B0ObjectWithFlag4((GameState*)gs);
 if(object)SetField238Enabled(object);
 if(resources)ClearWordAtOffset4MaskedBits((int)resources,128);
}
