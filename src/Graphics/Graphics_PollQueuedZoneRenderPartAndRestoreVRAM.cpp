#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define C(p,o) (*(signed char*)((p)+(o)))
#define V(p,o) (*(char**)((p)+(o)))
extern "C" void* SystemState_GetGlobalFlags();extern "C" bool SystemState_TestAnyFlags(const unsigned*,unsigned);extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();extern "C" unsigned _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,unsigned);extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,unsigned,void**,unsigned*);extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);extern "C" void TextureVRAM_SnapshotAllocationBounds(char*);extern "C" void Graphics_RestoreTextureImageAndPaletteVRAMState(void*);extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);extern "C" void _ZN23ZoneContainerRenderPart5ResetEv(void*);extern "C" void ZoneContainerRenderPart_LoadSerializedFramesAndAnimations(void*,void*,unsigned);extern "C" void Object_InvokeSaveTextureImageVRAMState(char*);extern "C" void BackgroundLoader_QueueIndexedObjectResources(char*,int);
// Original: arm9/main @ 0x020534AC; symbol: Graphics_PollQueuedZoneRenderPartAndRestoreVRAM; size: 0x11C.
extern "C" void Graphics_PollQueuedZoneRenderPartAndRestoreVRAM(char* self){
if(SystemState_TestAnyFlags((unsigned*)SystemState_GetGlobalFlags(),2)||!B(self,0x185))return;void* loader=_ZN16BackgroundLoader11GetInstanceEv();if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,U(self,0x194))==2){void* file;unsigned size;_ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,U(self,0x194),&file,&size);if(file){char* context=V(self,0x154);char* vram=context+0x568;char* allocator=context+0x554;TextureVRAM_SnapshotAllocationBounds(vram);Graphics_RestoreTextureImageAndPaletteVRAMState(vram);V(self,0x190)=_ZN13SafeAllocator8AllocateEj((unsigned)allocator,0x88);if(V(self,0x190)){_ZN23ZoneContainerRenderPart5ResetEv(V(self,0x190));B(V(self,0x190),0x84)|=4;ZoneContainerRenderPart_LoadSerializedFramesAndAnimations(V(self,0x190),file,(unsigned)allocator);}Object_InvokeSaveTextureImageVRAMState(vram);}}_ZN16BackgroundLoader10RemoveTaskEi(loader,I(self,0x194));I(self,0x194)=-1;B(self,0x185)=0;if(B(self,0x186)){int i=C(self,0x17d)+1;BackgroundLoader_QueueIndexedObjectResources(self,C(self+i,0x178));B(self,0x186)=0;}
}
