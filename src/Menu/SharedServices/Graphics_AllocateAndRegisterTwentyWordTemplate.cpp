#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
struct State;
extern "C" void Menu_SetCallbackTableAndCount(State *,unsigned,unsigned);
// Original data: arm9/ov004 @ 0x216fa8c; symbol: data_ov004_0216fa8c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 000000008c3d1502203e150238401502a4401502104215025042150250431502184615021847150248471502fc4715022c48150284491502e44915027c4b1502 ...; full span in module reference.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" const unsigned char GraphicsAllocateAndRegisterTwentyWordTemplate_UnknownRoleProcedureReferenceRecords[];
extern "C" void *memcpy(void *,const void *,unsigned);
struct TwentyWordTemplate {unsigned words[20];};
// Original: arm9/ov004 @ 0x0215502C; symbol: func_ov004_0215502c; size: 0x64.
// Allocates and copies the twenty-word template, then registers its address and element count in the target state.
extern "C" void Graphics_AllocateAndRegisterTwentyWordTemplate(SafeAllocator *allocator,State *state) {
 TwentyWordTemplate initial=*(const TwentyWordTemplate *)GraphicsAllocateAndRegisterTwentyWordTemplate_UnknownRoleProcedureReferenceRecords;
 void *buffer=allocator->Allocate(0x50);
 memcpy(buffer,&initial,0x50);
 Menu_SetCallbackTableAndCount(state,(unsigned)buffer,20);
}
