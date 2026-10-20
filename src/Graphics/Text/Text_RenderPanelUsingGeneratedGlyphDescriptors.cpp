#pragma optimize_for_size off
#include <globaldefs.h>

typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
// Original data: arm9/main @ 0x20ee8e8; symbol: data_020ee8e8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 20002000200020002000200010002000200020002000200020001000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char TextRenderPanelUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes_Variant3[];
// Original data: arm9/main @ 0x20ee904; symbol: data_020ee904.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 10001000100010001000100010000800080008000800080008000800.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char TextRenderPanelUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes_Variant4[];
// Original data: arm9/main @ 0x20ee920; symbol: data_020ee920.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00002000400060008000a000c00000002000400060008000a000c0002000000002000000c001000000400000.
// Observed span: 44 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char TextRenderPanelUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes_Variant5[];
// Original data: arm9/main @ 0x20ee8cc; symbol: data_020ee8cc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000000000000000000000001000100010001000100010001000.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char TextRenderPanelUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes_Variant2[];
// Original data: arm9/main @ 0x20ee820; symbol: data_020ee820.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex b000b000b000b000b800b800.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const short TextRenderPanelUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes[];
extern "C" void TextCanvas_BuildPackedRegionDescriptors(void*, int, const void*, const void*, const void*, const void*);
extern "C" void TextCanvas_InitializeRegionCanvas(void*);
extern "C" void TextCanvas_SetPixelBuffer(void*, int);
extern "C" void TextCanvas_SetRegions(void*, const void*, int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadSupportedFirmwareLanguage();
extern "C" void TextCanvas_DrawStringAndMeasureAdvance(void*, int, int, void*, int, int);

// Original: arm9/main @ 0x020E0EC4; symbol: func_020e0ec4; size: 0xB0.
extern "C" ARM void Text_RenderPanelUsingGeneratedGlyphDescriptors(void* self, int start, int length) {
    char glyphData[0xa8];
    char renderState[12];
    TextCanvas_BuildPackedRegionDescriptors(glyphData, 0xe,
                  TextRenderPanelUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes_Variant5, TextRenderPanelUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes_Variant2, TextRenderPanelUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes_Variant3, TextRenderPanelUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes_Variant4);
    TextCanvas_InitializeRegionCanvas(renderState);
    TextCanvas_SetPixelBuffer(renderState, start + length);
    TextCanvas_SetRegions(renderState, glyphData, 0xe);
    unsigned panelBase = (unsigned)self + 0x2ec;
    void* panelTarget = (void*)(panelBase + 0x400);
    (void)_ZN9GameState11GetInstanceEv();
    int tableIndex = GameState_ReadSupportedFirmwareLanguage();
    TextCanvas_DrawStringAndMeasureAdvance(renderState, TextRenderPanelUsingGeneratedGlyphDescriptors_UnknownRoleInitializedBytes[tableIndex],
                  6, panelTarget, 0xf, 0);
}
