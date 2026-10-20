#include <globaldefs.h>
ARM
struct Tree;struct State;struct Node;struct Item {void* table;unsigned char pad[44];};
extern "C" void* memcpy(void*,const void*,unsigned);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
extern "C" Tree* Menu_FindSessionArenaById(Tree*,unsigned);
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" void MenuRecordList_AppendKeyedRecord(Node**,Node*);
extern "C" int MenuFill_InitializeRectangleRecord(Item*,void*,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
// Original data: arm9/ov023 @ 0x21ff4b0; symbol: data_ov023_021ff4b0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 14c51f02b8691f02e8691f0284691f0288691f02186a1f026cc41f0270c41f02b4c41f0258741f0250741f024c741f0244741f0240741f0238741f029c7d1f02 ...; full span in module reference.
// Observed span: 260 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" char SharedData_UnknownRoleProcedureReferenceRecords_Variant14[];
// Original: arm9/ov004 @ 0x0216B120; symbol: func_ov004_0216b120; size: 0xA4.
extern "C" void Resource_AllocateConfiguredNodeAndAppend(Tree* owner,unsigned value,unsigned kind,unsigned a,unsigned b,unsigned c,unsigned d,unsigned e){
 char* arena=(char*)Menu_FindSessionArenaById(owner,kind);
 Item* node=(Item*)_ZN13SafeAllocator8AllocateEj((unsigned)(arena+4),48);
 if(node){
 Item initial;initial.table=SharedData_UnknownRoleProcedureReferenceRecords_Variant14;
 memcpy(node,&initial,48);
 MenuFill_InitializeRectangleRecord(node,owner,value,kind,a,b,c,d,e,15);
 Node** head=(Node**)Menu_GetDisplayRecordRegistry((State*)owner);
 MenuRecordList_AppendKeyedRecord(head,(Node*)node);
 }
}
