#include <globaldefs.h>
ARM
#pragma optimize_for_size off
// Original data: arm9/main @ 0x20f10f8; symbol: data_020f10f8.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 00ae080268ad08020000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char PartyProgressInitializeConditionCallbacks_UnknownRoleProcedureReferenceRecords[];
// Original data: arm9/main @ 0x20f1118; symbol: data_020f1118.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 28aa080268ad0802.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char PartyProgressInitializeConditionCallbacks_UnknownRoleProcedureReferenceRecords_Variant3[];
// Original data: arm9/main @ 0x20f1108; symbol: data_020f1108.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 28aa0802bcae08020000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char PartyProgressInitializeConditionCallbacks_UnknownRoleProcedureReferenceRecords_Variant2[];
extern "C" void PartyProgress_ResetConditionsAndRecoveryTimers(char*);
// Original: arm9/main @ 0x0208B508; symbol: func_0208b508; size: 0x40.
extern "C" char* PartyProgress_InitializeConditionCallbacks(char* p){
    *(char**)(p+4)=PartyProgressInitializeConditionCallbacks_UnknownRoleProcedureReferenceRecords;
    *(char**)(p+0x24)=PartyProgressInitializeConditionCallbacks_UnknownRoleProcedureReferenceRecords_Variant3;
    *(char**)(p+0x40)=PartyProgressInitializeConditionCallbacks_UnknownRoleProcedureReferenceRecords_Variant3;
    *(char**)(p+0x5c)=PartyProgressInitializeConditionCallbacks_UnknownRoleProcedureReferenceRecords_Variant2;
    *(char**)(p+0x78)=PartyProgressInitializeConditionCallbacks_UnknownRoleProcedureReferenceRecords_Variant3;
    PartyProgress_ResetConditionsAndRecoveryTimers(p);
    return p;
}
