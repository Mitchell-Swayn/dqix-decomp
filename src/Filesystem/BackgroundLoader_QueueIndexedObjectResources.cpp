#include <globaldefs.h>
ARM
extern "C" int sprintf(char*,const char*,...);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(void*,const char*,const char*,void*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" unsigned short _ZNK8Object3D10GetField06Ev(void*);
extern "C" char* GameObject_ResolveLinkedStatsOrNull(char**);
extern "C" void VectorizedMemset(void*,int,unsigned);
// Original data: arm9/main @ 0x20e7bf8; symbol: data_020e7bf8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 6d770000.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" signed char BackgroundLoaderQueueIndexedObjectResources_UnknownRoleInitializedBytes[];
extern "C" char BackgroundLoader_QueueIndexedObjectResources_PathDataCharaSg02DCChr[],BackgroundLoader_QueueIndexedObjectResources_FormatSg02DLGSpr[],BackgroundLoader_QueueIndexedObjectResources_FormatSg02DSpr[],BackgroundLoader_QueueIndexedObjectResources_PathDataAniSgGp2[];
struct Flags { unsigned char bit:1; };
// Original: arm9/main @ 0x0205308C; symbol: func_0205308c; size: 0x164.
extern "C" void BackgroundLoader_QueueIndexedObjectResources(char* p,int index) {
 char path[80];
 char* state=GameObject_ResolveLinkedStatsOrNull((char**)p);
 sprintf(path,BackgroundLoader_QueueIndexedObjectResources_PathDataCharaSg02DCChr,index,BackgroundLoaderQueueIndexedObjectResources_UnknownRoleInitializedBytes[((Flags*)(state+20))->bit]);
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 if(*(int*)(p+0x180)>-1) {_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x180));*(int*)(p+0x180)=-1;}
 *(int*)(p+0x180)=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,0);
 unsigned short id=*(unsigned short*)Zone3D_GetMainInstance();
 if(id==_ZNK8Object3D10GetField06Ev(p)) {
  int queue=0;
  switch(index) {
   case 12:case 13:case 14: VectorizedMemset(path,0,80);sprintf(path,BackgroundLoader_QueueIndexedObjectResources_FormatSg02DLGSpr,index);queue=1;break;
   case 15:case 16:case 30: VectorizedMemset(path,0,80);sprintf(path,BackgroundLoader_QueueIndexedObjectResources_FormatSg02DSpr,index);queue=1;break;
  }
  if(queue) {
   if(*(int*)(p+0x194)>-1) {_ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(p+0x194));*(int*)(p+0x194)=-1;}
   *(int*)(p+0x194)=_ZN16BackgroundLoader18QueueLoadFileInGP2EPKcS1_P13SafeAllocator(loader,BackgroundLoader_QueueIndexedObjectResources_PathDataAniSgGp2,path,0);
  }
 }
}
