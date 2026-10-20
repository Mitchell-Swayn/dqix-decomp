#include <globaldefs.h>
ARM
extern "C" int sprintf(char*,const char*,...);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*,const char*,void*);
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*,unsigned);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*,int,void**,unsigned*);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
extern "C" void* Object_GetGlobalSixteenEntryDisplayState();
extern "C" int AllocateInitializeAndAppendLinkedNode(int*,unsigned,void*,unsigned,unsigned,unsigned);
extern "C" void Resource_ResetDisplayLoadRequest(void*);
// Original data: arm9/ov025 @ 0x21eeff0; symbol: data_ov025_021eeff0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 04060404.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
// Original data: arm9/ov025 @ 0x21eeff4; symbol: data_ov025_021eeff4.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 9df81e0298f81e029af81e02a0f81e020f000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" char ResourceProcessFourDisplayLoadRequests_UnknownRoleDataReferences[],ResourceProcessFourDisplayLoadRequests_UnknownRoleInitializedBytes[],Resource_ProcessFourDisplayLoadRequests_FormatS0Du[],Resource_ProcessFourDisplayLoadRequests_PathDataEffectSChr[];
struct Request { int task; unsigned short id,param; unsigned char type,state; unsigned short pad; };
struct Words { unsigned v[4]; };struct Bytes { unsigned char v[4]; };
// Original: arm9/ov025 @ 0x021EB204; symbol: func_ov025_021eb204; size: 0x1BC.
extern "C" int Resource_ProcessFourDisplayLoadRequests(char* self) {
 int active;
 Request* req=(Request*)(self+0x594);
 active=0;
 void* loader=_ZN16BackgroundLoader11GetInstanceEv();
 int* list=(int*)Object_GetGlobalSixteenEntryDisplayState();
 unsigned char index=*(unsigned char*)(self+0x30);
 void* allocator=*(void**)(self+0x10+index*4);
 unsigned options=*(unsigned*)(self+0x20+index*4);
 for(unsigned char i=0;i<4;i++,req++) {
  if(!req->state)continue;
  active=1;
  switch(req->state) {
  case 1: {
   Words words=*(Words*)ResourceProcessFourDisplayLoadRequests_UnknownRoleDataReferences;
   Bytes bytes=*(Bytes*)ResourceProcessFourDisplayLoadRequests_UnknownRoleInitializedBytes;
   char path[64];char temporary[64];
   sprintf(path,Resource_ProcessFourDisplayLoadRequests_FormatS0Du,words.v[req->type],bytes.v[req->type]);
   sprintf(temporary,path,req->param);
   sprintf(path,Resource_ProcessFourDisplayLoadRequests_PathDataEffectSChr,temporary);
   req->task=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,allocator);
   if(req->task!=-1)req->state=2;
   else Resource_ResetDisplayLoadRequest(req);
   break;
  }
  case 2:
   if(_ZN16BackgroundLoader13GetTaskStatusEi(loader,req->task))req->state=3;
   break;
  case 3: {
   void* file=0;unsigned length=0;
   _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader,req->task,&file,&length);
   if(file)AllocateInitializeAndAppendLinkedNode(list,req->id,allocator,(unsigned)file,length,options);
   _ZN16BackgroundLoader10RemoveTaskEi(loader,req->task);
   Resource_ResetDisplayLoadRequest(req);
   break;
  }
  default:Resource_ResetDisplayLoadRequest(req);break;
  }
 }
 return active;
}
