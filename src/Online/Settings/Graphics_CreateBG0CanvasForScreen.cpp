#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d38; symbol: data_ov031_02290d38.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x22493b0; symbol: data_ov031_022493b0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2000.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
// Original data: arm9/ov031 @ 0x22493b2; symbol: data_ov031_022493b2.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 180020000c00.
// Observed span: 6 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned short GraphicsCreateBG0CanvasForScreen_UnknownRoleInitializedBytes_Variant3[],GraphicsCreateBG0CanvasForScreen_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/ov031 @ 0x22493ac; symbol: data_ov031_022493ac.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00008001.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" const unsigned short GraphicsCreateBG0CanvasForScreen_UnknownRoleInitializedBytes[];
extern "C" void* Memory_AllocateZeroedBlock(unsigned,unsigned);
extern "C" void TextCanvas_InitializeRowMajorCharacterSurface(unsigned,unsigned,unsigned,unsigned,unsigned);
extern "C" unsigned GetSubBG0ScreenBase();
extern "C" unsigned GetMainBG0ScreenBase();
extern "C" void Graphics_FillScreenBlockTilesWithPalette(unsigned short*,int,int,int,int,int,unsigned,unsigned);
extern "C" void WfcUtility_ClearTextCanvas(void*,int);
extern "C" void Graphics_UploadDirtyBgCharacterData(void*);
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(int,void(*)(void*),void*,int);
struct Canvas {unsigned words[6];void* self;void* settings;unsigned a,b;void* pixels;void* task;};
// Original: arm9/ov031 @ 0x0223C560; symbol: func_ov031_0223c560; size: 0x178.
extern "C" Canvas* Graphics_CreateBG0CanvasForScreen(int screen,int settings) {
 unsigned short rows=GraphicsCreateBG0CanvasForScreen_UnknownRoleInitializedBytes_Variant3[screen*2];
 unsigned short columns=GraphicsCreateBG0CanvasForScreen_UnknownRoleInitializedBytes_Variant2[screen*2];
 Canvas* canvas=(Canvas*)(WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage+0x610+screen*48);
 canvas->pixels=Memory_AllocateZeroedBlock(columns*rows*32,32);
 if(screen==1) {
  *(volatile unsigned short*)0x04001008&=~0x40;
  *(volatile unsigned short*)0x04001008=(*(volatile unsigned short*)0x04001008&0x43)|0xc00;
 } else {
  *(volatile unsigned short*)0x04000008&=~0x40;
  *(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&0x43)|0xc00;
 }
 TextCanvas_InitializeRowMajorCharacterSurface((unsigned)canvas,(unsigned)canvas->pixels,columns,rows,4);
 unsigned char* config=WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage+settings*8;
 int one=1;
 canvas->self=canvas;
 canvas->settings=config;
 canvas->a=one;
 canvas->b=one;
 unsigned screenBase;
 if(screen==1) screenBase=GetSubBG0ScreenBase();
 else screenBase=GetMainBG0ScreenBase();
 int zero=0;
 int tile=GraphicsCreateBG0CanvasForScreen_UnknownRoleInitializedBytes[screen];
 Graphics_FillScreenBlockTilesWithPalette((unsigned short*)screenBase,columns,rows,zero,zero,32,tile,15);
 WfcUtility_ClearTextCanvas(canvas,0);
 canvas->task=WfcUtility_CreateTaskWithBorrowedContext(1,Graphics_UploadDirtyBgCharacterData,WfcUtilityDestroyTextCanvasServices_UnknownRoleZeroInitializedStorage+0x67c+screen,200);
 return canvas;
}
