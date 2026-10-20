#include <globaldefs.h>
ARM
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short*,unsigned);
extern "C" int ReadSelectedCoordinatePair(void*,int*,int*);
extern "C" int Geometry_TestPointWithinScaledTextureRectangle(void*,int,int,int);
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned short KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original: arm9/ov017 @ 0x021AB1A4; symbol: func_ov017_021ab1a4; size: 0xAC.
extern "C" int Graphics_TestNewMaskOrPointOutsideTwoRectangles(unsigned char* p){
 int result=0;
 if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2))result=1;
 if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]){
 int x,y;
 ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);
 if(!Geometry_TestPointWithinScaledTextureRectangle(*(void**)(p+0x18),0,(short)x,(short)y)){
 if(!Geometry_TestPointWithinScaledTextureRectangle(*(void**)(p+0x18),1,(short)x,(short)y))result=1;
 }
 }
 return result;
}
