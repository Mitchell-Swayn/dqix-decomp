#include <globaldefs.h>
ARM
struct SafeAllocator; struct Record; struct State; struct IndexedRecordView;
struct Mode { unsigned char low:4,high:4; };
struct Owner { char pad[0x1c]; Mode mode; };
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" int _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" char* FindVariableLengthBlockByIndex(char*,int,char**,unsigned*);
extern "C" int ResourceFile_CountActiveStrideRecords(Record*);
extern "C" void AllocateSixteenByteRecordArrayWhenAllocatorPresent(unsigned char*,unsigned,SafeAllocator*);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void UpdateProvidedOrStoredChildResource(char*,void*);
extern "C" void SetWordField18AndClearFormatByte1F(int,unsigned);
extern "C" void Graphics_AllocateAndClearConfiguredBuffer(char*,SafeAllocator*);
extern "C" int DispatchResourceLoadByFourByteTag(Owner*,const void*,unsigned,unsigned);
extern "C" void DispatchModeThroughTwoDimensionalFlagTable(Owner*,unsigned);
extern "C" int Graphics_InvokeTwoIndexTransferCallback(State*,void*,void*);
extern "C" void DispatchIndexedRecordWithCoordinates(IndexedRecordView*,unsigned,unsigned,unsigned,short,short,short,short,unsigned short);
// Original: arm9/ov003 @ 0x0217CB3C; symbol: func_ov003_0217cb3c; size: 0x1E8.
extern "C" void Graphics_LoadCanvasResourceBlocks(char* p,int mainEngine,int alternate) {
 char* block; void* file; unsigned length; unsigned blockSize;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 char* canvas; SafeAllocator* allocator;
 if(mainEngine) {
  *(volatile unsigned short*)0x400000a=(*(volatile unsigned short*)0x400000a&0x43)|0xf00;
  *(volatile unsigned*)0x4000000=(*(volatile unsigned*)0x4000000&~0x1f00)|0x300;
  canvas=p+0x60; allocator=(SafeAllocator*)(p+0x2c);
  Graphics_InitializeCanvasTransferState(canvas);
  ((Owner*)canvas)->mode.low=0; ((Owner*)canvas)->mode.high=1;
  DispatchModeThroughTwoDimensionalFlagTable((Owner*)canvas,1);
 } else {
  *(volatile unsigned short*)0x4001008=(*(volatile unsigned short*)0x4001008&0x43)|0xf00;
  *(volatile unsigned*)0x4001000=(*(volatile unsigned*)0x4001000&~0x1f00)|0x100;
  canvas=p+0x40; allocator=(SafeAllocator*)(p+0x18);
  Graphics_InitializeCanvasTransferState(canvas);
  ((Owner*)canvas)->mode.low=1; ((Owner*)canvas)->mode.high=0;
  DispatchModeThroughTwoDimensionalFlagTable((Owner*)canvas,0);
 }
 _ZN13SafeAllocator5ResetEv(allocator);
 int fileId=alternate?*(int*)(p+0x138):*(int*)(p+0x134);
 SetWordField18AndClearFormatByte1F((int)canvas,0);
 Graphics_InvokeTwoIndexTransferCallback((State*)canvas,0,0);
 Graphics_AllocateAndClearConfiguredBuffer(canvas,allocator);
 AllocateSixteenByteRecordArrayWhenAllocatorPresent((unsigned char*)canvas,1,allocator);
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,fileId,&file,&length);
 int count=ResourceFile_CountActiveStrideRecords((Record*)file);
 for(int i=0;i<count;i++) {
  char* payload=FindVariableLengthBlockByIndex((char*)file,i,&block,&blockSize);
  if(payload) DispatchResourceLoadByFourByteTag((Owner*)canvas,payload,(unsigned)allocator,blockSize);
 }
 DispatchIndexedRecordWithCoordinates((IndexedRecordView*)canvas,0,0,0,0,0,32,24,0xffff);
 UpdateProvidedOrStoredChildResource(canvas,0);
}
