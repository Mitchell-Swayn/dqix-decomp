#include <globaldefs.h>
ARM
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" char* FindVariableLengthBlockByIndex(char*,int,char**,unsigned*);
extern "C" int ResourceFile_CountActiveStrideRecords(void*);
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void DispatchResourceParserByFourByteMagic(char*,const void*);
extern "C" void Graphics_DispatchResourceByFourByteMagic(unsigned char*,void*);
struct LoadState {char pad[0x20];int task;int state;};
extern "C" LoadState data_ov004_021707e8;
extern "C" char data_ov004_02170542[];
struct Canvas {char pad[0x1c]; unsigned char first:4;unsigned char second:4; char rest[3];};
// Original: arm9/ov004 @ 0x02163144; symbol: func_ov004_02163144; size: 0x140.
extern "C" int Graphics_LoadAndDispatchSubscreenResources() {
 int result=1;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(data_ov004_021707e8.state==0) {
  *(volatile unsigned*)0x04001010=0;
  *(volatile unsigned*)0x04001014=0;
  data_ov004_021707e8.task=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,data_ov004_02170542,0);
  ++data_ov004_021707e8.state;
 } else if(data_ov004_021707e8.state==1) {
  if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,data_ov004_021707e8.task)) {
   Canvas canvas;
   void* file;
   unsigned length;
   unsigned blockSize;
   char* blockData;
   _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,data_ov004_021707e8.task,&file,&length);
   int count=ResourceFile_CountActiveStrideRecords(file);
   Graphics_InitializeCanvasTransferState((char*)&canvas);
   canvas.first=1;
   canvas.second=1;
   for(int i=0;i<count;i++) {
    char* block=FindVariableLengthBlockByIndex((char*)file,i,&blockData,&blockSize);
    if(block) {
     DispatchResourceParserByFourByteMagic((char*)&canvas,block);
     Graphics_DispatchResourceByFourByteMagic((unsigned char*)&canvas,block);
    }
   }
   _ZN16BackgroundLoader10RemoveTaskEi(loader,data_ov004_021707e8.task);
   data_ov004_021707e8.task=-1;
   result=0;
  }
 }
 return result;
}
