#include <globaldefs.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <std_library_functions.h>
#include <System/LoadToVRAM.h>
struct Object;struct State;
ARM
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define I(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))

#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned TextContext_GetSharedInstance();extern "C" void Graphics_ApplySubBackgroundSnapshotAndClearPending(Object*);extern "C" void Graphics_ApplyMainBackgroundSnapshotAndClearPending(Object*);extern "C" void Window_ClearResourceBuffers(unsigned char*);extern "C" void Graphics_ResetCountedThirtyTwoByteTransfers(unsigned char*);extern "C" void Window_ResetResourceTransfers(unsigned char*);extern "C" void Selection_ReleaseAttachedDisplayResources(unsigned char*);extern "C" void* memset(void*,int,unsigned);extern "C" void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);extern "C" void Window_PopCanvasesAndResetSelection(State*,int);
// Original: arm9/ov013 @ 0x021846A0; symbol: func_ov013_021846a0; size: 0x124.
#pragma force_active on
extern "C" void Graphics_DestroyModeDependentPanelAndTwoAllocators(unsigned char* self){BackgroundLoader* loader=BackgroundLoader::GetInstance();if(I(self,1616)>=0){loader->RemoveTask(I(self,1616));W(self,1616)=-1;}B((void*)TextContext_GetSharedInstance(),6590)=0;if(B(self,1600)){Graphics_ApplySubBackgroundSnapshotAndClearPending((Object*)(self+32));Window_PopCanvasesAndResetSelection((State*)(self+56),1);Window_ClearResourceBuffers((unsigned char*)self+56);Graphics_ResetCountedThirtyTwoByteTransfers(self+56);Window_ResetResourceTransfers(self+56);}else{Graphics_ApplyMainBackgroundSnapshotAndClearPending((Object*)(self+32));Window_ClearResourceBuffers((unsigned char*)self+56);Graphics_ResetCountedThirtyTwoByteTransfers(self+56);Window_ResetResourceTransfers(self+56);Selection_ReleaseAttachedDisplayResources((unsigned char*)self+56);if(P(self,1620)){memset(P(self,1620),0,32);_Z25CleanInvalidateCacheRangePKvj(P(self,1620),32);LoadToMainBG1CharacterData(P(self,1620),0,32);}volatile unsigned* display=(volatile unsigned*)0x04000000;*display=(*display&~0x1f00u)|(W(self,52)<<8);}if(((SafeAllocator*)(self+1548))->GetSignedAllocator())((SafeAllocator*)(self+1548))->Destroy();if(((SafeAllocator*)self)->GetSignedAllocator())((SafeAllocator*)self)->Destroy();B(self,1596)=6;}
