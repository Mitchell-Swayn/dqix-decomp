#include <globaldefs.h>
ARM
struct Header { unsigned int flags; unsigned short extra; };
struct State { Header* output; int pad; signed char index; };
// Original data: arm9/ov031 @ 0x2250bf8; symbol: data_ov031_02250bf8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" State* WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x22489a4; symbol: data_ov031_022489a4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 181716155f5e5d5c.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityCreateWirelessRegionIndicator_UnknownRoleInitializedBytes[];
extern "C" unsigned int WM_GetAllowedChannel();
extern "C" unsigned short ReadSharedRecordSizeForAllowedTypes();
extern "C" void WfcUtility_ExpandSpriteCellTemplate(unsigned int,unsigned int,void*);
// Original: arm9/ov031 @ 0x02223B60; symbol: func_ov031_02223b60; size: 0xA8.
extern "C" void System_ExpandSharedEntriesAndSetHeaderFlags() {
volatile unsigned short* ime=(volatile unsigned short*)0x4000208;
unsigned int offset=0;
unsigned short saved=*ime;
*ime=0;
if(WM_GetAllowedChannel()!=0x8000)offset=ReadSharedRecordSizeForAllowedTypes();
(void)*ime;*ime=saved;
WfcUtility_ExpandSpriteCellTemplate(0,(WfcUtilityCreateWirelessRegionIndicator_UnknownRoleInitializedBytes+WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage->index*4)[offset],WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage->output);
WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage->output->flags=(WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage->output->flags&0xfe00ff00)|0xe50026;
WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage->output->extra=(WfcUtilityDestroyWirelessRegionIndicator_UnknownRoleZeroInitializedStorage->output->extra&~0xc00)|0x800;
}
