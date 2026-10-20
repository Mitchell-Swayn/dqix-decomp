#include <globaldefs.h>
ARM
struct GameState;
extern "C" {
void* __clear(void*,unsigned);
void* _ZN9GameState11GetInstanceEv();
void GameState_SetUnknown3b0(GameState*,void*);
void* _ZN16BackgroundLoader11GetInstanceEv();
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
void _ZN13SafeAllocator7DestroyEv(void*);
void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
void _ZN8Object3D7DestroyEv(void*);
void ResourceLoader_ResetPresentationOwner(int);
void InitializeSceneResourceOwner(unsigned char*);
void KrakPot_ResetItemPreviewSprites(unsigned char*);
void Resource_DestroyAndResetSharedRecordState(char*);
}
// Original: arm9/ov006 @ 0x021547C8; symbol: func_ov006_021547c8; size: 0x1E4.
// Releases scene tasks, allocators and models, restores the prior game-state object and resets ownership.
extern "C" void DestroySceneResourceOwnerAndReset(unsigned char* self) {
 Resource_DestroyAndResetSharedRecordState((char*)self+0xae4);
 KrakPot_ResetItemPreviewSprites(self);
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(*(int*)(self+0xad4)>=0) {_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0xad4));*(int*)(self+0xad4)=-1;}
 if(*(int*)(self+0xad8)>=0) {_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0xad8));*(int*)(self+0xad8)=-1;}
 if(_ZNK13SafeAllocator18GetSignedAllocatorEv(self+0x18c)) _ZN13SafeAllocator7DestroyEv(self+0x18c);
 void* allocators[7];__clear(allocators,28);
 allocators[0]=*(void**)(self+0x184);allocators[1]=*(void**)(self+0x188);
 allocators[2]=*(void**)(self+0x184);allocators[3]=*(void**)(self+0x188);
 allocators[4]=*(void**)(self+0x1280);allocators[5]=*(void**)(self+0x1284);
 for(unsigned char i=0;allocators[i];++i) if(_ZNK13SafeAllocator18GetSignedAllocatorEv(allocators[i])) _ZN13SafeAllocator7DestroyEv(allocators[i]);
 for(unsigned char i=0;i<6;++i) {
  unsigned offset=i*20;
  if(_ZNK13SafeAllocator18GetSignedAllocatorEv(*(unsigned char**)(self+0x180)+offset)) _ZN13SafeAllocator7DestroyEv(*(unsigned char**)(self+0x180)+offset);
 }
 for(unsigned char i=0;i<4;++i) {
  unsigned offset=i*20;
  if(_ZNK13SafeAllocator18GetSignedAllocatorEv(self+0xa84+offset)) _ZN13SafeAllocator7DestroyEv(self+0xa84+offset);
 }
 if(*(void**)(self+0x1a0)) {GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();GameState_SetUnknown3b0(game,*(void**)(self+0x1a0));*(void**)(self+0x1a0)=0;}
 if(!(*(unsigned short*)(self+0xae2)&8)) {
  _ZN8Object3D7DestroyEv(self+0x238);_ZN8Object3D7DestroyEv(self+0x2e4);_ZN8Object3D7DestroyEv(self+0x390);_ZN8Object3D7DestroyEv(self+0x43c);_ZN8Object3D7DestroyEv(self+0x4e8);
 }
 ResourceLoader_ResetPresentationOwner((int)(self+0x12a0));
 InitializeSceneResourceOwner(self);
}
