#include <globaldefs.h>
// Original data: arm9/main @ 0x21015a0; symbol: data_021015a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 96 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21017a0; symbol: data_021017a0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 480 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2101f80; symbol: data_02101f80.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1088 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" { void Network_RecordWirelessErrorUnlessTerminal(unsigned); int WM_StartMP(void(*)(void*),void*,unsigned,void*,unsigned,unsigned); void Network_HandleClientMultiplayerCallback(void*); extern unsigned NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[]; extern char NetworkHandleClientConnectionEvents_UnknownRoleZeroInitializedStorage_Variant2[],NetworkHandleClientConnectionEvents_UnknownRoleZeroInitializedStorage[]; }
// Original: arm9/main @ 0x0202D2A4; symbol: func_0202d2a4; size: 0x13C.
extern "C" ARM void Network_HandleClientConnectionEvents(unsigned short* message) { unsigned error=message[1]; if(error) { Network_RecordWirelessErrorUnlessTerminal(error); if(message[1]==12) NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=9; else if(message[1]==11) NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=9; else if(message[1]==1) NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=8; else NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=9; return; } unsigned code=message[4]; if(code==8) return; if(code==7) { NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=4; int result=WM_StartMP(Network_HandleClientMultiplayerCallback,NetworkHandleClientConnectionEvents_UnknownRoleZeroInitializedStorage_Variant2,(unsigned short)NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[11],NetworkHandleClientConnectionEvents_UnknownRoleZeroInitializedStorage,(unsigned short)NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[14],1); bool success; if(result==2) success=true; else { Network_RecordWirelessErrorUnlessTerminal(result); success=false; } if(!success) NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=3; else *(unsigned short*)NetworkGetAssociationId_UnknownRoleZeroInitializedStorage=message[5]; return; } if(code==6) return; if(code==9) { Network_RecordWirelessErrorUnlessTerminal(20); NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=9; return; } if(code!=26) NetworkGetAssociationId_UnknownRoleZeroInitializedStorage[4]=9; }
