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
char* FindVariableLengthBlockByIndex(char*,int,char**,unsigned*);
int ResourceFile_CountActiveStrideRecords(void*);
void AllocateSixteenByteRecordArrayWhenAllocatorPresent(void*,unsigned,void*);
void Graphics_InitializeCanvasTransferState(void*);
void ClearSelectedBufferUsingFormatSizeTable(void*,void*);
void UpdateProvidedOrStoredChildResource(void*,void*);
void SetWordField18AndClearFormatByte1F(void*,unsigned);
void Graphics_AllocateAndClearConfiguredBuffer(void*,void*);
int DispatchResourceLoadByFourByteTag(void*,const void*,void*,unsigned);
void DispatchModeThroughTwoDimensionalFlagTable(void*,unsigned);
int Graphics_InvokeTwoIndexTransferCallback(void*,void*,void*);
void DispatchIndexedRecordWithCoordinates(void*,unsigned,unsigned,unsigned,short,short,short,short,unsigned short);
void Graphics_UpdateBoundedSixteenByteEntry(void*,unsigned,unsigned,unsigned,unsigned short);
void TextCanvas_InitializeLayoutAndTransferDefaults(void*);
void Object_AllocateOffsetD4BufferAndStoreWord8(void*,void*,int,unsigned);

}
extern "C" {
void MapVRAMBanksToMainBG(int);void MapVRAMBanksToSubBG(int);
void func_ov020_0218c7bc(unsigned,unsigned,unsigned,unsigned,unsigned);
void Graphics_SetDisplayControlBits(int,int,int,int,int);
void _ZN16BackgroundLoader10MaybeResetEv(void*);void _ZN16BackgroundLoader14RemoveAllLocksEv(void*);
void ColorEffect_ConfigureAlphaBlend(unsigned,unsigned,unsigned,unsigned,unsigned);
void Graphics_WriteSignedBrightnessMagnitudeAndMode(unsigned short*,int);
extern char data_ov020_0218dc9d[];
}
struct Triple {int v[3];};
extern "C" Triple data_ov020_0218d95c,data_ov020_0218d968;
// Original: arm9/ov020 @ 0x0218C98C; symbol: func_ov020_0218c98c; size: 0x3D8.
extern "C" void Graphics_LoadDualScreenCanvasResources(unsigned char* self){
 _ZN13SafeAllocator5ResetEv(self+0x470);
 MapVRAMBanksToMainBG(8);
 func_ov020_0218c7bc(0,1,1,1,0);
 Graphics_InitializeCanvasTransferState(self+0x49c);
 SetWordField18AndClearFormatByte1F(self+0x49c,0);
 ((Nibbles*)(self+0x4b8))->type=0;((Nibbles*)(self+0x4b8))->mode=1;
 DispatchModeThroughTwoDimensionalFlagTable(self+0x49c,1);
 Graphics_AllocateAndClearConfiguredBuffer(self+0x49c,self+0x470);
 AllocateSixteenByteRecordArrayWhenAllocatorPresent(self+0x49c,1,self+0x470);
 Graphics_InvokeTwoIndexTransferCallback(self+0x49c,0,0);
 MapVRAMBanksToSubBG(4);
 Graphics_SetDisplayControlBits(0,1,1,1,0);
 Graphics_InitializeCanvasTransferState(self+0x4bc);
 SetWordField18AndClearFormatByte1F(self+0x4bc,0);
 ((Nibbles*)(self+0x4d8))->type=1;((Nibbles*)(self+0x4d8))->mode=0;
 DispatchModeThroughTwoDimensionalFlagTable(self+0x4bc,0);
 Graphics_AllocateAndClearConfiguredBuffer(self+0x4bc,self+0x470);
 AllocateSixteenByteRecordArrayWhenAllocatorPresent(self+0x4bc,1,self+0x470);
 Graphics_InvokeTwoIndexTransferCallback(self+0x4bc,0,0);
 int task;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 _ZN16BackgroundLoader10MaybeResetEv(loader);
 task=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,data_ov020_0218dc9d,0);
 while(1){if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,task)){
 void* blocks[5];unsigned lengths[5];Triple mainMap,subMap;char* name;void* file;unsigned length;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,task,&file,&length);
 int count=ResourceFile_CountActiveStrideRecords(file);
 for(int i=0;i<count;i++)blocks[i]=FindVariableLengthBlockByIndex((char*)file,i,&name,&lengths[i]);
 mainMap=data_ov020_0218d95c;subMap=data_ov020_0218d968;
 int mainIndex=0,subIndex=0;
 for(int i=0;i<count;i++){
  if(i==mainMap.v[mainIndex]){DispatchResourceLoadByFourByteTag(self+0x49c,blocks[i],self+0x470,lengths[i]);mainIndex++;}
  if(i==subMap.v[subIndex]){DispatchResourceLoadByFourByteTag(self+0x4bc,blocks[i],self+0x470,lengths[i]);subIndex++;}
 }
 _ZN16BackgroundLoader10RemoveTaskEi(loader,task);
 DispatchIndexedRecordWithCoordinates(self+0x49c,0,0,0,0,0,32,25,0);
 DispatchIndexedRecordWithCoordinates(self+0x4bc,0,0,0,0,0,32,25,0);
 UpdateProvidedOrStoredChildResource(self+0x49c,0);
 UpdateProvidedOrStoredChildResource(self+0x4bc,0);
 break;}else _ZN16BackgroundLoader14RemoveAllLocksEv(loader);}
 *(volatile unsigned short*)0x04000050=0;*(volatile unsigned short*)0x04001050=0;
 ColorEffect_ConfigureAlphaBlend(0x04000050,1,2,15,31);
 ColorEffect_ConfigureAlphaBlend(0x04001050,1,2,31,0);
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|0x300;
 *(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x100;
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,0);
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,0);
}
