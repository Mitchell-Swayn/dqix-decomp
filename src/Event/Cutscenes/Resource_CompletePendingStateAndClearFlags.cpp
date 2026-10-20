#include <globaldefs.h>
#include <Resource/GameResources.h>
ARM
struct Object;
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Object Main_UnknownRoleZeroInitializedStorage_Variant2;
extern "C" int Bgm_GetPlaybackMode(Object*);
extern "C" void Bgm_ReturnToPrimaryPlayback(Object*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void GameResources_ClearSecondaryFlags(int,unsigned int);
extern "C" void GameResources_ClearPrimaryFlags(unsigned int*,unsigned int);
// Original: arm9/ov001 @ 0x02156B20; symbol: func_ov001_02156b20; size: 0x80.
extern "C" void Resource_CompletePendingStateAndClearFlags() {
 GameResources* res=GameResources_GetInstance();
 if(Bgm_GetPlaybackMode(&Main_UnknownRoleZeroInitializedStorage_Variant2)==2) Bgm_ReturnToPrimaryPlayback(&Main_UnknownRoleZeroInitializedStorage_Variant2);
 if(*(unsigned short*)Zone3D_GetMainInstance()!=10000) GameResources_ClearSecondaryFlags((int)res,4);
 GameResources_ClearSecondaryFlags((int)res,0x40);
 GameResources_ClearSecondaryFlags((int)res,0x10);
 GameResources_ClearSecondaryFlags((int)res,2);
 GameResources_ClearPrimaryFlags((unsigned int*)res,4);
}
