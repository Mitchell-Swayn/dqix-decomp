#include <globaldefs.h>
ARM
struct Nibbles {unsigned char type:4,mode:4;};
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

}
extern "C" {
void MapVRAMBanksToMainBG(int);void MapVRAMBanksToSubBG(int);
void ConfigureBackgroundLayerOneControlBits(unsigned,unsigned,unsigned,unsigned,unsigned);
void Graphics_SetDisplayControlBits(int,int,int,int,int);
void _ZN16BackgroundLoader31ResetQueuedTasksAndScratchUsageEv(void*);void _ZN16BackgroundLoader14RemoveAllLocksEv(void*);
void ColorEffect_ConfigureAlphaBlend(unsigned,unsigned,unsigned,unsigned,unsigned);
void Graphics_WriteSignedBrightnessMagnitudeAndMode(unsigned short*,int);
extern char Graphics_LoadDualScreenCanvasResources_PathDataAniBgTitlePac[];
}
struct Triple {int v[3];};
// Original data: arm9/ov020 @ 0x218d95c; symbol: data_ov020_0218d95c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000200000003000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov020.md.
// Original data: arm9/ov020 @ 0x218d968; symbol: data_ov020_0218d968.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 010000000200000004000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov020.md.
extern "C" Triple GraphicsLoadDualScreenCanvasResources_UnknownRoleInitializedBytes,GraphicsLoadDualScreenCanvasResources_UnknownRoleInitializedBytes_Variant2;
// Original: arm9/ov020 @ 0x0218C98C; symbol: func_ov020_0218c98c; size: 0x3D8.
extern "C" void Graphics_LoadDualScreenCanvasResources(unsigned char* self){
 _ZN13SafeAllocator5ResetEv(self+0x470);
 MapVRAMBanksToMainBG(8);
 ConfigureBackgroundLayerOneControlBits(0,1,1,1,0);
 Graphics_InitializeCanvasTransferState(self+0x49c);
 Graphics_SetTextBackgroundScreenSize(self+0x49c,0);
 ((Nibbles*)(self+0x4b8))->type=0;((Nibbles*)(self+0x4b8))->mode=1;
 Graphics_SetBackgroundColorMode(self+0x49c,1);
 Graphics_AllocateAndClearConfiguredBuffer(self+0x49c,self+0x470);
 Graphics_AllocateScreenDescriptors(self+0x49c,1,self+0x470);
 Graphics_InvokeTwoIndexTransferCallback(self+0x49c,0,0);
 MapVRAMBanksToSubBG(4);
 Graphics_SetDisplayControlBits(0,1,1,1,0);
 Graphics_InitializeCanvasTransferState(self+0x4bc);
 Graphics_SetTextBackgroundScreenSize(self+0x4bc,0);
 ((Nibbles*)(self+0x4d8))->type=1;((Nibbles*)(self+0x4d8))->mode=0;
 Graphics_SetBackgroundColorMode(self+0x4bc,0);
 Graphics_AllocateAndClearConfiguredBuffer(self+0x4bc,self+0x470);
 Graphics_AllocateScreenDescriptors(self+0x4bc,1,self+0x470);
 Graphics_InvokeTwoIndexTransferCallback(self+0x4bc,0,0);
 int task;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 _ZN16BackgroundLoader31ResetQueuedTasksAndScratchUsageEv(loader);
 task=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Graphics_LoadDualScreenCanvasResources_PathDataAniBgTitlePac,0);
 while(1){if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,task)){
 void* blocks[5];unsigned lengths[5];Triple mainMap,subMap;char* name;void* file;unsigned length;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,task,&file,&length);
 int count=ResourceFile_CountActiveStrideRecords(file);
 for(int i=0;i<count;i++)blocks[i]=ResourceFile_GetPayloadByIndex((char*)file,i,&name,&lengths[i]);
 mainMap=GraphicsLoadDualScreenCanvasResources_UnknownRoleInitializedBytes;subMap=GraphicsLoadDualScreenCanvasResources_UnknownRoleInitializedBytes_Variant2;
 int mainIndex=0,subIndex=0;
 for(int i=0;i<count;i++){
  if(i==mainMap.v[mainIndex]){Graphics_LoadTaggedLayerResource(self+0x49c,blocks[i],self+0x470,lengths[i]);mainIndex++;}
  if(i==subMap.v[subIndex]){Graphics_LoadTaggedLayerResource(self+0x4bc,blocks[i],self+0x470,lengths[i]);subIndex++;}
 }
 _ZN16BackgroundLoader10RemoveTaskEi(loader,task);
 Graphics_CopyIndexedScreenRectangle(self+0x49c,0,0,0,0,0,32,25,0);
 Graphics_CopyIndexedScreenRectangle(self+0x4bc,0,0,0,0,0,32,25,0);
 Graphics_CleanAndTransferScreenBuffer(self+0x49c,0);
 Graphics_CleanAndTransferScreenBuffer(self+0x4bc,0);
 break;}else _ZN16BackgroundLoader14RemoveAllLocksEv(loader);}
 *(volatile unsigned short*)0x04000050=0;*(volatile unsigned short*)0x04001050=0;
 ColorEffect_ConfigureAlphaBlend(0x04000050,1,2,15,31);
 ColorEffect_ConfigureAlphaBlend(0x04001050,1,2,31,0);
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|0x300;
 *(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x100;
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,0);
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,0);
}
