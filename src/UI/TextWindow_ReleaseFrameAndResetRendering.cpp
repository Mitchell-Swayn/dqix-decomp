#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void ZoneContainer_ResetRenderPartsAndDestroyAllocator(char*);
extern "C" void TextWindow_ResetGlyphRenderingAndFrameContexts(char*);
extern "C" void TextWindow_ResetGlyphPoolAndParserState(char*);
extern "C" void Graphics_ClearAndStageSharedBuffers(char*);
extern "C" void TextWindow_ResetFrameContextsAndMessageFlags(char*);
// Original: arm9/main @ 0x02043000; symbol: func_02043000; size: 0x40.
extern "C" void TextWindow_ReleaseFrameAndResetRendering(char* p){
    ZoneContainer_ResetRenderPartsAndDestroyAllocator(p+0x19e0);
    TextWindow_ResetGlyphRenderingAndFrameContexts(p);
    TextWindow_ResetGlyphPoolAndParserState(p);
    Graphics_ClearAndStageSharedBuffers(p);
    TextWindow_ResetFrameContextsAndMessageFlags(p);
    *(unsigned*)(p+0x38)=0;
}
