#include <globaldefs.h>
ARM
struct Tree;struct Entry;struct Table;
extern "C" Tree* FindTreeNodeForwarder(Tree*,unsigned);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" int _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" void _ZN16BackgroundLoader14RemoveAllLocksEv(void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" int _ZN16BackgroundLoader21GetDetailedTaskStatusEi(void*,int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void ClearWordHalfwordAndByteRecord(unsigned*);
extern "C" void Script_ExecuteWithFiveGlobalContextValues(int,int,const void*,unsigned,int,unsigned short,unsigned char);
extern "C" void* memset(void*,int,unsigned);
extern "C" void __clear(void*,unsigned);
extern "C" int GameState_CopySixtyByteFieldAtOffset7504(void*);
extern "C" Entry* Object_FindPositiveHalfwordKeyEntry(Table*,int);
extern "C" void* data_ov004_021707c8[];
extern "C" const char data_ov004_0217039a[],data_ov004_021703af[];
// Original: arm9/ov004 @ 0x021567F8; symbol: func_ov004_021567f8; size: 0x208.
extern "C" int Resource_LoadScriptAndBuildEnabledKeyList(Tree* tree) {
 unsigned char* node=(unsigned char*)FindTreeNodeForwarder(tree,4);
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 data_ov004_021707c8[3]=_ZN13SafeAllocator8AllocateEj((unsigned)(node+4),20);
 int task=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,data_ov004_0217039a,data_ov004_021703af,0);
 if(task<0) return 0;
 while(!_ZN16BackgroundLoader13GetTaskStatusEi(loader,task)) _ZN16BackgroundLoader14RemoveAllLocksEv(loader);
 if(_ZN16BackgroundLoader21GetDetailedTaskStatusEi(loader,task)!=2) {
  _ZN16BackgroundLoader10RemoveTaskEi(loader,task);
  return 0;
 }
 void* file;
 unsigned length;
 _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,task,&file,&length);
 if(file) {
  ClearWordHalfwordAndByteRecord((unsigned*)data_ov004_021707c8[3]);
  Script_ExecuteWithFiveGlobalContextValues((int)data_ov004_021707c8[3],(int)(node+4),file,length,0,0,15);
 }
 _ZN16BackgroundLoader10RemoveTaskEi(loader,task);
 if(!file) return 0;
 data_ov004_021707c8[2]=_ZN13SafeAllocator8AllocateEj((unsigned)(node+4),960);
 memset(data_ov004_021707c8[2],0,960);
 unsigned bits[15]={0};
 GameState_CopySixtyByteFieldAtOffset7504(bits);
 int count=0;
 for(int i=0;i<480;++i) {
  int id=i+1;
  if(Object_FindPositiveHalfwordKeyEntry((Table*)data_ov004_021707c8[3],(short)id)) {
   if(bits[id/32]&(1<<(id%32))) ((short*)data_ov004_021707c8[2])[count++]=id;
  }
 }
 data_ov004_021707c8[1]=_ZN13SafeAllocator8AllocateEj((unsigned)(node+4),960);
 memset(data_ov004_021707c8[1],0,960);
 data_ov004_021707c8[0]=_ZN13SafeAllocator8AllocateEj((unsigned)(node+4),4096);
 memset(data_ov004_021707c8[0],0,4096);
 return 0;
}
