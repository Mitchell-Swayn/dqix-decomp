#include <globaldefs.h>
ARM
struct Record;struct State;
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" char* FindVariableLengthBlockByIndex(char*,int,char**,unsigned*);
extern "C" int ResourceFile_CountActiveStrideRecords(Record*);
extern "C" void InitializeFixedPointScalesAndInvalidIndices(State*);
extern "C" void InitializeRecordBuffersAndEnabledByte(unsigned char*);
extern "C" int Graphics_DispatchDataByResourceMagic(int,void*,int,int);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void*,void*);
// Original: arm9/ov008 @ 0x02188D74; symbol: func_ov008_02188d74; size: 0x17C.
extern "C" int Graphics_LoadIndexedResourceBlocks(char* p) {
 char* block; void* file; unsigned fileSize; unsigned blockSize;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 unsigned state=*(unsigned char*)(p+0xb12);
 if(state==0) {
  *(unsigned*)(p+0x73c)=0; *(unsigned*)(p+0x740)=0;
  _ZN13SafeAllocator5ResetEv(p+0x50);
  *(char**)(p+0x73c)=_ZN13SafeAllocator8AllocateEj((unsigned)(p+0x50),0x54);
  *(char**)(p+0x740)=_ZN13SafeAllocator8AllocateEj((unsigned)(p+0x50),0x28);
  InitializeRecordBuffersAndEnabledByte(*(unsigned char**)(p+0x73c));
  (*(unsigned char**)(p+0x73c))[0x50]=1;
  char* record=*(char**)(p+0x73c);
  *(char**)(record+0x40)=*(char**)(p+0x740);
  *(short*)(record+0x4c)=1;
  for(int i=0;i<1;i++) InitializeFixedPointScalesAndInvalidIndices((State*)(*(char**)(p+0x740)+i*0x28));
  void* path=ResolveIndexedRecordAndReturnSecondWord(p+0xa0,(void*)7);
  *(int*)(p+0xb20)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,(char*)path,0);
  ++*(unsigned char*)(p+0xb12);
 }
 if(state==1) {
  if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,*(int*)(p+0xb20))) {
   _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,*(int*)(p+0xb20),&file,&fileSize);
   int count=ResourceFile_CountActiveStrideRecords((Record*)file);
   for(int i=0;i<count;i++) {
    char* data=FindVariableLengthBlockByIndex((char*)file,i,&block,&blockSize);
    if(data) Graphics_DispatchDataByResourceMagic(*(int*)(p+0x73c),data,blockSize,(int)(p+0x50));
   }
   _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0xb20));
   *(int*)(p+0xb20)=-1;
   *(unsigned char*)(p+0xb12)=0;
   return 1;
  }
 }
 return 0;
}
