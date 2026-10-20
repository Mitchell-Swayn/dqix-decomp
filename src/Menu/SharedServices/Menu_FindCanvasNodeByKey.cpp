#include <globaldefs.h>
ARM
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void**, unsigned short);
// Original: arm9/ov004 @ 0x0215E47C; symbol: func_ov004_0215e47c; size: 0x20.
extern "C" void* Menu_FindCanvasNodeByKey(void* self, unsigned short value) { void** head = (void**)Menu_GetDisplayRecordRegistry(self); void* result = MenuRecordList_LocateByKey(head, value); if (!result) result = 0; return result; }
