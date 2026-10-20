#include <globaldefs.h>
ARM
extern "C" int WM_SetIndCallback(unsigned);
extern "C" int WirelessCommand_SubmitOpcodeTwentyNineWithFourArguments(void*,unsigned,unsigned,unsigned,unsigned short);
extern "C" void MBi_CheckWmErrcode(int,int);
extern "C" void MBi_HandleParentWirelessEvent(void*);
// Original data: arm9/ov027 @ 0x21dd8ec; symbol: data_ov027_021dd8ec.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 050028002800fffffcd81d0201000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned short MBInit_UnknownRoleDataReferences[];
// Original: arm9/ov027 @ 0x021DB490; symbol: func_ov027_021db490; size: 0x50.
// Registers the parent callback and submits the stored four communication parameters.
extern "C" void MBi_OnInitializeDone(void)
{
    MBi_CheckWmErrcode(128,WM_SetIndCallback((unsigned)MBi_HandleParentWirelessEvent));
    MBi_CheckWmErrcode(29,WirelessCommand_SubmitOpcodeTwentyNineWithFourArguments((void*)MBi_HandleParentWirelessEvent,MBInit_UnknownRoleDataReferences[3],MBInit_UnknownRoleDataReferences[1],MBInit_UnknownRoleDataReferences[0],MBInit_UnknownRoleDataReferences[2]));
}
