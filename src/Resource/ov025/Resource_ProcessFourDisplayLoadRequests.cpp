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
extern "C" void func_ov025_021eb3c0(void*);
extern "C" char data_ov025_021eeff4[],data_ov025_021eeff0[],data_ov025_021ef8e0[],data_ov025_021ef8e9[];
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
   Words words=*(Words*)data_ov025_021eeff4;
   Bytes bytes=*(Bytes*)data_ov025_021eeff0;
   char path[64];char temporary[64];
   sprintf(path,data_ov025_021ef8e0,words.v[req->type],bytes.v[req->type]);
   sprintf(temporary,path,req->param);
   sprintf(path,data_ov025_021ef8e9,temporary);
   req->task=_ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader,path,allocator);
   if(req->task!=-1)req->state=2;
   else func_ov025_021eb3c0(req);
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
   func_ov025_021eb3c0(req);
   break;
  }
  default:func_ov025_021eb3c0(req);break;
  }
 }
 return active;
}
