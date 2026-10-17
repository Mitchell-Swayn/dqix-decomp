#include <globaldefs.h>
ARM
extern "C" int sprintf(char*,const char*,...);
extern "C" void* ReadGlobalValueAt020FB3F0();
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" char* GetIndirectField150Address488(char**);
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" signed char data_020e7bf8[];
extern "C" char data_020f0434[],data_020f044c[],data_020f045c[],data_020f0467[];
struct Flags { unsigned char bit:1; };
// Original: arm9/main @ 0x0205308C; symbol: func_0205308c; size: 0x164.
extern "C" void BackgroundLoader_QueueIndexedObjectResources(char* p,int index) {
 char path[80];
 char* state=GetIndirectField150Address488((char**)p);
 sprintf(path,data_020f0434,index,data_020e7bf8[((Flags*)(state+20))->bit]);
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(*(int*)(p+0x180)>-1) {_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x180));*(int*)(p+0x180)=-1;}
 *(int*)(p+0x180)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,0);
 unsigned short id=*(unsigned short*)ReadGlobalValueAt020FB3F0();
 if(id==_ZNK8Object3D10GetField06Ev(p)) {
  int queue=0;
  switch(index) {
   case 12:case 13:case 14: VectorizedMemset(path,0,80);sprintf(path,data_020f044c,index);queue=1;break;
   case 15:case 16:case 30: VectorizedMemset(path,0,80);sprintf(path,data_020f045c,index);queue=1;break;
  }
  if(queue) {
   if(*(int*)(p+0x194)>-1) {_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x194));*(int*)(p+0x194)=-1;}
   *(int*)(p+0x194)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,data_020f0467,path,0);
  }
 }
}
