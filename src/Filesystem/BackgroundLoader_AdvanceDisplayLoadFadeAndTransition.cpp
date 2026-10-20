#include <globaldefs.h>
#pragma opt_propagation off
#pragma optimize_for_size on
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "GameState/GameState.h"
extern "C" GameResources* GameResources_GetInstance();
extern "C" void BackgroundLoader_CancelTaskAndSelectNewHalfwordId(void*,int,int),Graphics_InitializeSpriteResourceBuffers(void*);
extern "C" int ResourceFile_CountActiveStrideRecords(void*);
extern "C" void* ResourceFile_GetPayloadByIndex(void*,int,void*,unsigned*);
extern "C" void Graphics_DispatchDataByResourceMagic(void*,void*,unsigned,SafeAllocator*);
extern "C" void Graphics_OffsetCellOamStartIndices(void*,unsigned,int,int),Graphics_SetCellAffineMode(void*,unsigned,int,int);
extern "C" void ResourceHandle_ApplyPreviousAndNewStateWithValue(void*,int,int),SoundSfx_StartCurrentGroupSequenceArchiveEntry(void*,int,int),SoundSfx_RestoreCurrentHeapState(void*);
extern "C" const char BackgroundLoader_AdvanceDisplayLoadFadeAndTransition_PathDataAniOqmsgGp2[],BackgroundLoader_AdvanceDisplayLoadFadeAndTransition_MarkupOqmsgLGPac[];
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x0208CFCC; symbol: func_0208cfcc; size: 0x374.
extern "C" ARM void BackgroundLoader_AdvanceDisplayLoadFadeAndTransition(unsigned char* self)
{
 char* owner=(char*)GameResources_GetInstance();BackgroundLoader* loader=BackgroundLoader::GetInstance();
 unsigned state=self[0xd5];
 if(state==0){
  unsigned short limit=300;
  bool ordinary=(*(unsigned short*)(self+0xda)&256)==0;bool special=ordinary==false;
  if(special)limit=150;
  if(*(unsigned short*)(self+0xd0)<limit) *(unsigned short*)(self+0xd0)+=GameState::GetInstance()->GetTickCount();
  else if(special){SetSubBrightness((GameResources*)owner,-4,4);*(int*)(self+0xc0)=loader->QueueLoadFileInGP2(BackgroundLoader_AdvanceDisplayLoadFadeAndTransition_PathDataAniOqmsgGp2,BackgroundLoader_AdvanceDisplayLoadFadeAndTransition_MarkupOqmsgLGPac,0);self[0xd5]++;}
  else {BackgroundLoader_CancelTaskAndSelectNewHalfwordId(self,*(short*)(self+0xd2),0);*(unsigned short*)(self+0xda)|=4;*(unsigned*)(self+0xc8)=0;self[0xd7]=0;self[0xd5]=2;}
 }else if(state==1){
  if(loader->GetTaskStatus(*(int*)(self+0xc0))){
   owner=*(char**)self;((SafeAllocator*)(owner+0x3c))->Reset();
   unsigned aux;void* file;unsigned size,value;
   loader->GetLoadedFileByID(*(int*)(self+0xc0),&file,&size);
   int count=ResourceFile_CountActiveStrideRecords(file);Graphics_InitializeSpriteResourceBuffers(self+0x60);
   self[0xb0]=1;*(unsigned*)(self+0xa0)=*(unsigned*)(self+0xb4);*(short*)(self+0xac)=3;
   for(int i=0;i<count;i++){void* item=ResourceFile_GetPayloadByIndex(file,i,&aux,&value);Graphics_DispatchDataByResourceMagic(self+0x60,item,value,(SafeAllocator*)(owner+0x3c));}
   Graphics_OffsetCellOamStartIndices(self+0x60,*(unsigned*)(self+0xb4),3,64);loader->RemoveTask(*(int*)(self+0xc0));
   *(int*)(self+0xc0)=-1;*(unsigned short*)(self+0xda)|=4;*(unsigned*)(self+0xc8)=0;self[0xd7]=0;self[0xd5]++;
  }
 }else if(state==2){
  if(!IsSubBrightnessTransitionActive(GameResources_GetInstance())){
   Graphics_SetCellAffineMode(self+0x60,*(unsigned*)(self+0xb4),1,1);Graphics_SetCellAffineMode(self+0x60,*(unsigned*)(self+0xb4)+40,1,1);
   self[0xd8]=0;*(float*)(self+0xcc)=0;*(unsigned short*)(self+0xda)&=~1;self[0xd5]++;
  }
 }else if(state==3){
  *(unsigned short*)(self+0xda)|=8;
  if(*(float*)(self+0xcc)<1.0f)*(float*)(self+0xcc)+=0.2f;
  else{*(float*)(self+0xcc)=1.0f;ResourceHandle_ApplyPreviousAndNewStateWithValue(Main_UnknownRoleZeroInitializedStorage,110,110);SoundSfx_StartCurrentGroupSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,0,0);self[0xd5]++;self[0xd9]=30;}
 }else if(state==4){*(unsigned short*)(self+0xda)|=128;self[0xd5]++;}
 else if(state==5){
  if(!(*(unsigned short*)(self+0xda)&128)){
   *(float*)(self+0xcc)+=0.2f;
   if(1.0f<*(float*)(self+0xcc)){*(float*)(self+0xcc)=1.0f;self[0xd5]++;}
  }
 }else if(state==6&&!*(signed char*)(self+0xd9)){SoundSfx_RestoreCurrentHeapState(Main_UnknownRoleZeroInitializedStorage);self[0xd4]=1;self[0xd5]=0;}
}
