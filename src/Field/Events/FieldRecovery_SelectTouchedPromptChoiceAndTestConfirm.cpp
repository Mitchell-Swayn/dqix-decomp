#include <globaldefs.h>
ARM
#define D(p) ((unsigned)(p))
#define U32(p) (*(unsigned*)(p))
#define U16(p) (*(unsigned short*)(p))
#define S16(p) (*(short*)(p))
#define U8(p) (*(unsigned char*)(p))
#define S8(p) (*(signed char*)(p))
#define V32(p) (*(volatile unsigned*)(p))
#define V16(p) (*(volatile unsigned short*)(p))
extern "C" unsigned TextCanvas_CreateAndConfigureDisplayPart(...);
extern "C" unsigned Input_IsKeyMaskNewlyPressed(...);
extern "C" unsigned ReadSelectedCoordinatePair(...);
extern "C" unsigned TextCanvas_SelectEntryAtPoint(...);
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
// Original: arm9/ov017 @ 0x021ab0c0; symbol: Graphics_SelectTouchedDisplayPartAndReportInput; size: 0xe4.
extern "C" unsigned FieldRecovery_SelectTouchedPromptChoiceAndTestConfirm(unsigned self){
unsigned char changed=0;if(Input_IsKeyMaskNewlyPressed(D(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage),0x401))changed=1;
if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]&&U32(self+0x44)){int x,y;unsigned object=U32(self+0x18);ReadSelectedCoordinatePair(D(Main_UnknownRoleZeroInitializedStorage_Variant4),D(&x),D(&y));S16(self+0x4e)=S16(U32(self+0x44));int hit=TextCanvas_SelectEntryAtPoint(object,S16(self+0x48),(short)x,(short)y,D(&changed),1);if(hit<0)return 0;S16(U32(self+0x44))=hit;if(S16(self+0x4e)!=S16(U32(self+0x44))){S16(object+0x36)=S16(U32(self+0x44));TextCanvas_CreateAndConfigureDisplayPart(object,S16(self+0x48));}}
return changed;
}