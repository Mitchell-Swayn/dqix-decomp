#include <globaldefs.h>
ARM
struct Format {unsigned char low:4,high:4;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadPResources(void*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*,int,int);
extern "C" bool _Z31IsSubBrightnessTransitionActiveP13GameResources(void*);
extern "C" void* SystemState_GetGlobalFlags();
extern "C" void SystemState_SetFlags(void*,unsigned);
extern "C" void GameState_EnableGlobalFlag64();
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void Graphics_SetTextBackgroundScreenSize(void*,unsigned);
extern "C" void Graphics_SetBackgroundColorMode(void*,unsigned);
extern "C" int Graphics_InvokeTwoIndexTransferCallback(void*,void*,void*);
extern "C" void Graphics_AllocateScreenDescriptors(void*,unsigned,void*);
extern "C" void Graphics_AllocateAndClearConfiguredBuffer(void*,void*);
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" int ResourceFile_CountActiveStrideRecords(void*);
extern "C" void* ResourceFile_GetPayloadByIndex(void*,int,void**,unsigned*);
extern "C" int Graphics_LoadTaggedLayerResource(void*,const void*,unsigned,unsigned);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void Graphics_ClearScreenBuffer(void*,void*);
extern "C" void Graphics_UpdateBoundedSixteenByteEntry(void*,int,int,int,unsigned short);
extern "C" void Graphics_CleanAndTransferScreenBuffer(void*,void*);
extern "C" char Alltrades_AdvanceVocationStatPreview_PathDataAniBgdsGp2[],Alltrades_AdvanceVocationStatPreview_MarkupBgdsLGPac[];
// Original: arm9/ov003 @ 0x021541B0; symbol: func_ov003_021541b0; size: 0x2A0.
extern "C" void Graphics_LoadSubBackgroundResourceAfterFade(char* self) {
 void* resources=GameState_ReadPResources(_ZN9GameState11GetInstanceEv());
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(*(unsigned char*)(self+0x5b)==0) {
 int valid=0;int choice=*(signed char*)(self+0x59);
 if(choice>=0&&choice<=3)valid=1;
 if(valid) {
 self[0x58]=1;_Z16SetSubBrightnessP13GameResourcesii(resources,-16,1);
 ++*(unsigned char*)(self+0x5b);
 }
 } else if(*(unsigned char*)(self+0x5b)==1) {
 if(!_Z31IsSubBrightnessTransitionActiveP13GameResources(resources)) {
 SystemState_SetFlags(SystemState_GetGlobalFlags(),1);
 GameState_EnableGlobalFlag64();
 ++*(unsigned char*)(self+0x5b);
 }
 } else if(*(unsigned char*)(self+0x5b)==2) {
 volatile unsigned short* bg=(volatile unsigned short*)0x04001008;
 bg[0]=(bg[0]&0x43)|0xf00;
 bg[0]&=~3;bg[1]=(bg[1]&~3)|1;bg[2]=(bg[2]&~3)|2;bg[3]=(bg[3]&~3)|3;
 *(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x1100;
 void* allocator=*(void**)self;
 _ZN13SafeAllocator5ResetEv(allocator);
 ((Format*)(self+0x34))->low=1;((Format*)(self+0x34))->high=0;
 Graphics_SetTextBackgroundScreenSize(self+0x18,0);
 Graphics_SetBackgroundColorMode(self+0x18,0);
 Graphics_InvokeTwoIndexTransferCallback(self+0x18,0,0);
 Graphics_AllocateScreenDescriptors(self+0x18,14,allocator);
 Graphics_AllocateAndClearConfiguredBuffer(self+0x18,allocator);
 *(int*)(self+0x50)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,Alltrades_AdvanceVocationStatPreview_PathDataAniBgdsGp2,Alltrades_AdvanceVocationStatPreview_MarkupBgdsLGPac,0);
 ++*(unsigned char*)(self+0x5b);
 } else if(*(unsigned char*)(self+0x5b)==3) {
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(self+0x50))) {
 void* allocator=*(void**)self;
 void* out;void* file;unsigned fileSize;unsigned blockSize;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(self+0x50),&file,&fileSize);
 int count=ResourceFile_CountActiveStrideRecords(file);
 for(int i=0;i<count;i++) {
 void* block=ResourceFile_GetPayloadByIndex(file,i,&out,&blockSize);
 Graphics_LoadTaggedLayerResource(self+0x18,block,(unsigned)(allocator),blockSize);
 }
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0x50));
 *(int*)(self+0x50)=-1;
 Graphics_ClearScreenBuffer(self+0x18,0);
 Graphics_UpdateBoundedSixteenByteEntry(self+0x18,0,0,0,0xffff);
 Graphics_CleanAndTransferScreenBuffer(self+0x18,0);
 self[0x5a]=1;self[0x5b]=0;
 *(unsigned char*)(self+0x5d)|=2;
 }
 }
}
