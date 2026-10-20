#include <globaldefs.h>
ARM
#pragma optimization_level 4
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
struct Nibble{unsigned char lower:4,upper:4;};
extern "C" unsigned WfcUtility_MarkBackgroundTextCanvasDirty(...);
extern "C" unsigned WfcUtility_RenderCanvasAlignedText(...);
extern "C" unsigned WfcUtility_ClearTextCanvas(...);
// Original data: arm9/ov031 @ 0x2248ee0; symbol: data_ov031_02248ee0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 323535000b0010003f404142430000002900000000000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityDrawIpv4EditorDigits_UnknownRoleInitializedBytes[];
// Original data: arm9/ov031 @ 0x2248f20; symbol: data_ov031_02248f20.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 313d495a6672838f9bacb8c4.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityDrawIpv4EditorDigits_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov031 @ 0x2290c98; symbol: data_ov031_02290c98.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0222df84; symbol: DrawTwelveIndexedBufferCells.
extern "C" void WfcUtility_DrawIpv4EditorDigits(){struct Rect{unsigned short x,y,w,h;}rect;rect.x=H(WfcUtilityDrawIpv4EditorDigits_UnknownRoleInitializedBytes,14);rect.y=H(WfcUtilityDrawIpv4EditorDigits_UnknownRoleInitializedBytes,16);rect.w=11;rect.h=16;WfcUtility_ClearTextCanvas((void*)U((void*)U(WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage,0),0),0);struct Pair{unsigned short value,zero;}pair;pair.zero=0;unsigned style=2;const unsigned char* table=WfcUtilityDrawIpv4EditorDigits_UnknownRoleInitializedBytes_Variant2;for(int i=0;i<12;i++){unsigned char* p=(unsigned char*)U(WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage,0);pair.value=B(p+i,8);unsigned x=*table++;rect.x=x;WfcUtility_RenderCanvasAlignedText((void*)U(p,0),x,((volatile unsigned short*)&rect)[1],((volatile unsigned short*)&rect)[2],((volatile unsigned short*)&rect)[3],style,0x480,&pair);}WfcUtility_MarkBackgroundTextCanvasDirty((void*)U((void*)U(WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage,0),0));}
