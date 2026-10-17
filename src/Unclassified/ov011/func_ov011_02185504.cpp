#include <globaldefs.h>
struct Fields { char prefix[0x1cc]; unsigned char active; char pad[7]; unsigned mainBanks,subBanks; };
struct GlobalState { char pad[0x998]; unsigned field998,field99c,field9a0; };
extern "C" void* func_ov017_021b2164();
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov011_021849c8(void*);
extern "C" void func_ov011_02184c68(void*, unsigned);
extern "C" void* func_ov023_021f6880(void*,unsigned);
extern "C" unsigned OV023_ReadHalfwordField04();
extern "C" void func_ov011_021849e0(void*,unsigned);
extern "C" void func_ov011_021849d0(void*,unsigned);
extern "C" unsigned func_ov011_021849d8(void*);
extern "C" void func_ov011_02184a0c(void*,unsigned);
extern "C" void func_ov011_02184be0(void*,unsigned,unsigned);
extern "C" void func_ov011_02184bf0(void*,unsigned,unsigned);
extern "C" GlobalState* ReadWordFieldAtOffset1C();
extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState();
extern "C" void ClearAndStageSharedGraphicsBuffers(void*);
extern "C" unsigned ReadWordFieldAtOffset954(void*);
extern "C" void* GameResources_GetInstance();
extern "C" unsigned _Z28IsBrightnessTransitionActiveP13GameResources(void*);
extern "C" void Memory_InitializeRecordAtIndexIfLessThanThree(void*,unsigned);
extern "C" unsigned func_ov023_021f6bc0(void*);
extern "C" void _ZN23ZoneContainerRenderPart12ResetIfFlag0Ev(void*);
extern "C" void _ZN21ZoneRenderPartEntries5ResetEv(void*);
extern "C" void MapVRAMBanksToMainBG(unsigned);
extern "C" void MapVRAMBanksToSubBG(unsigned);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,unsigned);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" void Graphics_ResetLayoutAndDisplayFlagsAt20(void*);
extern "C" void func_ov023_021f9c0c(void*);
// Original: arm9/ov011 @ 0x02185504; symbol: func_ov011_02185504; size: 0x48.
extern "C" unsigned func_ov011_02185504(void* self) { unsigned id=func_ov011_02184c30(self); void* item=func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()),id); if(!item) return 0; if(OV023_ReadHalfwordField04()!=6) return 0; Graphics_ResetLayoutAndDisplayFlagsAt20(item); return 1; }
