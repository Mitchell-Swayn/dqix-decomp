#include <globaldefs.h>
ARM
// Original data: arm9/ov011 @ 0x21889a0; symbol: data_ov011_021889a0.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 7c4c1802c04c1802e44d1802d04e1802b04f180218501802205018025c511802ec511802145218021853180218541802045518024c551802cc55180200561802 ...; full span in module reference.
// Observed span: 460 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov011.md.
extern "C" unsigned char MenuInstallSb2OpcodeHandlerTable_UnknownRoleProcedureReferenceRecords[];
extern "C" void Script_SetOpcodeHandlerTable(void *, void *, int);
// Original: arm9/ov011 @ 0x021888EC; symbol: func_ov011_021888ec; size: 0x18.
extern "C" void Menu_InstallSb2OpcodeHandlerTable(void *p) {
    Script_SetOpcodeHandlerTable(p, MenuInstallSb2OpcodeHandlerTable_UnknownRoleProcedureReferenceRecords, 0x73);
}
