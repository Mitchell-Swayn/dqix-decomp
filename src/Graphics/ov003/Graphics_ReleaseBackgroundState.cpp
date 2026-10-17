#include <globaldefs.h>
ARM
struct Object; struct Obj; struct State; struct GameResources;
extern "C" void* GetGlobalStatePointer();
extern "C" void RecordFlags_ClearWordMask(unsigned int*,unsigned int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" GameResources* GameResources_GetInstance();
extern "C" void ClearWordAtOffset4MaskedBits(int,unsigned int);
extern "C" void ProcessActiveObjectAndClearActiveFlag(Object*);
extern "C" void Graphics_ResetCountedTransferRecordsAtOffset2C(unsigned char*);
extern "C" void SetValueZeroForEachThirtyTwoByteEntry(State*);
extern "C" void Graphics_ResetCountedTransferEntriesWithModeZero(State*);
extern "C" void BackgroundLoader_RemovePrimaryAndThreeSecondaryTasks(Obj*);
extern "C" void* memset(void*,int,unsigned int);
extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
extern "C" void LoadToMainBG1CharacterData(const void*,unsigned int,unsigned int);
extern "C" unsigned int ReadWordFieldAtOffset1C();
extern "C" void ResetGlobalOwnerAndEmbeddedSelectionState(void*);
extern "C" void ClearAndStageSharedGraphicsBuffers(char*);
extern "C" void _ZN13SafeAllocator7DestroyEv(void*);
// Original: arm9/ov003 @ 0x0215FB94; symbol: func_ov003_0215fb94; size: 0x154.
extern "C" void Graphics_ReleaseBackgroundState(char* p) {
 RecordFlags_ClearWordMask((unsigned int*)GetGlobalStatePointer(),0x80000);
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(*(int*)(p+0x46c)>=0) { _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x46c)); *(int*)(p+0x46c)=-1; }
 GameResources* resources=GameResources_GetInstance();
 *(volatile unsigned int*)0x4000000=(*(volatile unsigned int*)0x4000000&~0x1f00)|(*(unsigned int*)(p+0x330)<<8);
 ClearWordAtOffset4MaskedBits((int)resources,0xc0);
 *(volatile unsigned int*)0x4000000=(*(volatile unsigned int*)0x4000000&~0x1f00)|0x100;
 *(volatile unsigned short*)0x4000050=0;
 ProcessActiveObjectAndClearActiveFlag((Object*)(p+0x2f4));
 unsigned char* transfer=*(unsigned char**)(p+0x324);
 if(transfer) { Graphics_ResetCountedTransferRecordsAtOffset2C(transfer); SetValueZeroForEachThirtyTwoByteEntry((State*)transfer); Graphics_ResetCountedTransferEntriesWithModeZero((State*)transfer); BackgroundLoader_RemovePrimaryAndThreeSecondaryTasks((Obj*)transfer); }
 if(*(void**)(p+0x398)) { memset(*(void**)(p+0x398),0,0x20); _Z25CleanInvalidateCacheRangePKvj(*(void**)(p+0x398),0x20); LoadToMainBG1CharacterData(*(void**)(p+0x398),0,0x20); }
 *(void**)(p+0x398)=0;
 char* shared=(char*)ReadWordFieldAtOffset1C();
 if(*(int*)(shared+0x998)) { ResetGlobalOwnerAndEmbeddedSelectionState(shared); ClearAndStageSharedGraphicsBuffers(shared); }
 *(int*)(shared+0x2d8)=0;
 *(unsigned char*)(shared+0x2e6)=1;
 _ZN13SafeAllocator7DestroyEv(p+0x2c8); _ZN13SafeAllocator7DestroyEv(p+0x2b4); _ZN13SafeAllocator7DestroyEv(p+0x2a0); _ZN13SafeAllocator7DestroyEv(p+0x28c); _ZN13SafeAllocator7DestroyEv(p+0x278); _ZN13SafeAllocator7DestroyEv(p+0x264); _ZN13SafeAllocator7DestroyEv(p+0x23c); _ZN13SafeAllocator7DestroyEv(p+0x228);
}
