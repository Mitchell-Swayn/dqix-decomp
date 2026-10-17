#include <globaldefs.h>
ARM
struct Tree;struct State;struct Node;struct Item {void* table;unsigned char pad[44];};
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" Tree* FindTreeNodeForwarder(Tree*,unsigned);
extern "C" void* func_ov011_021849c8(State*);
extern "C" void AppendEnabledNodeToForwardChain(Node**,Node*);
extern "C" int Unclassified_InitializeType19RecordFromArguments(Item*,void*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" char data_ov023_021ff4b0[];
// Original: arm9/ov004 @ 0x0216B120; symbol: func_ov004_0216b120; size: 0xA4.
extern "C" void Resource_AllocateConfiguredNodeAndAppend(Tree* owner,unsigned value,unsigned kind,unsigned a,unsigned b,unsigned c,unsigned d,unsigned e){
 char* arena=(char*)FindTreeNodeForwarder(owner,kind);
 Item* node=(Item*)_ZN13SafeAllocator8AllocateEj((unsigned)(arena+4),48);
 if(node){
 Item initial;initial.table=data_ov023_021ff4b0;
 memcpy(node,&initial,48);
 Unclassified_InitializeType19RecordFromArguments(node,owner,value,kind,a,b,c,d,e,15);
 Node** head=(Node**)func_ov011_021849c8((State*)owner);
 AppendEnabledNodeToForwardChain(head,(Node*)node);
 }
}
