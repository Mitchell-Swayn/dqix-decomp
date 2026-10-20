#include <globaldefs.h>
ARM
extern "C" void PartyMenu_BuildAvailableConnectionActions(void *state, short *first, short *second);
extern "C" void *ResourceStringTable_GetTextByKey(void *base, void *offset);
extern "C" int Text_AppendFormatString(char *output, const char *text);
// Original: arm9/ov002 @ 0x0215F644; symbol: func_ov002_0215f644; size: 0x60.
extern "C" void PartyMenu_AppendSelectedMiscellaneousCommandHelp(void *state, char *output) {
    if (!output) return;
    unsigned char scratch[0x14];
    PartyMenu_BuildAvailableConnectionActions(state, (short *)(scratch + 2), (short *)scratch);
    short selected = *(short *)((char *)state + 0x1b00 + 0xfe);
    short recordIndex = *(short *)(scratch + 2 + selected * 2);
    short offset = (short)(recordIndex + 0xfb4);
    const char *text = (const char *)ResourceStringTable_GetTextByKey((char *)state + 0x20, (void *)(int)offset);
    Text_AppendFormatString(output, text);
}
