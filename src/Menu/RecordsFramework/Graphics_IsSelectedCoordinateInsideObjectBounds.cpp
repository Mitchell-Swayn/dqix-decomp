#include <globaldefs.h>
ARM
extern "C" void MenuHitRegion_GetBounds(unsigned char*,unsigned short*,unsigned short*,unsigned short*,unsigned short*);
extern "C" int ReadSelectedCoordinatePair(void*,int*,int*);
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original: arm9/ov023 @ 0x021FD46C; symbol: func_ov023_021fd46c; size: 0x8C.
extern "C" int Graphics_IsSelectedCoordinateInsideObjectBounds(unsigned char* object) {
if(object[12]&16)return 0;
int x,y;
unsigned short left,top,right,bottom;
MenuHitRegion_GetBounds(object,&left,&top,&right,&bottom);
ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);
if(left<=x && x<right && top<=y && y<bottom)return 1;
return 0;
}
