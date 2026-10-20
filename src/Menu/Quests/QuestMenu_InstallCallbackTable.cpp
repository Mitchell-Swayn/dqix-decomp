#include <globaldefs.h>
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void *memcpy(void *, const void *, unsigned);
extern "C" void Menu_SetCallbackTableAndCount(void *, unsigned, unsigned);
struct Block { unsigned w[19]; };
// Original data: arm9/ov004 @ 0x216ffac; symbol: data_ov004_0216ffac.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 0000000044681602c46a1602406b1602d86b1602906f1602986f1602a06f1602e46f16026870160210731602707316022474160234741602fc75160248761602 ...; full span in module reference.
// Observed span: 76 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" Block QuestMenuInstallCallbackTable_UnknownRoleProcedureReferenceRecords;
// Original: arm9/ov004 @ 0x021677B4; symbol: func_ov004_021677b4; size: 0x6C.
extern "C" void QuestMenu_InstallCallbackTable(void *allocator, void *state) {
    Block local = QuestMenuInstallCallbackTable_UnknownRoleProcedureReferenceRecords;
    char *copy = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0x4c);
    memcpy(copy, &local, 0x4c);
    Menu_SetCallbackTableAndCount(state, (unsigned)copy, 0x13);
}
