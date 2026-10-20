#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2105fd8; symbol: data_02105fd8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1536 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21065d8; symbol: data_021065d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4096 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage_Variant2[],GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage[];extern "C" void Graphics_CopyClippedTileRectangleToScreenBlocks(void*,void*,int,int,int,int,int,int,int,unsigned short);
// Original: arm9/main @ 0x0203B8BC; symbol: func_0203b8bc; size: 0xC0.
extern "C" void Graphics_UpdateSelectedBackgroundTileBuffer(char* p,int row,int col,int a,int b,int c,int d,int e,unsigned short key){*(int*)(p+(col+row*4)*4+64)=1;if(row==1){switch(col){case 0:Graphics_CopyClippedTileRectangleToScreenBlocks(p,GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage_Variant2,64,32,a,b,c,d,e,key);break;case 1:Graphics_CopyClippedTileRectangleToScreenBlocks(p,GraphicsClearSubBackgroundCharacterBuffers_UnknownRoleZeroInitializedStorage,32,24,a,b,c,d,e,key);break;}}}
