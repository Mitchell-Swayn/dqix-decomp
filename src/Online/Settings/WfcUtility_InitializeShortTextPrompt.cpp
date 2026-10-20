#include <globaldefs.h>
ARM
extern "C" int Graphics_CreateBG0CanvasForScreen(...);
extern "C" int Graphics_LoadAlternateMainBG2AndSetPriorities(...);
extern "C" int MIi_CpuClear16(...);
extern "C" int MIi_CpuCopy16(...);
extern "C" int WfcUtility_MarkBackgroundTextCanvasDirty(...);
extern "C" int WfcUtility_GetConnectionTextResult(...);
extern "C" int WfcUtility_SetConnectionEventCallback(...);
extern "C" int WfcUtility_SetMainLoopCallback(...);
extern "C" int WfcUtility_SetConnectionEventCallback(...);
extern "C" int WfcUtility_GetConnectionTextResult(...);
extern "C" int Graphics_LoadAlternateMainBG2AndSetPriorities(...);
extern "C" int System_ConfigureDisplayPlaneAndCallback(...);
extern "C" int WfcUtility_MarkShortTextPromptCompleted(...);
extern "C" int WfcUtility_CreateSlidingDialog(...);
extern "C" int Graphics_CreateBG0CanvasForScreen(...);
extern "C" int WfcUtility_RenderCanvasAlignedText(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov031 @ 0x2290c78; symbol: data_ov031_02290c78.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x0222A6C4; symbol: CreateCanvasCopyHalfwordListAndInstallCallbacks.
extern "C" void WfcUtility_InitializeShortTextPrompt(void){
char* state=C(WfcUtility_GetConnectionTextResult());void* canvas=(void*)Graphics_CreateBG0CanvasForScreen(0,0);B(ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage,1)=0;B(ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage,0)=0;Graphics_LoadAlternateMainBG2AndSetPriorities();short text[11];MIi_CpuClear16(0,text,22);MIi_CpuCopy16(state+2,text,B(state,1)*2);WfcUtility_RenderCanvasAlignedText(canvas,8,53,240,28,2,0x480,text);WfcUtility_MarkBackgroundTextCanvasDirty(canvas);WfcUtility_SetConnectionEventCallback(WfcUtility_MarkShortTextPromptCompleted);WfcUtility_CreateSlidingDialog(29,4,0,-1,0);WfcUtility_SetMainLoopCallback(System_ConfigureDisplayPlaneAndCallback);
}
