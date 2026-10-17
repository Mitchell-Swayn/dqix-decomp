#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" AllocatorUnion data_02114e20; extern "C" void Memory_FreeThroughAllocatorUnion(AllocatorUnion*,void*); extern "C" void SetByteFieldAtOffset253ToOne(GameObject*); extern "C" void Flags_ClearWordMask(void*,int); extern "C" void* GetGlobalStatePointer(); extern "C" void RecordFlags_ClearWordMask(void*,int);
// Original: arm9/main @ 0x020D9D60; symbol: func_020d9d60; size: 0x58.
extern "C" void Object_ResetGameResourcesAndReturnSignedAllocatorBlock(char* self) { GameObject* gameObject=GameState::GetInstance()->GetUnknownGameObject(); SetByteFieldAtOffset253ToOne(gameObject); void* object=GameResources_GetInstance(); Flags_ClearWordMask(object,16); RecordFlags_ClearWordMask(GetGlobalStatePointer(),14); SafeAllocator* allocator=(SafeAllocator*)(self+0x58); SignedAllocatorHeader* block=allocator->GetSignedAllocator(); if(!block)return; allocator->Destroy(); Memory_FreeThroughAllocatorUnion(&data_02114e20,block); }
