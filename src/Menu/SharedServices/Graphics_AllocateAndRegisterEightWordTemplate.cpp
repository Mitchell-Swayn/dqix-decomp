#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
struct State;
extern "C" void Menu_SetCallbackTableAndCount(State *,unsigned,unsigned);
// Original data: arm9/ov004 @ 0x216faec; symbol: data_ov004_0216faec.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 00000000e8601502b0611502f064150260671502f8671502006a1502b86c15020b000b00.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" const unsigned char GraphicsAllocateAndRegisterEightWordTemplate_UnknownRoleProcedureReferenceRecords[];
extern "C" void *memcpy(void *,const void *,unsigned);
struct EightWordTemplate {unsigned words[8];};
// Original: arm9/ov004 @ 0x02156DC8; symbol: func_ov004_02156dc8; size: 0x60.
// Allocates and copies the eight-word template, then registers its address and element count in the target state.
extern "C" void Graphics_AllocateAndRegisterEightWordTemplate(SafeAllocator *allocator,State *state) {
 EightWordTemplate initial=*(const EightWordTemplate *)GraphicsAllocateAndRegisterEightWordTemplate_UnknownRoleProcedureReferenceRecords;
 void *buffer=allocator->Allocate(0x20);
 memcpy(buffer,&initial,0x20);
 Menu_SetCallbackTableAndCount(state,(unsigned)buffer,8);
}
