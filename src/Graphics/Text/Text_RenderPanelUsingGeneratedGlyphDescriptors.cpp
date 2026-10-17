#pragma optimize_for_size off
#include <globaldefs.h>

typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;
extern "C" char data_020ee8e8[];
extern "C" char data_020ee904[];
extern "C" char data_020ee920[];
extern "C" char data_020ee8cc[];
extern "C" const short data_020ee820[];
extern "C" void BuildRecordsWithCumulativeHalfProductOffsets(void*, int, const void*, const void*, const void*, const void*);
extern "C" void ClearTwoWordsAndFollowingByte(void*);
extern "C" void WriteFirstWordValue(void*, int);
extern "C" void Object_SetWord4AndByte8(void*, const void*, int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadSupportedFirmwareLanguage();
extern "C" void func_0205b234(void*, int, int, void*, int, int);

// Original: arm9/main @ 0x020E0EC4; symbol: func_020e0ec4; size: 0xB0.
extern "C" ARM void Text_RenderPanelUsingGeneratedGlyphDescriptors(void* self, int start, int length) {
    char glyphData[0xa8];
    char renderState[12];
    BuildRecordsWithCumulativeHalfProductOffsets(glyphData, 0xe,
                  data_020ee920, data_020ee8cc, data_020ee8e8, data_020ee904);
    ClearTwoWordsAndFollowingByte(renderState);
    WriteFirstWordValue(renderState, start + length);
    Object_SetWord4AndByte8(renderState, glyphData, 0xe);
    unsigned panelBase = (unsigned)self + 0x2ec;
    void* panelTarget = (void*)(panelBase + 0x400);
    (void)_ZN9GameState11GetInstanceEv();
    int tableIndex = GameState_ReadSupportedFirmwareLanguage();
    func_0205b234(renderState, data_020ee820[tableIndex],
                  6, panelTarget, 0xf, 0);
}
