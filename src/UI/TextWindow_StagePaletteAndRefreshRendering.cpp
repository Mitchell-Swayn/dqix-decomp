#include <globaldefs.h>
// Original data: arm9/main @ 0x20e7af8; symbol: data_020e7af8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000c618c618ff7f0a0f0a0fb5565a6bff7fff7fff7fff7fff7fa5140000ff7f.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x21077fc; symbol: data_021077fc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned TextLayoutRenderVisibleStream_UnknownRoleZeroInitializedStorage;extern "C" char TextWindowStagePaletteAndRefreshRendering_UnknownRoleInitializedBytes[];extern "C" void _Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(unsigned,const void*,unsigned,unsigned,bool,bool);extern "C" void Object3D_InitializeExtendedAnimationWrapper(void*);extern "C" void TextWindow_RenderAndTransferDisplayBuffers(void*,int);
// Original: arm9/main @ 0x020432C4; symbol: func_020432c4; size: 0xA4.
extern "C" ARM void TextWindow_StagePaletteAndRefreshRendering(char* object){char* descriptor=*(char**)(object+0x1e28);if(descriptor)TextLayoutRenderVisibleStream_UnknownRoleZeroInitializedStorage=(*(unsigned*)(descriptor+0x68)<<16)>>13;_Z17StageMemoryToVRAM13VRAMSubregionPKvjjbb(0,TextWindowStagePaletteAndRefreshRendering_UnknownRoleInitializedBytes,TextLayoutRenderVisibleStream_UnknownRoleZeroInitializedStorage,32,true,true);for(int i=0;i<128;++i){Object3D_InitializeExtendedAnimationWrapper(object+0x9b8+i*28);(object+i)[0x17b8]=0;}TextWindow_RenderAndTransferDisplayBuffers(object,0);}
