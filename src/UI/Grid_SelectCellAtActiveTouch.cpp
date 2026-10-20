#include <globaldefs.h>
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];extern "C" void ReadSelectedCoordinatePair(void*,unsigned*,unsigned*);extern "C" int Grid_FindCellContainingPointAndSelectIndex(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x0205BEA0; symbol: func_0205bea0; size: 0x58.
extern "C" ARM bool Grid_SelectCellAtActiveTouch(unsigned object){if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]){unsigned a,b;ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&a,&b);return Grid_FindCellContainingPointAndSelectIndex(object,a,b)>=0;}return false;}
