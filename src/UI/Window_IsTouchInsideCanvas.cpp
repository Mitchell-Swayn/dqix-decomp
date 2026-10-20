struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2114e54; symbol: data_02114e54.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 112 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant4[];extern "C" void ReadSelectedCoordinatePair(void*,int*,int*);extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
// Original: arm9/main @ 0x0205DF38; symbol: func_0205df38; size: 0xD4.
extern "C" int Window_IsTouchInsideCanvas(unsigned char* object,unsigned key){int x,y;if(!*(int*)(object+0x98))return 0;if(!*(int*)(object+0x9c))return 0;if(Main_UnknownRoleZeroInitializedStorage_Variant4[0x55]){ReadSelectedCoordinatePair(Main_UnknownRoleZeroInitializedStorage_Variant4,&x,&y);unsigned char* rect=(unsigned char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(object),key);if(rect){short left=*(short*)(rect+0xac),width=*(short*)(rect+0xa8),top=*(short*)(rect+0xae),height=*(short*)(rect+0xaa);short right=left+width,bottom=top+height;if(x>(short)(left<<3)&&x<(short)(right<<3)&&y>(short)(top<<3)&&y<(short)(bottom<<3))return 1;}}return 0;}
