#include <globaldefs.h>
ARM
struct Tree; struct State; struct Owner; struct Node;
extern "C" char data_ov023_021fec44[],data_ov023_021fec49[],data_ov023_021fec4e[],data_ov023_021fec53[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);
extern "C" unsigned ReadWordFieldAtOffset1C();
extern "C" void Object_ClearWordAndHalfwordOutput(unsigned*);
extern "C" int Graphics_DispatchDataByResourceMagic(int,void*,int,int);
extern "C" unsigned short ReadRecordDerivedHalfwordOrZero(void*,void*);
extern "C" Tree* FindTreeNodeForwarder(Tree*,unsigned);
extern "C" void* func_ov011_021849c8(State*);
extern "C" void Util_InsertNodeByAscendingKey(Owner*,Node*);
extern "C" void Ov023_SetIndexedHalfwordBit(void*,unsigned char,unsigned short);
extern "C" void* GetIndexedRecordAddressOrZero(void*,unsigned short);
extern "C" int func_ov023_021fad20(void*,const char*,void**,unsigned*);
// Original: arm9/ov023 @ 0x021FAB48; symbol: func_ov023_021fab48; size: 0x1D0.
extern "C" void Graphics_LoadNamedResourcesAndStageSharedState(char* self,Tree* tree,void* source,unsigned length) {
 void* data; unsigned size;
 void* manager; unsigned key;
 if(!source || !length) return;
 char* node=(char*)FindTreeNodeForwarder(tree,*(unsigned short*)(self+8));
 if(!node) return;
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(node+4);
 if(func_ov023_021fad20(source,data_ov023_021fec44,&data,&size)) Graphics_DispatchDataByResourceMagic((int)(self+0x24),data,size,(int)(node+4));
 if(func_ov023_021fad20(source,data_ov023_021fec49,&data,&size)) Graphics_DispatchDataByResourceMagic((int)(self+0x24),data,size,(int)(node+4));
 if(func_ov023_021fad20(source,data_ov023_021fec4e,&data,&size)) Graphics_DispatchDataByResourceMagic((int)(self+0x24),data,size,(int)(node+4));
 if(func_ov023_021fad20(source,data_ov023_021fec53,&data,&size)) {
  unsigned* buffer=(unsigned*)_ZN13SafeAllocator8AllocateEj((unsigned)(node+4),8);
  if(buffer) {
   Object_ClearWordAndHalfwordOutput(buffer);
   *(unsigned**)(self+0x60)=buffer;
   Graphics_DispatchDataByResourceMagic((int)(self+0x24),data,size,(int)(node+4));
  }
 }
 _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(node+4);
 key=*(unsigned*)(self+0x6c);
 manager=func_ov011_021849c8((State*)tree);
 *(unsigned*)(self+0x78)=0;
 *(unsigned*)(self+0x7c)=key;
 Util_InsertNodeByAscendingKey((Owner*)manager,(Node*)(self+0x78));
 for(unsigned i=0;i<*(unsigned short*)(self+0x72);i++) {
  void* record=GetIndexedRecordAddressOrZero(self+0x24,(unsigned short)i);
  if(record) Ov023_SetIndexedHalfwordBit(manager,*(unsigned char*)(self+0x74),ReadRecordDerivedHalfwordOrZero(self+0x24,record));
 }
 char* shared=(char*)ReadWordFieldAtOffset1C();
 *(char**)(shared+0x2d8)=self+0x24;
 *(unsigned*)(shared+0x2dc)=*(unsigned*)(self+0x64);
 *(unsigned short*)(shared+0x2e4)=0;
 *(unsigned*)(shared+0x2e0)=*(unsigned*)(self+0x60);
 *(unsigned char*)(shared+0x2e6)=1;
}
