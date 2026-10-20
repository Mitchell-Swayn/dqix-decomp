#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[];extern "C" void Network_RecordWirelessErrorUnlessTerminal(unsigned);extern "C" int Network_BuildAndSubmitConnectionAuxiliaryData();extern "C" int Network_BeginStateThreeOperationUnlessAlreadyActive();
// Original: arm9/main @ 0x0202D108; symbol: func_0202d108; size: 0x78.
extern "C" void Network_HandleRestartCompletionAndPendingMode(unsigned short* param){if(param[1]){Network_RecordWirelessErrorUnlessTerminal(param[1]);return;}*(unsigned*)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+16)=1;if(!*(unsigned short*)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+4))return;*(unsigned short*)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+4)=0;if(*(unsigned*)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+0x30)){if(!Network_BuildAndSubmitConnectionAuxiliaryData())*(unsigned*)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+16)=9;}else{if(!Network_BeginStateThreeOperationUnlessAlreadyActive())*(unsigned*)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+16)=9;}}
