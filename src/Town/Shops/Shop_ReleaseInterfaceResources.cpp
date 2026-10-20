#include <globaldefs.h>
ARM
extern "C" int LoadToMainBG1CharacterData(...);
extern "C" int Graphics_ApplyMainBackgroundSnapshotAndClearPending(...);
extern "C" int TextContext_GetSharedInstance(...);
extern "C" int _Z25CleanInvalidateCacheRangePKvj(...);
extern "C" int _ZN13SafeAllocator7DestroyEv(...);
extern "C" int _ZN16BackgroundLoader10RemoveTaskEi(...);
extern "C" int _ZN16BackgroundLoader11GetInstanceEv(...);
extern "C" void* memset(void*,int,unsigned);extern "C" void* memcpy(void*,const void*,unsigned);
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov003 @ 0x02174454; symbol: ReleaseBackgroundTaskAndSixAllocators; size: 0xc8.
extern "C" void Shop_ReleaseInterfaceResources(char* self){
void* loader=(void*)_ZN16BackgroundLoader11GetInstanceEv();if(W(self,0xfec)>=0){_ZN16BackgroundLoader10RemoveTaskEi(loader,W(self,0xfec));W(self,0xfec)=-1;}char* layout=C(TextContext_GetSharedInstance());W(layout,0x2d8)=0;B(layout,0x2e6)=1;volatile unsigned* display=(volatile unsigned*)0x04000000;*display=(*display&~0x1f00)|0x100;*(volatile unsigned short*)0x04000050=0;Graphics_ApplyMainBackgroundSnapshotAndClearPending(self+36);if(P(self,0xff4)){memset(P(self,0xff4),0,32);_Z25CleanInvalidateCacheRangePKvj(P(self,0xff4),32);LoadToMainBG1CharacterData(P(self,0xff4),0,32);}unsigned char i=0;P(self,0xff4)=0;if(!P(self,4))return;for(;i<6;i++)_ZN13SafeAllocator7DestroyEv(P(self,4)+i*20);
}
