#include <globaldefs.h>
ARM
struct LowSeven {unsigned char value:7;unsigned char rest:1;};
extern "C" char* GetSubBG0ScreenBase(...);
extern "C" char* GetMainBG3ScreenBase(...);
extern "C" char* Zone3D_GetMainInstance(...);
extern "C" char* Filesystem_ExtractLocalizedGp2FileToScratch(...);
extern "C" void memset(...);
extern "C" void memcpy(...);
extern "C" void ResourceHandle_SwitchTargetUnlessBlocked(...);
extern "C" void Bgm_SetVolumeSetting(...);
extern "C" void GameState_EnableGlobalFlag64(...);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv(...);
extern "C" void Text_InitializeNameTableFromAvailableData(...);
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv(...);
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
// Original data: arm9/main @ 0x2109bf4; symbol: data_02109bf4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant2[],MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[],Graphics_ClearBackgroundMapsAndLoadArchiveContext_PathDataPrmItemnameGp2[],Graphics_ClearBackgroundMapsAndLoadArchiveContext_MarkupItemnameLGNat[];
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov004 @ 0x0215BF94; symbol: Graphics_ClearBackgroundMapsAndLoadArchiveContext; size: 0xd0.
// Clears subBG0/mainBG3 maps and loads a bounded archive member into shared resource context.
extern "C" int Graphics_ClearBackgroundMapsAndLoadArchiveContext(){unsigned short* screen=(unsigned short*)GetSubBG0ScreenBase();for(int i=0;i<2048;++i)*screen++=0;memset(GetMainBG3ScreenBase(),0,4096);ResourceHandle_SwitchTargetUnlessBlocked(Main_UnknownRoleZeroInitializedStorage_Variant2,((LowSeven*)(P(Zone3D_GetMainInstance(),8)+13))->value);Bgm_SetVolumeSetting(Main_UnknownRoleZeroInitializedStorage_Variant2,B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),45));GameState_EnableGlobalFlag64();_ZN16BackgroundLoader13AddLockGlobalEv();unsigned length;char* file=Filesystem_ExtractLocalizedGp2FileToScratch(Graphics_ClearBackgroundMapsAndLoadArchiveContext_PathDataPrmItemnameGp2,Graphics_ClearBackgroundMapsAndLoadArchiveContext_MarkupItemnameLGNat,&length);if(length<=0x10800){memcpy(P(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),0x98),file,length);char* owner=P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8);Text_InitializeNameTableFromAvailableData(owner+0x8c,P(owner,0x98),length);}_ZN16BackgroundLoader16RemoveLockGlobalEv();return 0;}
