#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];extern "C" void ReadSelectedCoordinatePair(void*,int*,int*);extern "C" int Input_FindContainingOriginRelativeRectangle(unsigned,int,int);
// Original: arm9/main @ 0x020E1E4C; symbol: func_020e1e4c; size: 0x64.
extern "C" int Input_ResolveCoordinateHitIndexOrNegativeStatus(unsigned key){int x,y;if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]){ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);int result=Input_FindContainingOriginRelativeRectangle(key,(short)x,(short)y);if(result<0)result=-2;return result;}return -1;}
