#include <globaldefs.h>
ARM
struct State;struct Tree;
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned MenuRecordList_GetBackgroundTaskId(void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" int _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" Tree* Menu_FindSessionArenaById(Tree*,unsigned);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void MenuRecordList_SetBackgroundTaskId(void*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" void _ZN13SafeAllocator11CreateTypeAEPvj(void*,void*,unsigned);
extern "C" void _ZN13SafeAllocator5ResetEv(void*);
extern "C" bool ZoneState2754_CopyAndRelocateSerializedData(void*,void*,void*,unsigned);
extern "C" bool _ZN13ZoneState275421BuildAlternateForKeysEP13SafeAllocatorPvjPKss(void*,void*,void*,unsigned,const short*,short);
extern "C" void __clear(void*,unsigned);
// Original: arm9/ov023 @ 0x021FBF4C; symbol: func_ov023_021fbf4c; size: 0x298.
extern "C" int Resource_PollAndBuildSelectedZoneData(unsigned char* self,State* owner) {
 unsigned char* node;
 void* state=Menu_GetDisplayRecordRegistry(owner);
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 int task=MenuRecordList_GetBackgroundTaskId(state);
 if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,task)) {
 if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,task)==2) {
  void* file;unsigned length;
  _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,task,&file,&length);
  node=(unsigned char*)Menu_FindSessionArenaById((Tree*)owner,*(unsigned short*)(self+8));
  if(!node) {
   _ZN16BackgroundLoader10RemoveTaskEi(loader,task);
   MenuRecordList_SetBackgroundTaskId(state,-1);
   return 2;
  }
  if(!*(unsigned*)(self+0x4c)) {
   void* data=_ZN13SafeAllocator8AllocateEj((unsigned)(node+4),0x1a000);
   _ZN13SafeAllocator11CreateTypeAEPvj(self+0x20,data,0x1a000);
   _ZN13SafeAllocator5ResetEv(self+0x20);
   ZoneState2754_CopyAndRelocateSerializedData(self+0x34,self+0x20,file,length);
  } else {
   unsigned bytes=0;
   short count=0;
   unsigned char keys[12]={0};
   if(*(unsigned*)(self+0x4c)&1) {
    bytes+=79872.0;
    for(short i=0;i<=7;++i) keys[count++]=i;
   }
   if(*(unsigned*)(self+0x4c)&2) {bytes+=7987.2;keys[count++]=8;}
   if(*(unsigned*)(self+0x4c)&4) {bytes+=4915.2;keys[count++]=9;}
   if(*(unsigned*)(self+0x4c)&8) {bytes+=15872.0;keys[count++]=11;}
   if(bytes>0x1a000) bytes=0x1a000;
   void* data=_ZN13SafeAllocator8AllocateEj((unsigned)(node+4),bytes);
   _ZN13SafeAllocator11CreateTypeAEPvj(self+0x20,data,bytes);
   _ZN13SafeAllocator5ResetEv(self+0x20);
   _ZN13ZoneState275421BuildAlternateForKeysEP13SafeAllocatorPvjPKss(self+0x34,self+0x20,file,length,(const short*)keys,count);
  }
 }
 _ZN16BackgroundLoader10RemoveTaskEi(loader,task);
 MenuRecordList_SetBackgroundTaskId(state,-1);
 return 2;
 }
 return *(int*)(self+0x1c);
}
