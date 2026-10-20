#include <globaldefs.h>
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];
extern "C" int Input_IsKeyMaskNewlyPressed(void*,int);
extern "C" int Window_IsVisible(void*);
extern "C" int Input_TestPressedKeyBitOne(void*);
extern "C" void ReadSelectedCoordinatePair(void*,int*,int*);
extern "C" int Geometry_TestPointWithinScaledTextureRectangle(void*,short,short,short);
// Original: arm9/ov003 @ 0x021766E8; symbol: func_ov003_021766e8; size: 0xB0.
extern "C" ARM int Shop_TestSelectionCancellation(unsigned char* self) { int result=0; if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)) result=1; void* input=*(void**)self; if(input && Window_IsVisible(input)) { if(Input_TestPressedKeyBitOne(*(void**)self)) result=1; } else if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]) { int x,y; ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y); if(!Geometry_TestPointWithinScaledTextureRectangle(*(void**)(self+0x89c),*(short*)(self+0xffe),(short)x,(short)y)) result=1; } return result; }
