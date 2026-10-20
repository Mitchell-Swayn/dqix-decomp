#include <globaldefs.h>
#include <Resource/GameResources.h>
#include <Filesystem/BackgroundLoader.h>
#include <Memory/SafeAllocator.h>
#include <Filesystem/FileIO.h>
ARM
struct Record { signed char active; char reserved[0x47]; int stride; };
struct Owner;
struct State { unsigned char pad[28]; unsigned char first:4; unsigned char second:4; };
struct IndexedRecordView { unsigned char pad[0x10]; unsigned char* records; void* resource; unsigned char pad2[5]; unsigned char count; };
struct TilemapOwner { unsigned int field0[5]; unsigned short* tiles; };
extern "C" {
GameResources* GameResources_GetInstance();
void* _ZN16BackgroundLoader11GetInstanceEv();
int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,SafeAllocator*);
unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
void _ZN13SafeAllocator5ResetEv(void*);
int _Z28IsBrightnessTransitionActiveP13GameResources(void*);
void Window_PopCanvasesAndResetSelection(State*,int);
void* ResourceStringTable_GetTextByKey(void*,void*);
void Graphics_InitializeCanvasTransferState(char*);
void Graphics_SetTextBackgroundScreenSize(int,unsigned);
void Graphics_SetBackgroundColorMode(Owner*,unsigned);
int Graphics_InvokeTwoIndexTransferCallback(State*,void*,void*);
void Graphics_AllocateAndClearConfiguredBuffer(char*,SafeAllocator*);
void Graphics_AllocateScreenDescriptors(unsigned char*,unsigned,SafeAllocator*);
int ResourceFile_CountActiveStrideRecords(Record*);
char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
// The target caller supplies r3=size; sibling canvas loaders confirm this fourth ABI argument.
int Graphics_LoadTaggedLayerResource(Owner*,const void*,unsigned);
void Graphics_CopyIndexedScreenRectangle(IndexedRecordView*,unsigned,unsigned,unsigned,short,short,short,short,unsigned short);
void Tilemap_FillClippedRectangle(TilemapOwner*,unsigned,short,short,short,short,unsigned);
void Graphics_CleanAndTransferScreenBuffer(char*,void*);
void TextCanvas_AllocateTilemapAndBindPixels(char*,SafeAllocator*,int,unsigned);
void Selection_AttachBackwardLinkedDisplayRecords(unsigned char*,char*,unsigned char);
}
struct Nibbles {unsigned char low:4,high:4;};
#define I(o) (*(int*)(self+(o)))
#define B(o) (*(unsigned char*)(self+(o)))
// Original: arm9/ov008 @ 0x02188A54; symbol: func_ov008_02188a54; size: 0x320.
// Queues a selected archive, waits for brightness and loading, then initializes two canvases and six records.
extern "C" int Graphics_AdvanceArchiveCanvasInitialization(char* self,int alternate) {
 GameResources* resources=GameResources_GetInstance();
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 unsigned char state=B(0xb12);
 if(state==0) {
  int archive=1, file=2;
  if(alternate){archive=3;file=4;}
  const char* inner=(const char*)ResourceStringTable_GetTextByKey(self+0xa0,(void*)file);
  const char* outer=(const char*)ResourceStringTable_GetTextByKey(self+0xa0,(void*)archive);
  I(0xb20)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,outer,inner,0);
  B(0xb12)++;
 }
 if(state==1) {
  if(_Z28IsBrightnessTransitionActiveP13GameResources(resources))return 0;
  Window_PopCanvasesAndResetSelection((State*)(self+0x130),1);
  B(0xb12)++;
 }
 if(state==2 && _ZN16BackgroundLoader13GetTaskStatusEi(loader,I(0xb20))) {
  _ZN13SafeAllocator5ResetEv(self+0x14);
  Graphics_InitializeCanvasTransferState(self+0xf0);
  Graphics_SetTextBackgroundScreenSize((int)(self+0xf0),0);
  ((Nibbles*)(self+0x10c))->low=1;
  ((Nibbles*)(self+0x10c))->high=0;
  Graphics_SetBackgroundColorMode((Owner*)(self+0xf0),1);
  Graphics_InvokeTwoIndexTransferCallback((State*)(self+0xf0),0,0);
  Graphics_AllocateAndClearConfiguredBuffer(self+0xf0,(SafeAllocator*)(self+0x14));
  Graphics_AllocateScreenDescriptors((unsigned char*)self+0xf0,1,(SafeAllocator*)(self+0x14));
  Graphics_InitializeCanvasTransferState(self+0x110);
  Graphics_SetTextBackgroundScreenSize((int)(self+0x110),0);
  ((Nibbles*)(self+0x12c))->low=1;
  ((Nibbles*)(self+0x12c))->high=1;
  Graphics_SetBackgroundColorMode((Owner*)(self+0x110),0);
  Graphics_InvokeTwoIndexTransferCallback((State*)(self+0x110),0,0);
  Graphics_AllocateAndClearConfiguredBuffer(self+0x110,(SafeAllocator*)(self+0x14));
  char* block;char* data;unsigned length;unsigned size;
  _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,I(0xb20),(void**)&data,&length);
  int count=ResourceFile_CountActiveStrideRecords((Record*)data);
  for(int i=0;i<count;i++) {
   char* resource=ResourceFile_GetPayloadByIndex(data,i,&block,&size);
   if(resource) {
    if(i==count-1)((int(*)(Owner*,const void*,unsigned,unsigned))Graphics_LoadTaggedLayerResource)((Owner*)(self+0x110),resource,(unsigned)(self+0x14),size);
    else ((int(*)(Owner*,const void*,unsigned,unsigned))Graphics_LoadTaggedLayerResource)((Owner*)(self+0xf0),resource,(unsigned)(self+0x14),size);
   }
  }
  _ZN16BackgroundLoader10RemoveTaskEi(loader,I(0xb20));
  I(0xb20)=-1;
  Graphics_CopyIndexedScreenRectangle((IndexedRecordView*)(self+0xf0),0,0,0,0,0,32,24,65535);
  Graphics_CleanAndTransferScreenBuffer(self+0xf0,0);
  Tilemap_FillClippedRectangle((TilemapOwner*)(self+0x110),0,0,0,32,25,0);
  Graphics_CleanAndTransferScreenBuffer(self+0x110,0);
  char* record;
  for(int i=0;i<6;i++) {
   record=self+0x1ec+i*224;
   TextCanvas_AllocateTilemapAndBindPixels(record,(SafeAllocator*)(self+0x14),I(0x72c),512);
   *(char**)(record+4)=self+0x110;
  }
  *(char**)(self+0x1c8)=self+0x110;
  B(0x1e2)=1;
  Selection_AttachBackwardLinkedDisplayRecords((unsigned char*)self+0x130,self+0x1ec,6);
  B(0xb12)=0;
  return 1;
 }
 return 0;
}
