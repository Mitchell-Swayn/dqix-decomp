#include <globaldefs.h>
ARM
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void *memcpy(void *, const void *, unsigned int);
struct State;
extern "C" void Menu_SetCallbackTableAndCount(State *, unsigned, unsigned);
// Original data: arm9/ov004 @ 0x2170444; symbol: data_ov004_02170444.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 0000000070f71502fcfd15023c031602ec121602f813160214151602181c1602082116026c2716029c2a1602cc2a1602042b16023c2b1602842b1602302c1602 ...; full span in module reference.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char MenuAllocateOverlayDispatchTemplate_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov004 @ 0x021633AC; symbol: func_ov004_021633ac; size: 0x38.
extern "C" void Menu_AllocateOverlayDispatchTemplate(unsigned arena, State *self) {
    char *copy = _ZN13SafeAllocator8AllocateEj(arena, 0x60);
    memcpy(copy, MenuAllocateOverlayDispatchTemplate_UnknownRoleProcedureReferenceRecords, 0x60);
    Menu_SetCallbackTableAndCount(self, (unsigned)copy, 0x18);
}
