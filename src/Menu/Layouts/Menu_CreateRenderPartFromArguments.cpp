#include <globaldefs.h>
ARM
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov023 @ 0x21fee68; symbol: data_ov023_021fee68.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 80b61f02b8691f02e8691f0284691f0288691f02186a1f0240b61f0278b81f028cb81f0258741f0250741f024c741f0244741f0240741f0238741f02ccb81f02 ...; full span in module reference.
// Observed span: 252 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
struct Argument;struct Tree;struct State;struct Node;extern "C" int Menu_ReadScriptArgumentAsInteger(Argument*);extern "C" unsigned Resource_GetSharedLoadState();extern "C" Tree* Menu_FindSessionArenaById(Tree*,unsigned);extern "C" unsigned _ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(void*);extern "C" void* _ZN13SafeAllocator8AllocateEj(void*,unsigned);extern "C" void _ZN21ZoneRenderPartEntries5ResetEv(void*);extern "C" unsigned SharedData_UnknownRoleProcedureReferenceRecords_Variant8;extern "C" void* memcpy(void*,const void*,unsigned);extern "C" int Menu_InitializeTilePayloadAndReserveOam(void*,unsigned,int,int,void*,int);extern "C" void* Menu_GetDisplayRecordRegistry(State*);extern "C" void MenuRecordList_AppendKeyedRecord(Node**,Node*);struct RenderOwner{char pad[84];unsigned char entries[64];};struct Panel{void* vtable;char pad[28];RenderOwner owner;};
// Original: arm9/ov011 @ 0x02185EA4; symbol: Resource_AllocateInitializeAndAppendRenderNode; size: 0x104.
extern "C" int Menu_CreateRenderPartFromArguments(char* parameter){int first=Menu_ReadScriptArgumentAsInteger((Argument*)parameter);int index=Menu_ReadScriptArgumentAsInteger((Argument*)(parameter+8));void* data=W(parameter,16)==2?(void*)W(parameter,20):0;if(!data)return 0;int mode=Menu_ReadScriptArgumentAsInteger((Argument*)(parameter+24));unsigned owner=Resource_GetSharedLoadState();char* tree=(char*)Menu_FindSessionArenaById((Tree*)owner,index);if(!tree)return 0;_ZNK13SafeAllocator30GetSizeWithLargestBlockRemovedEv(tree+4);void* node=_ZN13SafeAllocator8AllocateEj(tree+4,180);if(!node)return 0;Panel temp;char* base=(char*)&temp.owner;temp.vtable=&SharedData_UnknownRoleProcedureReferenceRecords_Variant8;_ZN21ZoneRenderPartEntries5ResetEv(base+84);memcpy(node,&temp,180);if(!Menu_InitializeTilePayloadAndReserveOam(node,owner,first,index,data,mode)){_ZN21ZoneRenderPartEntries5ResetEv(temp.owner.entries);return 0;}MenuRecordList_AppendKeyedRecord((Node**)Menu_GetDisplayRecordRegistry((State*)owner),(Node*)node);_ZN21ZoneRenderPartEntries5ResetEv(temp.owner.entries);return 1;}
