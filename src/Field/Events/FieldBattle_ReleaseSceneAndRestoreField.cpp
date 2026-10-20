#include <globaldefs.h>
ARM
#pragma opt_common_subs off
// Separate observed object bases are retained, as in adjacent matched FieldBattle lifecycle routines.
// Original data: arm9/main @ 0x02114E20; symbol: data_02114e20.
// Mutable zero-initialized allocator-union storage; logical extent is unresolved.
// Full storage record: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
extern "C" void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);
extern "C" char* GameResources_GetInstance();
extern "C" void BattleScene_Destroy(void*);
extern "C" void OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void GameObject_RequestMovementInputEnable(void*);
extern "C" void Object_SetHalfword1B2WhenMemberListedOrForced(void*,int,int);
extern "C" void Ov017_ApplyIndexedSignedValues(void*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
extern "C" void ZoneTransition_InitializeRequest(void*);
extern "C" void GameResources_ClearPrimaryFlags(void*,unsigned);
extern "C" void FileCache_RestoreRomTablesIfSpaceAvailable();
extern "C" int LinkedList_ContainsTag(void*,int);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void _ZN6Zone3D20SetBMDJStateRequestsEv(void*);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_ClearFlags(void*,unsigned);
// Original: arm9/ov017 @ 0x021B6F9C; symbol: func_ov017_021b6f9c; size: 0x168.
// Destroys the battle scene, releases its allocator, clears encounter state, and restores field movement and transition requests.
extern "C" void FieldBattle_ReleaseSceneAndRestoreField(char* self) {
 char* resources=GameResources_GetInstance();
 int saved;
 unsigned retained=*(unsigned short*)(self+0x6b6)&0x2000;
 saved=*(int*)(self+0x28);
 unsigned short* keys=(unsigned short*)(resources+0x44ae);
 if(keys[0]==*(unsigned short*)(self+0x24)) {keys[0]=0;keys[1]=0;}
 void* scene=*(void**)(self+0x6ac);
 if(scene)BattleScene_Destroy(scene);
 void* allocation=_ZNK13SafeAllocator18GetSignedAllocatorEv(self+8);
 if(allocation) {
 _ZN13SafeAllocator7DestroyEv(self+8);
 Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,allocation);
 }
 if(*(unsigned short*)(self+0x6b6)&0x800) {
 OverlayLoader_PopPrimarySelectionAndOptionallyRestoreOverlay(1);
 OverlayLoader_PopSecondarySelectionAndOptionallyRestoreOverlay(1);
 }
 void* object=_ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());
 GameObject_RequestMovementInputEnable(object);
 Object_SetHalfword1B2WhenMemberListedOrForced(object,0,0);
 Ov017_ApplyIndexedSignedValues(0);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(self+8);
 ZoneTransition_InitializeRequest(self+0x1c);
 *(void**)(self+0x6ac)=0;
 *(void**)(self+0x6b0)=0;
 *(unsigned short*)(self+0x6b4)=1;
 *(unsigned short*)(self+0x6b6)=0;
 *(unsigned*)(self+0x6b8)=0;
 GameResources_ClearPrimaryFlags(resources,0x800);
 FileCache_RestoreRomTablesIfSpaceAvailable();
 void* tags=*(void**)(resources+0x36fc);
 unsigned char* state=*(unsigned char**)(resources+0x3b5c);
 bool restore;
 if(saved<0 || !LinkedList_ContainsTag(tags,4))restore=true;else restore=false;
 void* zone=Zone3D_GetMainInstance();
 if(restore && !retained && state[8])_ZN6Zone3D20SetBMDJStateRequestsEv(zone);
 SystemState_ClearFlags(SystemState_GetGlobalFlags(),0x40000);
}
