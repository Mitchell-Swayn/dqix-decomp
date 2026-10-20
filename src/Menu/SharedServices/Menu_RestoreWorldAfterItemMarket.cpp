#include <globaldefs.h>
ARM
extern "C" int GameResources_ClearTertiaryFlags(...);
extern "C" int GameResources_ClearSecondaryFlags(...);
extern "C" int GameResources_ClearPrimaryFlags(...);
extern "C" int GameResources_GetInstance(...);
extern "C" int SystemState_GetGlobalFlags(...);
extern "C" int GameResources_SetSecondaryFlags(...);
extern "C" int Zone3D_GetMainInstance(...);
extern "C" int SystemState_ClearFlags(...);
extern "C" int GameObject_RequestMovementInputEnable(...);
extern "C" int GameResources_SetTertiaryFlags(...);
extern "C" int GameResources_SetPrimaryFlags(...);
extern "C" int _ZN12ZoneFeatures8SetColorEt(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int _ZN9GameState20GetUnknownGameObjectEv(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov004 @ 0x02158298; symbol: RestoreResourceMasksAndZoneColorFromSavedSettings.
extern "C" int Menu_RestoreWorldAfterItemMarket(void){
char*state=C(_ZN9GameState11GetInstanceEv());char*resources=C(GameResources_GetInstance());GameResources_ClearPrimaryFlags(resources,-1);GameResources_ClearSecondaryFlags(resources,-1);GameResources_ClearTertiaryFlags(resources,-1);GameResources_SetPrimaryFlags(resources,W(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),0));GameResources_SetSecondaryFlags(resources,W(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),4));GameResources_SetTertiaryFlags(resources,W(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),8));char*world=C(Zone3D_GetMainInstance());if(!world)return 0;char*zone=world+108;if(!zone)return 0;_ZN12ZoneFeatures8SetColorEt(zone,H(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),12));GameObject_RequestMovementInputEnable(_ZN9GameState20GetUnknownGameObjectEv(state));struct Flags{char pad[12];unsigned short low:13;unsigned short high:3;inline unsigned short Read(){return low;}inline void Write(unsigned short value){low=value;}};struct Region{char pad[0x5d00];Flags flags;};Region*region=(Region*)(state+0x26c);region->flags.Write(region->flags.Read()&~32);SystemState_ClearFlags(SystemState_GetGlobalFlags(),15);char*object=P(resources+0x3000,0x710);if(B(object,2))B(object,313)=1;return 0;
}
