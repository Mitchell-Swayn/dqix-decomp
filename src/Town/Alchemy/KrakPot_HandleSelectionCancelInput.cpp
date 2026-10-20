#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e30; symbol: data_02114e30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[],Main_UnknownRoleZeroInitializedStorage_Variant4[],Main_UnknownRoleZeroInitializedStorage[];
int Input_IsKeyMaskNewlyPressed(void*,int);
int Window_IsVisible(void*);
int Input_TestPressedKeyBitOne(void*);
void ReadSelectedCoordinatePair(void*,int*,int*);
int Geometry_TestPointWithinScaledTextureRectangle(void*,short,short,short);
}

// Original: arm9/ov006 @ 0x02158B78; symbol: func_ov006_02158b78; size: 0xB0.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM int KrakPot_HandleSelectionCancelInput(char* p)
{
    int result=0;
    if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,2)) result=1;
    void* object=*(void**)(p+0x18);
    if(object && Window_IsVisible(object))
    {
        if(Input_TestPressedKeyBitOne(*(void**)(p+0x18))) result=1;
    }
    else if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55])
    {
        int x,y;
        ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);
        if(!Geometry_TestPointWithinScaledTextureRectangle(*(void**)(p+0x14),*(short*)(p+0x36e),(short)x,(short)y)) result=1;
    }
    return result;
}
