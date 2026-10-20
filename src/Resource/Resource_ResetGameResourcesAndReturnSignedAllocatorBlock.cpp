#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" AllocatorUnion Main_UnknownRoleZeroInitializedStorage_Variant3; extern "C" void Memory_FreeThroughAllocatorUnion(AllocatorUnion*,void*); extern "C" void GameObject_RequestMovementInputEnable(GameObject*); extern "C" void GameResources_ClearPrimaryFlags(void*,int); extern "C" void* SystemState_GetGlobalFlags(); extern "C" void SystemState_ClearFlags(void*,int);
// Original: arm9/main @ 0x020D9D60; symbol: func_020d9d60; size: 0x58.
extern "C" void Resource_ResetGameResourcesAndReturnSignedAllocatorBlock(char* self) { GameObject* gameObject=GameState::GetInstance()->GetUnknownGameObject(); GameObject_RequestMovementInputEnable(gameObject); void* object=GameResources_GetInstance(); GameResources_ClearPrimaryFlags(object,16); SystemState_ClearFlags(SystemState_GetGlobalFlags(),14); SafeAllocator* allocator=(SafeAllocator*)(self+0x58); SignedAllocatorHeader* block=allocator->GetSignedAllocator(); if(!block)return; allocator->Destroy(); Memory_FreeThroughAllocatorUnion(&Main_UnknownRoleZeroInitializedStorage_Variant3,block); }
