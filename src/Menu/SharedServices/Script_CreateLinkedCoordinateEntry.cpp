#include <globaldefs.h>
ARM
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" void Menu_SetCallbackTableAndCount(void *, unsigned, unsigned);
// Original data: arm9/ov004 @ 0x2170360; symbol: data_ov004_02170360.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 00000000b85215024c53150244551502b0551502dc5615021c571502ac5715023c5a15026c5b1502bc5b1502545d1502a45e1502a05f1502.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char ScriptCreateLinkedCoordinateEntry_UnknownRoleProcedureReferenceRecords[];
// Original: arm9/ov004 @ 0x021560B0; symbol: func_ov004_021560b0; size: 0x38.
extern "C" void Script_CreateLinkedCoordinateEntry(unsigned allocatorArg, void *state) {
    char *entry = _ZN13SafeAllocator8AllocateEj(allocatorArg, 0x38);
    memcpy(entry, ScriptCreateLinkedCoordinateEntry_UnknownRoleProcedureReferenceRecords, 0x38);
    Menu_SetCallbackTableAndCount(state, (unsigned)entry, 0xe);
}
