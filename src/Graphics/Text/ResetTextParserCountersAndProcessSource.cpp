#include <globaldefs.h>
#include <std_library_functions.h>

extern "C" int TextStream_TestFFPrefixMarker(void*, const char*);
extern "C" int Text_ClassifyControlCodesFF20ThroughFF25(void*, const char*);
extern "C" int Text_IsHalfwordControlCodeFF01ThroughFF0D(void*, const char*);
extern "C" char* TextStream_FindEncodedControlToken(void*, unsigned short, const void*);
extern "C" int TextLookup_FindMatchingByteKeyEntry(const char*, unsigned char);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void*);
extern "C" void Graphics_ClearAndStageSharedBuffers(void*);
extern "C" void TextLayout_MeasureAndReuseRetainedPrefix(void*);

// Original: arm9/main @ 0x0206AA28; symbol: func_0206aa28; size: 0x1D0.
extern "C" void ResetTextParserCountersAndProcessSource(unsigned char* self)
{
    *(int*)(self + 0x7c) = 0;
    *(int*)(self + 0x6c) = 0;
    *(int*)(self + 0x70) = 0;
    *(int*)(self + 0x74) = 0;
    *(int*)(self + 0x78) = 0;
    char* source = *(char**)(self + 0x54);
    char* dest = *(char**)(self + 0x50);
    unsigned int tagMask = 0xffe0;
    bool sawInvalid = false;
    int wideBytes = 0;
    for (;;) {
        if (*source == '\0') break;
        wideBytes = 0;
        if (TextStream_TestFFPrefixMarker(self, source)) {
            wideBytes = (Text_ClassifyControlCodesFF20ThroughFF25(self, source) + 1) * 2;
            memcpy(dest, source, wideBytes);
            dest += wideBytes;
            *(int*)(self + 0x70) += wideBytes;
        }
        if (*(unsigned int*)(self + 0x68) < (unsigned int)(source - *(char**)(self + 0x48))) {
            *(int*)(self + 0x998) = 0;
            break;
        }
        if (TextStream_TestFFPrefixMarker(self, source)) {
            if (Text_IsHalfwordControlCodeFF01ThroughFF0D(self, source)) {
                if (sawInvalid) *(char**)(self + 0x58) = source;
                else {
                    unsigned char saved = self[0x19cc];
                    TextWindow_ResetGlyphBuffersAndFrameContexts(self);
                    Graphics_ClearAndStageSharedBuffers(self);
                    self[0x19cc] = saved;
                }
                break;
            }
            unsigned short marker;
            memcpy(&marker, source, 2);
            source += wideBytes;
            if ((marker & tagMask) == tagMask) {
                unsigned int decoded = (marker ^ tagMask) << 16;
                decoded >>= 16;
                decoded += 0xfd0;
                decoded += 0xf000;
                marker = (unsigned short)decoded;
                source = TextStream_FindEncodedControlToken(self, marker, *(void**)(self + 0x48));
                if (source == 0) {
                    unsigned char saved = self[0x19cc];
                    TextWindow_ResetGlyphBuffersAndFrameContexts(self);
                    Graphics_ClearAndStageSharedBuffers(self);
                    self[0x19cc] = saved;
                    break;
                }
            }
        } else {
            sawInvalid = true;
            int copySize = 1;
            int charset = TextLookup_FindMatchingByteKeyEntry(source, self[0x19dc]);
            if (charset) copySize = ((signed char)*(signed char*)(charset + 5) << 26) >> 26;
            memcpy(dest, source, copySize);
            dest += copySize;
            *(int*)(self + 0x70) += 1;
            source += copySize;
        }
    }
    TextLayout_MeasureAndReuseRetainedPrefix(self);
}
