#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int Field_IsHostDisconnectPending();
extern "C" void Menu_DestroyArenaTreeAndOwnedDisplayRecords(void*,void*);
extern "C" void Graphics_ApplyMainBackgroundSnapshotAndClearPending(void*);
extern "C" void Graphics_ApplySubBackgroundSnapshotAndClearPending(void*);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void* memset(void*,int,unsigned);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void LoadToMainBG1CharacterData(const void*,unsigned,unsigned);
extern "C" void LoadToMainBG1ScreenData(const void*,unsigned,unsigned);
extern "C" int MenuRecordList_GetBackgroundTaskId(void*);
extern "C" int GameResources_GetInstance();
extern "C" void GameResources_ClearSecondaryFlags(int,unsigned);
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant6;
// Original: arm9/ov011 @ 0x02184770; symbol: func_ov011_02184770; size: 0x130.
extern "C" void Graphics_ResetOverlayBackgroundState(char* p) {
 if(Field_IsHostDisconnectPending() && *(void (**)(void*))(p+0x1dc)) (*(void (**)(void*))(p+0x1dc))(p);
 *(int*)(p+0x1dc)=0;
 Menu_DestroyArenaTreeAndOwnedDisplayRecords(p,p);
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000 & ~0x1f00)|0x100;
 Graphics_ApplyMainBackgroundSnapshotAndClearPending(p+0x194);
 Graphics_ApplySubBackgroundSnapshotAndClearPending(p+0x194);
 unsigned flag=*(volatile unsigned*)(p+0x190);
 unsigned power=*(volatile unsigned short*)0x04000304;
 power &= ~0x8000;
 power |= flag<<15;
 *(volatile unsigned short*)0x04000304=power;
 _ZN16BackgroundLoader13AddLockGlobalEv();
 _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
 void* buffer=&Main_UnknownRoleZeroInitializedStorage_Variant6;
 memset(buffer,0,0x600);
 _Z25CleanInvalidateCacheRangePKvj(buffer,0x20);
 LoadToMainBG1CharacterData(buffer,0,0x20);
 _Z25CleanInvalidateCacheRangePKvj(buffer,0x600);
 LoadToMainBG1ScreenData(buffer,0,0x600);
 unsigned mainFlags=*(volatile unsigned*)(p+0x1a8);
 unsigned reg=*(volatile unsigned*)0x04000000;
 reg &= ~0x1f00;
 reg |= mainFlags<<8;
 *(volatile unsigned*)0x04000000=reg;
 unsigned subFlags=*(volatile unsigned*)(p+0x1ac);
 reg=*(volatile unsigned*)0x04001000;
 reg &= ~0x1f00;
 reg |= subFlags<<8;
 *(volatile unsigned*)0x04001000=reg;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 int id=MenuRecordList_GetBackgroundTaskId(p+0x118);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,id);
 _ZN16BackgroundLoader16RemoveLockGlobalEv();
 GameResources_ClearSecondaryFlags(GameResources_GetInstance(),0xc0);
}
