#include <globaldefs.h>
#pragma opt_propagation off
#pragma optimize_for_size on
#include "Filesystem/BackgroundLoader.h"
#include "Resource/Brightness.h"
#include "GameState/GameState.h"
extern "C" GameResources* GameResources_GetInstance();
extern "C" void BackgroundLoader_CancelTaskAndSelectNewHalfwordId(void*,int,int),InitializeRecordBuffersAndEnabledByte(void*);
extern "C" int ResourceFile_CountActiveStrideRecords(void*);
extern "C" void* FindVariableLengthBlockByIndex(void*,int,void*,unsigned*);
extern "C" void Graphics_DispatchDataByResourceMagic(void*,void*,unsigned,SafeAllocator*);
extern "C" void AdvanceRecordByte22Modulo128(void*,unsigned,int,int),Object_ApplyRecordConfigurationAndStoreTwoBytes(void*,unsigned,int,int);
extern "C" void ResourceHandle_ApplyPreviousAndNewStateWithValue(void*,int,int),DispatchNonnegativeStoredIndexWithTwoArguments(void*,int,int),InvokeObjectWithStoredFieldC0(void*);
extern "C" const char data_020f11eb[],data_020f11fe[];
extern "C" char data_02108760[];
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
  else if(special){SetSubBrightness((GameResources*)owner,-4,4);*(int*)(self+0xc0)=loader->QueueLoadFileInGP2(data_020f11eb,data_020f11fe,0);self[0xd5]++;}
  else {BackgroundLoader_CancelTaskAndSelectNewHalfwordId(self,*(short*)(self+0xd2),0);*(unsigned short*)(self+0xda)|=4;*(unsigned*)(self+0xc8)=0;self[0xd7]=0;self[0xd5]=2;}
 }else if(state==1){
  if(loader->GetTaskStatus(*(int*)(self+0xc0))){
   owner=*(char**)self;((SafeAllocator*)(owner+0x3c))->Reset();
   unsigned aux;void* file;unsigned size,value;
   loader->GetLoadedFileByID(*(int*)(self+0xc0),&file,&size);
   int count=ResourceFile_CountActiveStrideRecords(file);InitializeRecordBuffersAndEnabledByte(self+0x60);
   self[0xb0]=1;*(unsigned*)(self+0xa0)=*(unsigned*)(self+0xb4);*(short*)(self+0xac)=3;
   for(int i=0;i<count;i++){void* item=FindVariableLengthBlockByIndex(file,i,&aux,&value);Graphics_DispatchDataByResourceMagic(self+0x60,item,value,(SafeAllocator*)(owner+0x3c));}
   AdvanceRecordByte22Modulo128(self+0x60,*(unsigned*)(self+0xb4),3,64);loader->RemoveTask(*(int*)(self+0xc0));
   *(int*)(self+0xc0)=-1;*(unsigned short*)(self+0xda)|=4;*(unsigned*)(self+0xc8)=0;self[0xd7]=0;self[0xd5]++;
  }
 }else if(state==2){
  if(!IsSubBrightnessTransitionActive(GameResources_GetInstance())){
   Object_ApplyRecordConfigurationAndStoreTwoBytes(self+0x60,*(unsigned*)(self+0xb4),1,1);Object_ApplyRecordConfigurationAndStoreTwoBytes(self+0x60,*(unsigned*)(self+0xb4)+40,1,1);
   self[0xd8]=0;*(float*)(self+0xcc)=0;*(unsigned short*)(self+0xda)&=~1;self[0xd5]++;
  }
 }else if(state==3){
  *(unsigned short*)(self+0xda)|=8;
  if(*(float*)(self+0xcc)<1.0f)*(float*)(self+0xcc)+=0.2f;
  else{*(float*)(self+0xcc)=1.0f;ResourceHandle_ApplyPreviousAndNewStateWithValue(data_02108760,110,110);DispatchNonnegativeStoredIndexWithTwoArguments(data_02108760,0,0);self[0xd5]++;self[0xd9]=30;}
 }else if(state==4){*(unsigned short*)(self+0xda)|=128;self[0xd5]++;}
 else if(state==5){
  if(!(*(unsigned short*)(self+0xda)&128)){
   *(float*)(self+0xcc)+=0.2f;
   if(1.0f<*(float*)(self+0xcc)){*(float*)(self+0xcc)=1.0f;self[0xd5]++;}
  }
 }else if(state==6&&!*(signed char*)(self+0xd9)){InvokeObjectWithStoredFieldC0(data_02108760);self[0xd4]=1;self[0xd5]=0;}
}
