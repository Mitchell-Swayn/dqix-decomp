#include <globaldefs.h>
ARM
struct Nibbles {unsigned char lo:4,hi:4;};
struct Triple {int v[3];};
extern "C" {
void _ZN13SafeAllocator5ResetEv(void*);
void MapVRAMBanksToMainBG(int);
void MapVRAMBanksToSubBG(int);
void ConfigureBackgroundLayerOneControlBits(unsigned,unsigned,unsigned,unsigned,unsigned);
void Graphics_SetDisplayControlBits(int,int,int,int,int);
void Graphics_InitializeCanvasTransferState(char*);
void Graphics_SetTextBackgroundScreenSize(int,unsigned);
void Graphics_SetBackgroundColorMode(void*,unsigned);
void Graphics_AllocateAndClearConfiguredBuffer(char*,void*);
void Graphics_AllocateScreenDescriptors(unsigned char*,unsigned,void*);
int Graphics_InvokeTwoIndexTransferCallback(void*,void*,void*);
void* _ZN16BackgroundLoader11GetInstanceEv();
void _ZN16BackgroundLoader31ResetQueuedTasksAndScratchUsageEv(void*);
unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
void _ZN16BackgroundLoader14RemoveAllLocksEv(void*);
void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
int ResourceFile_CountActiveStrideRecords(void*);
char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
int Graphics_LoadTaggedLayerResource(void*,const void*,unsigned,...);
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
void Graphics_CopyIndexedScreenRectangle(void*,unsigned,unsigned,unsigned,short,short,short,short,unsigned short);
void Graphics_CleanAndTransferScreenBuffer(char*,void*);
void Graphics_WriteSignedBrightnessMagnitudeAndMode(unsigned short*,int);
extern char Graphics_InitializeDualScreenCanvasResources_PathDataMenuBgMobi2Pac[];
// Original data: arm9/ov020 @ 0x218d944; symbol: data_ov020_0218d944.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 010000000300000005000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov020.md.
// Original data: arm9/ov020 @ 0x218d950; symbol: data_ov020_0218d950.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000200000004000000.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov020.md.
extern const Triple GraphicsInitializeDualScreenCanvasResources_UnknownRoleInitializedBytes_Variant2,GraphicsInitializeDualScreenCanvasResources_UnknownRoleInitializedBytes;
}
// Original: arm9/ov020 @ 0x0218CF8C; symbol: func_ov020_0218cf8c; size: 0x3A0.
extern "C" void Graphics_InitializeDualScreenCanvasResources(char* p){
 _ZN13SafeAllocator5ResetEv(p+0x470);
 MapVRAMBanksToMainBG(8);
 ConfigureBackgroundLayerOneControlBits(0,0,31,2,0);
 Graphics_InitializeCanvasTransferState(p+0x49c);
 Graphics_SetTextBackgroundScreenSize((int)(p+0x49c),0);
 ((Nibbles*)(p+0x4b8))->lo=0;((Nibbles*)(p+0x4b8))->hi=1;
 Graphics_SetBackgroundColorMode(p+0x49c,0);
 Graphics_AllocateAndClearConfiguredBuffer(p+0x49c,p+0x470);
 Graphics_AllocateScreenDescriptors((unsigned char*)p+0x49c,1,p+0x470);
 Graphics_InvokeTwoIndexTransferCallback(p+0x49c,0,0);
 MapVRAMBanksToSubBG(4);
 Graphics_SetDisplayControlBits(0,0,1,1,0);
 Graphics_InitializeCanvasTransferState(p+0x4bc);
 Graphics_SetTextBackgroundScreenSize((int)(p+0x4bc),0);
 ((Nibbles*)(p+0x4d8))->lo=1;((Nibbles*)(p+0x4d8))->hi=0;
 Graphics_SetBackgroundColorMode(p+0x4bc,0);
 Graphics_AllocateAndClearConfiguredBuffer(p+0x4bc,p+0x470);
 Graphics_AllocateScreenDescriptors((unsigned char*)p+0x4bc,1,p+0x470);
 Graphics_InvokeTwoIndexTransferCallback(p+0x4bc,0,0);
 int id;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 _ZN16BackgroundLoader31ResetQueuedTasksAndScratchUsageEv(loader);
 id=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,Graphics_InitializeDualScreenCanvasResources_PathDataMenuBgMobi2Pac,0);
 while(1){
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,id)){
 char* out; void* file;unsigned length;char* blocks[6];unsigned sizes[6];
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,id,&file,&length);
 int count=ResourceFile_CountActiveStrideRecords(file);
 for(int i=0;i<count;i++)blocks[i]=ResourceFile_GetPayloadByIndex((char*)file,i,&out,&sizes[i]);
 Triple mainIndices=GraphicsInitializeDualScreenCanvasResources_UnknownRoleInitializedBytes_Variant2;
 Triple subIndices=GraphicsInitializeDualScreenCanvasResources_UnknownRoleInitializedBytes;
 int mainIndex=0,subIndex=0;
 for(int i=0;i<count;i++){
 if(i==mainIndices.v[mainIndex]){Graphics_LoadTaggedLayerResource(p+0x49c,blocks[i],(unsigned)(p+0x470),sizes[i]);mainIndex++;}
 if(i==subIndices.v[subIndex]){Graphics_LoadTaggedLayerResource(p+0x4bc,blocks[i],(unsigned)(p+0x470),sizes[i]);subIndex++;}
 }
 _ZN16BackgroundLoader10RemoveTaskEi(loader,id);
 Graphics_CopyIndexedScreenRectangle(p+0x49c,0,0,0,0,0,32,25,0);
 Graphics_CopyIndexedScreenRectangle(p+0x4bc,0,0,0,0,0,32,25,0);
 Graphics_CleanAndTransferScreenBuffer(p+0x49c,0);
 Graphics_CleanAndTransferScreenBuffer(p+0x4bc,0);
 break;
 }
 _ZN16BackgroundLoader14RemoveAllLocksEv(loader);
 }
 *(volatile unsigned short*)0x04000050=0;
 *(volatile unsigned short*)0x04001050=0;
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|0x200;
 *(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x100;
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,-16);
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,-16);
}
