#pragma opt_common_subs off
#include <globaldefs.h>
extern "C" unsigned char data_02114e54[];extern "C" void ReadSelectedCoordinatePair(void*,unsigned*,unsigned*);extern "C" int Grid_FindCellContainingPointAndSelectIndex(void*,unsigned,unsigned);struct Owner{unsigned handle;char pad[44];int index;char gap[24];unsigned char unchanged,pad4d,active;};
// Original: arm9/main @ 0x0205BC2C; symbol: func_0205bc2c; size: 0xB0.
extern "C" ARM int UpdatePointerSelectionFromCurrentCoordinates(Owner* owner){if(!owner->handle)return 0;unsigned first,second;ReadSelectedCoordinatePair(data_02114e54,&first,&second);if(data_02114e54[0x55]&&!owner->active){owner->active=1;int old=owner->index;owner->index=Grid_FindCellContainingPointAndSelectIndex(owner,first,second);if(owner->index<0){owner->active=0;return 0;}owner->unchanged=1;if(old!=owner->index)owner->unchanged=0;return 1;}owner->unchanged=0;owner->active=0;return 0;}
