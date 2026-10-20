#include <globaldefs.h>
ARM
struct GameState;struct GameResources;struct State;struct Object;
extern "C" {
void* _ZN16BackgroundLoader11GetInstanceEv();void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
void Resource_DestroyAndResetSharedRecordState(char*);
void G3X_SetClearColor(unsigned,unsigned,unsigned short,unsigned,int);
void* _ZN9GameState11GetInstanceEv();GameResources* GameState_ReadPResources(GameState*);
void GameResources_ClearSecondaryFlags(int,unsigned);
void Window_PopCanvasesAndResetSelection(State*,int);
void Selection_ReleaseAttachedDisplayResources(unsigned char*);
void Graphics_ApplyMainBackgroundSnapshotAndClearPending(Object*);
void Graphics_ClearScreenBuffer(unsigned char*,void*);
void Graphics_CleanConfiguredDestinationCache(void*,int);void Graphics_TransferScreenBuffer(void*,int);
void Graphics_ResetLoadedLayerResources(unsigned char*);
void* memset(void*,int,unsigned);
void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
void LoadToMainBG1CharacterData(const void*,unsigned,unsigned);
void _ZN13SafeAllocator7DestroyEv(void*);
}
#define W(o) (*(unsigned*)(p+(o)))
// Original: arm9/ov005 @ 0x02154198; symbol: func_ov005_02154198; size: 0x1D4.
// Cancels loading, restores display state and destroys menu-owned allocator groups.
extern "C" void ReleaseIndexedMenuGraphicsAndAllocators(unsigned char* p){
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if((int)W(0x3dc8)>=0){_ZN16BackgroundLoader10RemoveTaskEi(loader,W(0x3dc8));W(0x3dc8)=-1;}
 Resource_DestroyAndResetSharedRecordState((char*)p+0x1244);
 G3X_SetClearColor(*(unsigned short*)(p+0x3dc2),16,0x7fff,0,0);
 GameResources_ClearSecondaryFlags((int)GameState_ReadPResources((GameState*)_ZN9GameState11GetInstanceEv()),0x800);
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|(W(0xe80)<<8);
 Window_PopCanvasesAndResetSelection((State*)(p+0xee4),1);
 Selection_ReleaseAttachedDisplayResources(p+0xee4);
 Graphics_ApplyMainBackgroundSnapshotAndClearPending((Object*)(p+0xe6c));
 Graphics_ClearScreenBuffer(p+0xe84,0);
 Graphics_CleanConfiguredDestinationCache(p+0xe84,0);Graphics_TransferScreenBuffer(p+0xe84,0);
 Graphics_ResetLoadedLayerResources(p+0xe84);
 if(W(0x3d88)){
  memset((void*)W(0x3d88),0,32);
  _Z25CleanInvalidateCacheRangePKvj((void*)W(0x3d88),32);
  LoadToMainBG1CharacterData((void*)W(0x3d88),0,32);
 }
 _ZN13SafeAllocator7DestroyEv(p+0x14);
 for(int i=0;i<8;i++)_ZN13SafeAllocator7DestroyEv(p+0x28+i*20);
 for(int i=0;i<16;i++)_ZN13SafeAllocator7DestroyEv(p+0xc8+i*20);
 _ZN13SafeAllocator7DestroyEv(p+0x208);_ZN13SafeAllocator7DestroyEv(p+0x21c);_ZN13SafeAllocator7DestroyEv(p);
 _ZN13SafeAllocator7DestroyEv(p+0x230);_ZN13SafeAllocator7DestroyEv(p+0x244);_ZN13SafeAllocator7DestroyEv(p+0x258);_ZN13SafeAllocator7DestroyEv(p+0x26c);_ZN13SafeAllocator7DestroyEv(p+0x280);
 W(0x3d88)=0;W(0x3d8c)=0;W(0x3d90)=0;W(0x3d94)=0;W(0xe10)=0;
}
