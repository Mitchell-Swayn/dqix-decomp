#include <globaldefs.h>
ARM
struct Record;struct SafeAllocator;struct Owner;struct State;struct IndexedRecordView;
extern "C" void Graphics_WriteSignedBrightnessMagnitudeAndMode(unsigned short*,int);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void Graphics_SetDisplayControlBits(int,int,int,int,int);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void Graphics_SetTextBackgroundScreenSize(int,unsigned);
extern "C" void Graphics_SetBackgroundColorMode(Owner*,unsigned);
extern "C" void Graphics_AllocateAndClearConfiguredBuffer(char*,SafeAllocator*);
extern "C" void Graphics_AllocateScreenDescriptors(unsigned char*,unsigned,SafeAllocator*);
extern "C" int Graphics_InvokeTwoIndexTransferCallback(State*,void*,void*);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);
extern "C" int ResourceFile_CountActiveStrideRecords(Record*);
extern "C" char* ResourceFile_GetPayloadByIndex(char*,int,char**,unsigned*);
extern "C" int Graphics_LoadTaggedLayerResource(void*,const void*,unsigned,unsigned);
extern "C" void Graphics_CopyIndexedScreenRectangle(IndexedRecordView*,unsigned,unsigned,unsigned,short,short,short,short,unsigned short);
extern "C" void Graphics_CleanAndTransferScreenBuffer(char*,void*);
// Original data: arm9/main @ 0x211e33c; symbol: data_0211e33c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 7889 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Graphics_InitializeSubBackgroundCanvasAndDisplay_PathDataMenuNintendoPac[],Main_UnknownRoleZeroInitializedStorage_Variant6[];
struct Nibbles{unsigned char low:4,high:4;};
struct Canvas{char pad[0x1c];Nibbles flags;};
// Original: arm9/ov020 @ 0x0218CD98; symbol: func_ov020_0218cd98; size: 0x1F4.
extern "C" void Graphics_InitializeSubBackgroundCanvasAndDisplay(char* p) {
 unsigned fileSize;unsigned blockSize;char* block;
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,-16);
 _ZN13SafeAllocator5ResetEv(p+0x470);
 MapVRAMBanksToSubBG(4);
 Graphics_SetDisplayControlBits(0,1,1,1,0);
 Graphics_InitializeCanvasTransferState(p+0x4bc);
 Graphics_SetTextBackgroundScreenSize((int)(p+0x4bc),0);
 ((Canvas*)(p+0x4bc))->flags.low=1;
 ((Canvas*)(p+0x4bc))->flags.high=0;
 Graphics_SetBackgroundColorMode((Owner*)(p+0x4bc),0);
 Graphics_AllocateAndClearConfiguredBuffer(p+0x4bc,(SafeAllocator*)(p+0x470));
 Graphics_AllocateScreenDescriptors((unsigned char*)p+0x4bc,1,(SafeAllocator*)(p+0x470));
 Graphics_InvokeTwoIndexTransferCallback((State*)(p+0x4bc),0,0);
 _ZN16BackgroundLoader13AddLockGlobalEv();
 fileSize=0;
 _Z18LoadFileIntoMemoryPKcPvPj(Graphics_InitializeSubBackgroundCanvasAndDisplay_PathDataMenuNintendoPac,Main_UnknownRoleZeroInitializedStorage_Variant6,&fileSize);
 int count=ResourceFile_CountActiveStrideRecords((Record*)Main_UnknownRoleZeroInitializedStorage_Variant6);
 for(int i=0;i<count;i++) {
  char* data=ResourceFile_GetPayloadByIndex(Main_UnknownRoleZeroInitializedStorage_Variant6,i,&block,&blockSize);
  if(data)Graphics_LoadTaggedLayerResource((Owner*)(p+0x4bc),data,(unsigned)((SafeAllocator*)(p+0x470)),blockSize);
 }
 Graphics_CopyIndexedScreenRectangle((IndexedRecordView*)(p+0x4bc),0,0,0,0,0,32,24,0xffff);
 Graphics_CleanAndTransferScreenBuffer(p+0x4bc,0);
 _ZN16BackgroundLoader16RemoveLockGlobalEv();
 *(volatile unsigned short*)0x04000050=0;
 *(volatile unsigned short*)0x04001050=0;
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|0x1300;
 *(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x100;
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,-16);
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,-16);
}
