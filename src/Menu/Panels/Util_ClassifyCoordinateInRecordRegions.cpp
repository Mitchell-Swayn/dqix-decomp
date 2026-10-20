struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
struct Record;struct Owner;
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" int Main_UnknownRoleZeroInitializedStorage_Variant4[];
// Original: arm9/ov023 @ 0x021E63BC; symbol: func_ov023_021e63bc; size: 0x8C.
extern "C" int Util_ClassifyCoordinateInRecordRegions(unsigned char* p){
 unsigned char* r=(unsigned char*)(Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)((Owner*)(p+0xac)),p[0x1371]);
 short a=*(short*)(r+0xac);short b=*(short*)(r+0xae);
 a*=8;b*=8;
 int x=a+10;int y=b+16;
 int cx=Main_UnknownRoleZeroInitializedStorage_Variant4[14];int cy=Main_UnknownRoleZeroInitializedStorage_Variant4[15];
 if(x<=cx && cx<=x+16 && y<=cy && cy<=y+8)return 1;
 if(x<=cx && cx<=x+16 && y+12<=cy && cy<=y+20)return -1;
 return 0;
}
