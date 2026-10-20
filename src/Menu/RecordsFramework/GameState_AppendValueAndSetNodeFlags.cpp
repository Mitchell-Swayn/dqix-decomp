#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
// Original: arm9/ov023 @ 0x021F65D4; symbol: func_ov023_021f65d4; size: 0x2C.
extern "C" void* GameState_AppendValueAndSetNodeFlags(void* unused, unsigned short value, unsigned int flags) { void** head = (void**)Menu_GetDisplayRecordRegistry(unused); void* node = MenuRecordList_LocateByKey(head, value); if (node) *((unsigned char*)node + 0xc) |= flags; return node; }
