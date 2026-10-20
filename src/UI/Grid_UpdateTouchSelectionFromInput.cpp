#pragma opt_common_subs off
#include <globaldefs.h>
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];extern "C" void ReadSelectedCoordinatePair(void*,unsigned*,unsigned*);extern "C" int Grid_FindCellContainingPointAndSelectIndex(void*,unsigned,unsigned);struct Owner{unsigned handle;char pad[44];int index;char gap[24];unsigned char unchanged,pad4d,active;};
// Original: arm9/main @ 0x0205BC2C; symbol: func_0205bc2c; size: 0xB0.
extern "C" ARM int Grid_UpdateTouchSelectionFromInput(Owner* owner){if(!owner->handle)return 0;unsigned first,second;ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&first,&second);if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]&&!owner->active){owner->active=1;int old=owner->index;owner->index=Grid_FindCellContainingPointAndSelectIndex(owner,first,second);if(owner->index<0){owner->active=0;return 0;}owner->unchanged=1;if(old!=owner->index)owner->unchanged=0;return 1;}owner->unchanged=0;owner->active=0;return 0;}
