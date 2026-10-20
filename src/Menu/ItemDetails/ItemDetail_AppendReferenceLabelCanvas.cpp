#include <globaldefs.h>
ARM
extern "C" void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char*);
extern "C" int Menu_BindSharedTextCanvas(char*,short,short,short,short);
extern "C" void ItemDetail_RenderEnabledReferenceLabels(char*,char*);
extern "C" int Menu_UploadSharedTextCanvas(char*,int,unsigned short,int);
// Original data: arm9/ov023 @ 0x21ff9e0; symbol: data_ov023_021ff9e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov023.md.
extern "C" char MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov023 @ 0x021E0EB8; symbol: AppendSharedTextCanvasAndAdvanceBuffer; size: 0x8c.
extern "C" void ItemDetail_AppendReferenceLabelCanvas(char* self){
char canvas[224];TextCanvas_InitializeLayoutAndTransferDefaults((unsigned char*)canvas);if(Menu_BindSharedTextCanvas(canvas,0,0,28,6)){if(!(*(unsigned short*)(self+0x774)&0x400))ItemDetail_RenderEnabledReferenceLabels(self+0xcc,canvas);int size=Menu_UploadSharedTextCanvas(canvas,*(int*)(self+0x75c),(unsigned short)*(int*)(MenuBindSharedTextCanvas_UnknownRoleZeroInitializedStorage+12),0);*(int*)(self+0x75c)+=size;}
}
