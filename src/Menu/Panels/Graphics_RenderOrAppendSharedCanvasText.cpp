#include <globaldefs.h>
ARM
extern "C" int TextCanvas_InitializeLayoutAndTransferDefaults(...);
extern "C" int Menu_BindSharedTextCanvas(...);
extern "C" int ItemDetail_RenderQuantityRows(...);
extern "C" int Menu_UploadSharedTextCanvas(...);
// Original data: arm9/ov023 @ 0x21ff9e0; symbol: data_ov023_021ff9e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" unsigned char MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[];
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov023 @ 0x021DD344; symbol: Graphics_RenderOrAppendSharedCanvasText; size: 0xc0.
// Graphics RenderOrAppendSharedCanvasText from listed field operations and calls.
extern "C" void Graphics_RenderOrAppendSharedCanvasText(char* self){if(!(((unsigned)B(self,0x79b)<<30)>>31))return;char canvas[224];TextCanvas_InitializeLayoutAndTransferDefaults(canvas);if(!Menu_BindSharedTextCanvas(canvas,3,16,26,6))return;ItemDetail_RenderQuantityRows(self,canvas);if(P(self,0x760))Menu_UploadSharedTextCanvas(canvas,P(self,0x760),(unsigned short)W(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage,12),1);else{unsigned size=Menu_UploadSharedTextCanvas(canvas,P(self,0x75c),(unsigned short)W(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage,12),1);P(self,0x760)=P(self,0x75c);W(self,0x764)=size;P(self,0x75c)+=size;}}
