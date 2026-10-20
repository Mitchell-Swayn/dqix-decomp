#include <globaldefs.h>
ARM
extern "C" void TextWindow_ResetGlyphPoolAndParserState();extern "C" void Graphics_ClearAndStageSharedBuffers(void*);extern "C" void TextWindow_ResetFrameContextsAndMessageFlags(void*);
// Original: arm9/main @ 0x02043204; symbol: func_02043204; size: 0x20.
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void* p){TextWindow_ResetGlyphPoolAndParserState();Graphics_ClearAndStageSharedBuffers(p);TextWindow_ResetFrameContextsAndMessageFlags(p);}
