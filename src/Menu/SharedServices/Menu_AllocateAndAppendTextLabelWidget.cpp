#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned MenuRecordList_AppendKeyedRecord(...);
extern "C" unsigned Menu_FindSessionArenaById(...);
extern "C" unsigned _ZN13SafeAllocator8AllocateEj(...);
extern "C" unsigned Menu_GetDisplayRecordRegistry(...);
extern "C" unsigned MenuTextLabel_InitializeSelectableTextRecord(...);
extern "C" unsigned memcpy(...);
// Original data: arm9/ov023 @ 0x21fe708; symbol: data_ov023_021fe708.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex f08c1f02b8691f02e8691f0284691f0288691f02186a1f02e88a1f02ec8a1f02308b1f0258741f0250741f024c741f0244741f0240741f0238741f02688c1f02 ...; full span in module reference.
// Observed span: 260 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned char SharedData_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov004 @ 0x0216AFB0; symbol: AllocateAndAppendByteLookupNode; size: 0xbc.
// Allocates80-byte node from selected allocator, initializes byte lookup state and appends enabled forward-chain node.
extern "C" void Menu_AllocateAndAppendTextLabelWidget(unsigned owner,unsigned key,unsigned allocatorKey,unsigned value,unsigned a,unsigned b,unsigned c,unsigned d,unsigned char enabled){
 unsigned allocator=Menu_FindSessionArenaById(owner,allocatorKey);unsigned node=_ZN13SafeAllocator8AllocateEj(allocator+4,80);if(node){unsigned prototype[20];prototype[0]=(unsigned)SharedData_UnknownRoleProcedureReferenceRecords;memcpy(node,prototype,80);
 int flags=15;if(!enabled)flags=3;MenuTextLabel_InitializeSelectableTextRecord(node,owner,key,allocatorKey,value,0x192,a,b,c,d,flags);MenuRecordList_AppendKeyedRecord(Menu_GetDisplayRecordRegistry(owner),node);}
}
