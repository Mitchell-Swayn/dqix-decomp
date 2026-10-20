struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define I(p,o) (*(int*)((p)+(o)))
#define U(p,o) (*(unsigned*)((p)+(o)))
#define H(p,o) (*(unsigned short*)((p)+(o)))
#define S(p,o) (*(short*)((p)+(o)))
#define B(p,o) (*(unsigned char*)((p)+(o)))
#define C(p,o) (*(signed char*)((p)+(o)))
#define V(p,o) (*(char**)((p)+(o)))
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" WindowCanvasRecord* Window_GetSelectedTextCanvas(WindowCanvasOwner*);extern "C" bool TextCanvas_IsReady(int);extern "C" int ReadSelectedCoordinatePair(void*,int*,int*);extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original: arm9/main @ 0x0205DD08; symbol: Graphics_TestTouchInSelectedRecordSideMargins; size: 0x11C.
extern "C" int Window_GetTouchedCanvasSideMargin(char* self){
if(!V(self,0x98))return 0;if(!V(self,0x9c))return 0;if(!B(Main_UnknownRoleZeroInitializedStorage_Variant4,0x55))return 0;char* record=(char*)(unsigned)Window_GetSelectedTextCanvas((WindowCanvasOwner*)(self));if(!record)return 0;if(!TextCanvas_IsReady((int)record))return 0;if(!(B(record,0xc5)&8))return 0;int x,y;ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);short top=S(record,0xaa)<<3;short left=S(record,0xac)<<3;short right=(short)((short)(S(record,0xa8)<<3)+left);short bottom=(short)((short)(S(record,0xae)<<3)+top);short px=x,py=y;if(bottom-12<py&&py<bottom){if(left<px&&px<left+12)return -1;if(right-12<px&&px<right)return 1;}return 0;
}
