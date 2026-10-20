#include <globaldefs.h>
ARM
struct A;
extern "C" int Input_IsKeyMaskNewlyPressed(unsigned short* p,unsigned int mask);
extern "C" int ReadSelectedCoordinatePair(void *, int *, int *);
extern "C" int Geometry_TestPointWithinScaledTextureRectangle(void* owner,int index,int x,int y);
extern "C" unsigned int Window_IsVisible(A **p);
extern "C" bool Input_TestPressedKeyBitOne(void*);
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
// Original: arm9/ov003 @ 0x02155208; symbol: func_ov003_02155208; size: 0xB0.
extern "C" int Input_TestNewKeyOrOutsideTextureRectangle(char *self) {
    int result = 0;
    if (Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)) result = 1;
    void *input = *(void **)(self + 0x1c);
    if (input && Window_IsVisible((A **)input)) {
        if (Input_TestPressedKeyBitOne(*(void **)(self + 0x1c))) result = 1;
    } else {
        if (Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]) {
            int x,y;
            ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);
            if (!Geometry_TestPointWithinScaledTextureRectangle(*(void **)(self + 0x18),*(short *)(self + 0x1e6),(short)x,(short)y)) result = 1;
        }
    }
    return result;
}
