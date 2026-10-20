#include <globaldefs.h>
ARM
// Original: arm9/ov031:0223d830; Calls the initializer with one, then sets bit zero in control word 0x027e3ff8.
extern "C" void WfcUtility_RunTaskQueue(unsigned int);
// Original data: arm9/dtcm @ 0x27e0000; symbol: data_027e0000.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex c8690c02c8690c02c8690c02946a0c02a46a0c02b46a0c02c46a0c02c8690c02546a0c02646a0c02746a0c02846a0c02c8690c02c8690c02c8690c02c8690c02 ...; full span in module reference.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/dtcm.md.
extern volatile unsigned int Entry_UnknownRoleProcedureReferenceRecords[];
extern "C" void WfcUtility_RunMainTasksAndSignalControl(void) {
    WfcUtility_RunTaskQueue(1);
    volatile unsigned int *region = Entry_UnknownRoleProcedureReferenceRecords;
    region += 0xc00;
    region[0x3fe] |= 1;
}
