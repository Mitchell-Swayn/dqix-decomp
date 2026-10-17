#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int TestContextModeAndZeroSlot();
extern "C" void func_ov011_02184604(void*,void*);
extern "C" void ProcessActiveObjectAndClearActiveFlag(void*);
extern "C" void Object_ResetAndDeactivateState(void*);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void* memset(void*,int,unsigned);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void LoadToMainBG1CharacterData(const void*,unsigned,unsigned);
extern "C" void LoadToMainBG1ScreenData(const void*,unsigned,unsigned);
extern "C" int OV023_ReadWordField04(void*);
extern "C" int GameResources_GetInstance();
extern "C" void ClearWordAtOffset4MaskedBits(int,unsigned);
extern "C" unsigned char data_0211e33c;
// Original: arm9/ov011 @ 0x02184770; symbol: func_ov011_02184770; size: 0x130.
extern "C" void Graphics_ResetOverlayBackgroundState(char* p) {
 if(TestContextModeAndZeroSlot() && *(void (**)(void*))(p+0x1dc)) (*(void (**)(void*))(p+0x1dc))(p);
 *(int*)(p+0x1dc)=0;
 func_ov011_02184604(p,p);
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000 & ~0x1f00)|0x100;
 ProcessActiveObjectAndClearActiveFlag(p+0x194);
 Object_ResetAndDeactivateState(p+0x194);
 unsigned flag=*(volatile unsigned*)(p+0x190);
 unsigned power=*(volatile unsigned short*)0x04000304;
 power &= ~0x8000;
 power |= flag<<15;
 *(volatile unsigned short*)0x04000304=power;
 _ZN16BackgroundLoader13AddLockGlobalEv();
 _ZN16BackgroundLoader21FreeAllocationsGlobalEv();
 void* buffer=&data_0211e33c;
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
 int id=OV023_ReadWordField04(p+0x118);
 _ZN16BackgroundLoader10RemoveTaskEi(loader,id);
 _ZN16BackgroundLoader16RemoveLockGlobalEv();
 ClearWordAtOffset4MaskedBits(GameResources_GetInstance(),0xc0);
}
