#include <globaldefs.h>
ARM
#pragma force_active on
struct ObjectTextCanvas;
struct CanvasOperations { void (*reserved)(); void (*clear)(ObjectTextCanvas*,int); };
struct ObjectTextCanvas { unsigned surface[5]; CanvasOperations* operations; ObjectTextCanvas* self; void* settings; unsigned enabled,dirty; void* characters; unsigned short characterIndex; unsigned char width,height; };
extern "C" {
// Original data: arm9/ov031 @ 0x02290d38; symbol: data_ov031_02290d38; initially zero, text-canvas services and pool at offset 0x670.
extern unsigned char* WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage;
void* WfcUtility_PopPointerRingBack(void*);
void* WfcUtility_AllocateObjectCharacterRange(int,int,int,unsigned*);
unsigned NNSi_G2dCalcRequiredOBJ(int,int);
void TextCanvas_InitializePartitionedCharacterSurface(ObjectTextCanvas*,void*,int,int,int);
}
#pragma always_inline on
static inline void* ObjectCharacterAddress(int screen,unsigned index)
{
    unsigned base=screen==1 ? 0x06600000 : 0x06400000;
    return (void*)(base+(index<<7));
}
// Original: arm9/ov031 @ 0x0223c458; symbol: func_ov031_0223c458; size: 0xdc.
// Reserves object characters and a canvas, initializes its partitioned surface, clears it, and attaches the selected settings.
extern "C" ObjectTextCanvas* WfcUtility_CreateObjectTextCanvas(int screen,int width,int height,int allocation,unsigned* objectCount,int settings)
{
    ObjectTextCanvas* canvas=(ObjectTextCanvas*)WfcUtility_PopPointerRingBack(*(void**)(WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage+0x670));
    canvas->width=width;
    canvas->height=height;
    unsigned index;
    canvas->characters=WfcUtility_AllocateObjectCharacterRange(screen,width*height,allocation,&index);
    canvas->characterIndex=index;
    *objectCount=NNSi_G2dCalcRequiredOBJ(width,height);
    TextCanvas_InitializePartitionedCharacterSurface(canvas,ObjectCharacterAddress(screen,index),width,height,4);
    canvas->operations->clear(canvas,0);
    unsigned char* configuration=WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage+settings*8;
    int one=1;
    canvas->self=canvas;
    canvas->settings=configuration;
    canvas->enabled=one;
    canvas->dirty=one;
    return canvas;
}
#pragma force_active reset
