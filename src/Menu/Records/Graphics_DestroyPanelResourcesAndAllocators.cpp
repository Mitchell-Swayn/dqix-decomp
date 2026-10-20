#include <globaldefs.h>
ARM
struct Owner;
extern "C" {
void* _ZN16BackgroundLoader11GetInstanceEv();void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);void Graphics_FinalizeSpriteResourceBuffers(void*);void Menu_DestroyQueuedRecordPanelResources(void*);
unsigned TextContext_GetSharedInstance();void TextEntry_ResetGlyphCacheAndTextureAllocator(Owner*);void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);void Graphics_ClearAndStageSharedBuffers(char*);
void Graphics_ClearScreenBuffer(unsigned char*,void*);void Graphics_CleanConfiguredDestinationCache(void*,int);void Graphics_TransferScreenBuffer(void*,int);void Graphics_ResetLoadedLayerResources(unsigned char*);
unsigned GetMainBGAssignedVRAMSize();void MIi_CpuClearFast(int,void*,unsigned);void Selection_ReleaseAttachedDisplayResources(unsigned char*);void _ZN8Object3D7DestroyEv(void*);void _ZN13SafeAllocator7DestroyEv(void*);
void* Zone3D_GetMainInstance();void _ZN6Zone3D20SetBMDJStateRequestsEv(void*);void* SystemState_GetGlobalFlags();void SystemState_ClearFlags(unsigned*,unsigned);
}
#define P(o) (*(char**)(self+(o)))
#define W(o) (*(unsigned*)(self+(o)))
// Original: arm9/ov008 @ 0x021845AC; symbol: func_ov008_021845ac; size: 0x1A8.
// Removes pending load, finalizes panel graphics, clears main-BG VRAM and destroys the seven owned allocator entries.
extern "C" void Graphics_DestroyPanelResourcesAndAllocators(char* self) {
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();int task=*(int*)(self+0xb20);
 if(task>=0){_ZN16BackgroundLoader10RemoveTaskEi(loader,task);W(0xb20)=-1;}
 if(P(0x730))Graphics_FinalizeSpriteResourceBuffers(P(0x730));if(P(0x73c))Graphics_FinalizeSpriteResourceBuffers(P(0x73c));if(P(0xb08))Menu_DestroyQueuedRecordPanelResources(P(0xb08));
 char* context=(char*)TextContext_GetSharedInstance();TextEntry_ResetGlyphCacheAndTextureAllocator((Owner*)context);TextWindow_ResetGlyphBuffersAndFrameContexts(context);Graphics_ClearAndStageSharedBuffers(context);
 *(unsigned*)(context+0x2d8)=0;*(unsigned*)(context+0x2dc)=0;*(unsigned*)(context+0x2e0)=0;
 unsigned char* canvases[3]={(unsigned char*)self+0xd0,(unsigned char*)self+0xf0,(unsigned char*)self+0x110};
 for(int i=0;i<3;i++){unsigned char* canvas=canvases[i];Graphics_ClearScreenBuffer(canvas,0);Graphics_CleanConfiguredDestinationCache(canvas,0);Graphics_TransferScreenBuffer(canvas,0);Graphics_ResetLoadedLayerResources(canvas);}
 MIi_CpuClearFast(0,(void*)0x6000000,GetMainBGAssignedVRAMSize());Selection_ReleaseAttachedDisplayResources((unsigned char*)self+0x130);_ZN8Object3D7DestroyEv(self+0x790);
 P(0xb8)=0;W(0x72c)=0;char* allocators[8]={self,self+0x14,self+0x28,self+0x3c,self+0x50,self+0x64,self+0x78,self+0x8c};
 // The target prepares eight pointers but traverses exactly seven entries.
 for(int i=0;i<7;i++)_ZN13SafeAllocator7DestroyEv(allocators[i]);
 if(!*(unsigned char*)(self+0xb13)){if(!W(0xb24))_ZN6Zone3D20SetBMDJStateRequestsEv(Zone3D_GetMainInstance());SystemState_ClearFlags((unsigned*)SystemState_GetGlobalFlags(),15);}
}
