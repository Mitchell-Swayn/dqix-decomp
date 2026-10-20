#include <globaldefs.h>
ARM
struct Canvas {unsigned char pad[28];unsigned char type:4,mode:4;unsigned char more[3];};
extern "C" {
void* _ZN9GameState11GetInstanceEv();
int GameState_ReadSupportedFirmwareLanguage(void*);
void* _ZN16BackgroundLoader11GetInstanceEv();
unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
void _ZN13SafeAllocator5ResetEv(void*);
char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
int ResourceFile_CountActiveStrideRecords(void*);
void Graphics_AllocateScreenDescriptors(void*,unsigned,void*);
void Graphics_InitializeCanvasTransferState(void*);
void Graphics_ClearScreenBuffer(void*,void*);
void Graphics_CleanAndTransferScreenBuffer(void*,void*);
void Graphics_SetTextBackgroundScreenSize(void*,unsigned);
void Graphics_AllocateAndClearConfiguredBuffer(void*,void*);
int Graphics_LoadTaggedLayerResource(void*,const void*,void*,unsigned);
void Graphics_SetBackgroundColorMode(void*,unsigned);
int Graphics_InvokeTwoIndexTransferCallback(void*,void*,void*);
void Graphics_CopyIndexedScreenRectangle(void*,unsigned,unsigned,unsigned,short,short,short,short,unsigned short);
void Graphics_UpdateBoundedSixteenByteEntry(void*,unsigned,unsigned,unsigned,unsigned short);
void TextCanvas_InitializeLayoutAndTransferDefaults(void*);
void TextCanvas_AllocateTilemapAndBindPixels(void*,void*,int,unsigned);
extern char Graphics_LoadLocalizedCanvasResources_PathDataAniBgSmlttlPac[],Graphics_LoadLocalizedCanvasResources_PathDataAniBgSmlitiPac[];
}
// Original: arm9/ov014 @ 0x021886F8; symbol: func_ov014_021886f8; size: 0x394.
extern "C" void Graphics_LoadLocalizedCanvasResources(unsigned char* self){
 unsigned char* resource;
 void* game=_ZN9GameState11GetInstanceEv();
 if(!(self[0x17e]&16))return;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(self[0x17c]==0){
  const char* filename=Graphics_LoadLocalizedCanvasResources_PathDataAniBgSmlttlPac;if(self[0x17a]==4)filename=Graphics_LoadLocalizedCanvasResources_PathDataAniBgSmlitiPac;
  *(unsigned*)(self+0x16c)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,filename,0);self[0x17c]++;return;
 }
 if(self[0x17c]!=1)return;
 if(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(unsigned*)(self+0x16c)))return;
 char* name;void* file;unsigned length;unsigned blocksize;Canvas temp;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(self+0x16c),&file,&length);
 int blocks=ResourceFile_CountActiveStrideRecords(file);
 resource=*(unsigned char**)(self+0xb4);
 _ZN13SafeAllocator5ResetEv(resource+20);
 Graphics_InitializeCanvasTransferState(&temp);
 Graphics_SetTextBackgroundScreenSize(&temp,0);
 temp.type=1;temp.mode=2;
 Graphics_SetBackgroundColorMode(&temp,2);
 Graphics_AllocateAndClearConfiguredBuffer(&temp,resource+20);
 Graphics_InvokeTwoIndexTransferCallback(&temp,0,0);
 Graphics_AllocateScreenDescriptors(&temp,5,resource+20);
 for(int i=1;i<blocks;i++){
  char* part=ResourceFile_GetPayloadByIndex((char*)file,i,&name,&blocksize);
  if(part)Graphics_LoadTaggedLayerResource(&temp,part,resource+20,blocksize);
 }
 _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0x16c));*(int*)(self+0x16c)=-1;
 int lang=GameState_ReadSupportedFirmwareLanguage(game);
 int language=0;
 switch(lang){
  case 2:language=1;break;case 4:language=2;break;case 3:language=3;break;case 5:language=4;break;
 }
 Graphics_ClearScreenBuffer(&temp,0);
 Graphics_UpdateBoundedSixteenByteEntry(&temp,0,0,0,0xffff);
 if(language)Graphics_CopyIndexedScreenRectangle(&temp,language,0,0,22,2,9,2,0xffff);
 Graphics_CleanAndTransferScreenBuffer(&temp,0);
 _ZN13SafeAllocator5ResetEv(resource+20);
 for(unsigned char i=0;i<2;i++){
  Canvas* canvas=(Canvas*)(*(char**)(self+0xc4)+i*32);
  Graphics_InitializeCanvasTransferState(canvas);
  canvas->type=1;canvas->mode=i;
  Graphics_SetTextBackgroundScreenSize(canvas,0);
  Graphics_SetBackgroundColorMode(canvas,i);
  Graphics_AllocateAndClearConfiguredBuffer(canvas,resource+20);
  Graphics_InvokeTwoIndexTransferCallback(canvas,0,0);
 }
 char* part=ResourceFile_GetPayloadByIndex((char*)file,0,&name,&blocksize);
 if(part)Graphics_LoadTaggedLayerResource(*(void**)(self+0xc4),part,resource+20,blocksize);
 for(unsigned char i=0;i<2;i++){
  Canvas* canvas=(Canvas*)(*(char**)(self+0xc4)+i*32);
  Graphics_ClearScreenBuffer(canvas,0);Graphics_CleanAndTransferScreenBuffer(canvas,0);
 }
 for(unsigned char i=0;i<4;i++){
  char* canvas=*(char**)(self+0xc8)+i*0xe0;
  TextCanvas_InitializeLayoutAndTransferDefaults(canvas);
  TextCanvas_AllocateTilemapAndBindPixels(canvas,resource+20,*(int*)(self+0xcc),0x600);
  *(void**)(canvas+4)=*(void**)(self+0xc4);
 }
 self[0x17c]=0;self[0x17e]&=~16;
}
