#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5c4; symbol: data_ov031_0224e5c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[];extern "C" unsigned Network_NormalizeWirelessProfileIndex(unsigned);extern "C" void* Network_GetDcfPeerGameInfo(int);extern "C" void _Z24InvalidateDataCacheRangePKvj(const void*,unsigned);extern "C" void AccessPoint_CopyDecodedShopIdentifier(void*,void*);extern "C" void VectorizedMemset(void*,int,unsigned);
// Original: arm9/ov031 @ 0x02213504; symbol: UpdateModeByteAndValidateTenPrintableCharacters; size: 0xA8.
// Uses byte22 or a derived mode for byte17; copies and validates ten printable ASCII characters.
extern "C" void UpdateModeByteAndValidateTenPrintableCharacters(unsigned input){unsigned mode=*(unsigned char*)(NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[3]+0x22);if(!mode)mode=Network_NormalizeWirelessProfileIndex(input);NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[3][0x17]=mode;void* source=Network_GetDcfPeerGameInfo(0);if(source){_Z24InvalidateDataCacheRangePKvj(source,32);AccessPoint_CopyDecodedShopIdentifier(source,NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[3]+0x18);}int i=0;char* cursor;char* object=NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[3];cursor=object;do{int c=cursor[0x18];if(c<32||c>126){VectorizedMemset(object+0x18,0,10);return;}i++;cursor++;}while(i<10);}
