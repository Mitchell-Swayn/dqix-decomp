#include <globaldefs.h>
ARM
extern "C" int Selection_ReleaseAttachedDisplayResources(...);
extern "C" int Window_ClearResourceBuffers(...);
extern "C" int GetMainBG1CharacterBase(...);
extern "C" int Graphics_ResetCountedThirtyTwoByteTransfers(...);
extern "C" int Ov017_InitializeOverlayCanvasState(...);
extern "C" int Field_ReleasePromptBackgroundStagingBuffers(...);
extern "C" int Window_ResetResourceTransfers(...);
extern "C" int _ZN16BackgroundLoader10RemoveTaskEi(...);
extern "C" int _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" int Graphics_AllocateVRAMStagingMemoryForRecords(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021A5BAC; symbol: ResetLoadedOverlayCanvasAndRestoreMainDisplay.
extern "C" void Field_ReleaseGrottoMapPromptAndRestoreDisplay(char*self){
if(!W(self+0x4000,0x1c0))return;if(W(self+0x4000,0x1b8)){volatile unsigned*display=(volatile unsigned*)0x04000000;*display=(*display&~0x1f00)|0x100;if(W(self+0x4000,0x1bc)>=0){int loader=_ZN16BackgroundLoader11GetInstanceEv();_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self+0x4000,0x1bc));W(self+0x4000,0x1bc)=-1;}*(volatile unsigned short*)0x04000050=0;volatile unsigned short*bg=(volatile unsigned short*)0x04000008;*bg=(*bg&~3)|1;if(W(self+0x4000,0x1b4)){memset((void*)GetMainBG1CharacterBase(),0,32);Graphics_AllocateVRAMStagingMemoryForRecords(self+0x4094,2,2048);char*canvas=P(self+0x4000,0x90);Window_ClearResourceBuffers(canvas);Graphics_ResetCountedThirtyTwoByteTransfers(canvas);Window_ResetResourceTransfers(canvas);Field_ReleasePromptBackgroundStagingBuffers(self+0x4094,2);Selection_ReleaseAttachedDisplayResources(canvas);*display=(*display&~0x1f00)|0x1300;}}Ov017_InitializeOverlayCanvasState(self);
}
