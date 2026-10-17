#include <globaldefs.h>
ARM
extern "C" void func_ov002_02156080(void *state, short *first, short *second);
extern "C" void *ResolveIndexedRecordAndReturnSecondWord(void *base, void *offset);
extern "C" int AppendFormatText(char *output, const char *text);
// Original: arm9/ov002 @ 0x0215F644; symbol: func_ov002_0215f644; size: 0x60.
extern "C" void GameState_AppendResolvedIndexedFormatText(void *state, char *output) {
    if (!output) return;
    unsigned char scratch[0x14];
    func_ov002_02156080(state, (short *)(scratch + 2), (short *)scratch);
    short selected = *(short *)((char *)state + 0x1b00 + 0xfe);
    short recordIndex = *(short *)(scratch + 2 + selected * 2);
    short offset = (short)(recordIndex + 0xfb4);
    const char *text = (const char *)ResolveIndexedRecordAndReturnSecondWord((char *)state + 0x20, (void *)(int)offset);
    AppendFormatText(output, text);
}
