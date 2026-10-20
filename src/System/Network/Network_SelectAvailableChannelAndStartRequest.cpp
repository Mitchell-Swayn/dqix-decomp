#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned WM_GetAllowedChannel(); extern "C" void Network_RecordWirelessErrorUnlessTerminal(int); extern "C" char NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[];
extern "C" int Network_AccumulateLeastBusyChannels(); extern "C" int WM_MeasureChannel(void *,unsigned short,unsigned short,unsigned short,unsigned short);
// Original: arm9/main @ 0x0202D788; symbol: func_0202d788; size: 0xB8.
extern "C" unsigned short Network_SelectAvailableChannelAndStartRequest(unsigned short value) { unsigned flags=WM_GetAllowedChannel(); if(flags==0x8000) { Network_RecordWirelessErrorUnlessTerminal(3); *(int *)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+16)=9; return 3; } if(flags==0) { Network_RecordWirelessErrorUnlessTerminal(22); *(int *)(NetworkGetAssociationId_UnknownRoleZeroInitializedStorage+16)=9; return 24; } while(!(flags&(1U<<(value-1)))) { ++value; if(value>16) return 24; } return WM_MeasureChannel((void *)Network_AccumulateLeastBusyChannels,3,17,value,30); }
