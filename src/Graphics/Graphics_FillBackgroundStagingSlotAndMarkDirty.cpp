#pragma optimize_for_size off
#include <globaldefs.h>
#include <std_library_functions.h>
// Original data: arm9/main @ 0x2105fd8; symbol: data_02105fd8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1536 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21065d8; symbol: data_021065d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4096 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage_Variant2[],GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage[];
struct MemorySlots {char pad[0x40];unsigned slots[8];};
// Original: arm9/main @ 0x0203B718; symbol: func_0203b718; size: 0x6C.
extern "C" void Graphics_FillBackgroundStagingSlotAndMarkDirty(MemorySlots* p,int bank,unsigned slot,int value) {switch(bank){case 0:case 1:switch(slot){case 0:memset(GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage_Variant2,value,0x1000);break;case 1:memset(GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage,value,0x600);break;}break;}p->slots[slot+bank*4]=1;}
