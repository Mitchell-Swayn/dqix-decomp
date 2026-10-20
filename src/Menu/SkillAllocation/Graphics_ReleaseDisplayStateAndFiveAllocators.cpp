#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
extern "C" unsigned DisplayContext_GetGlobalInstance();extern "C" void DisplayContext_IgnoreRequestToken(void*,unsigned),BackgroundLoader_CancelEightTasksAndResetState(int);extern "C" char* Graphics_GetLoadedScreenDescriptor(char*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned),LoadToMainBG1CharacterData(const void*,unsigned,unsigned),Graphics_CleanAndTransferScreenBuffer(char*,void*),Graphics_ApplyMainBackgroundSnapshotAndClearPending(void*),Graphics_ApplySubBackgroundSnapshotAndClearPending(void*);extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int),_ZN13SafeAllocator7DestroyEv(void*);
// Original: arm9/ov013 @ 0x02186fa0; symbol: Graphics_ReleaseDisplayStateAndFiveAllocators; size 0x120.
extern "C" void Graphics_ReleaseDisplayStateAndFiveAllocators(char* self){int context=DisplayContext_GetGlobalInstance();DisplayContext_IgnoreRequestToken((void*)context,104);BackgroundLoader_CancelEightTasksAndResetState(context);if(!B(self,0x64)){char* entry=Graphics_GetLoadedScreenDescriptor(self+0x28,0);if(entry){void* data=P(entry,12);if(data){memset(data,0,0x600);_Z25CleanInvalidateCacheRangePKvj(data,32);LoadToMainBG1CharacterData(data,0,32);Graphics_CleanAndTransferScreenBuffer(self+0x28,data);}}Graphics_ApplyMainBackgroundSnapshotAndClearPending(self+0x14);volatile unsigned* display=(volatile unsigned*)0x04000000;*display=(*display&~0x1f00)|(W(self,0x60)<<8);}else{Graphics_ApplySubBackgroundSnapshotAndClearPending(self+0x14);volatile unsigned* display=(volatile unsigned*)0x04001000;*display=(*display&~0x1f00)|(W(self,0x60)<<8);}if(W(self,0x5c)>=0){_ZN16BackgroundLoader10RemoveTaskEi(_ZN16BackgroundLoader11GetInstanceEv(),W(self,0x5c));W(self,0x5c)=-1;}if(P(self,0))for(unsigned char i=0;i<5;i++)_ZN13SafeAllocator7DestroyEv(P(self,0)+20*i);}
