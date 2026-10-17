#include <globaldefs.h>
ARM
struct Record;struct SafeAllocator;struct Owner;struct State;struct IndexedRecordView;
extern "C" void Graphics_WriteSignedBrightnessMagnitudeAndMode(unsigned short*,int);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void Graphics_SetDisplayControlBits(int,int,int,int,int);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void SetWordField18AndClearFormatByte1F(int,unsigned);
extern "C" void DispatchModeThroughTwoDimensionalFlagTable(Owner*,unsigned);
extern "C" void Graphics_AllocateAndClearConfiguredBuffer(char*,SafeAllocator*);
extern "C" void AllocateSixteenByteRecordArrayWhenAllocatorPresent(unsigned char*,unsigned,SafeAllocator*);
extern "C" int Graphics_InvokeTwoIndexTransferCallback(State*,void*,void*);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void* _Z18LoadFileIntoMemoryPKcPvPj(const char*,void*,unsigned*);
extern "C" int ResourceFile_CountActiveStrideRecords(Record*);
extern "C" char* FindVariableLengthBlockByIndex(char*,int,char**,unsigned*);
extern "C" int DispatchResourceLoadByFourByteTag(Owner*,const void*,SafeAllocator*,unsigned);
extern "C" void DispatchIndexedRecordWithCoordinates(IndexedRecordView*,unsigned,unsigned,unsigned,short,short,short,short,unsigned short);
extern "C" void UpdateProvidedOrStoredChildResource(char*,void*);
extern "C" char data_ov020_0218dcb3[],data_0211e33c[];
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
 SetWordField18AndClearFormatByte1F((int)(p+0x4bc),0);
 ((Canvas*)(p+0x4bc))->flags.low=1;
 ((Canvas*)(p+0x4bc))->flags.high=0;
 DispatchModeThroughTwoDimensionalFlagTable((Owner*)(p+0x4bc),0);
 Graphics_AllocateAndClearConfiguredBuffer(p+0x4bc,(SafeAllocator*)(p+0x470));
 AllocateSixteenByteRecordArrayWhenAllocatorPresent((unsigned char*)p+0x4bc,1,(SafeAllocator*)(p+0x470));
 Graphics_InvokeTwoIndexTransferCallback((State*)(p+0x4bc),0,0);
 _ZN16BackgroundLoader13AddLockGlobalEv();
 fileSize=0;
 _Z18LoadFileIntoMemoryPKcPvPj(data_ov020_0218dcb3,data_0211e33c,&fileSize);
 int count=ResourceFile_CountActiveStrideRecords((Record*)data_0211e33c);
 for(int i=0;i<count;i++) {
  char* data=FindVariableLengthBlockByIndex(data_0211e33c,i,&block,&blockSize);
  if(data)DispatchResourceLoadByFourByteTag((Owner*)(p+0x4bc),data,(SafeAllocator*)(p+0x470),blockSize);
 }
 DispatchIndexedRecordWithCoordinates((IndexedRecordView*)(p+0x4bc),0,0,0,0,0,32,24,0xffff);
 UpdateProvidedOrStoredChildResource(p+0x4bc,0);
 _ZN16BackgroundLoader16RemoveLockGlobalEv();
 *(volatile unsigned short*)0x04000050=0;
 *(volatile unsigned short*)0x04001050=0;
 *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|0x1300;
 *(volatile unsigned*)0x04001000=(*(volatile unsigned*)0x04001000&~0x1f00)|0x100;
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400006c,-16);
 Graphics_WriteSignedBrightnessMagnitudeAndMode((unsigned short*)0x0400106c,-16);
}
