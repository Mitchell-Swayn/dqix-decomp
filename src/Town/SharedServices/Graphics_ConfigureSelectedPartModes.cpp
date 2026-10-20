#include <globaldefs.h>
ARM
extern "C" void TextCanvas_SetEntryTextAlignmentMode(char *p,int i,int v);
extern "C" void TextCanvas_HideEntry(unsigned char *p,int id);
extern "C" void TextCanvas_ShowEntry(unsigned char *p,int id);
extern "C" void TextCanvas_SetEntryMessageKey(char *p,int i,short v);
struct ModeSource { int pad[2]; unsigned low : 12; unsigned mode : 2; unsigned high : 18; };
// Original: arm9/ov003 @ 0x0217818C; symbol: func_ov003_0217818c; size: 0x8C.
extern "C" void Graphics_ConfigureSelectedPartModes(char *self, ModeSource *source, int group, int part) {
    char *object = *(char **)(self + 0x89c);
    unsigned char enabled = 1;
    if (source) enabled = source->mode ? enabled : 0;
    if (enabled) {
        TextCanvas_ShowEntry((unsigned char *)object, group);
        TextCanvas_SetEntryMessageKey(object, part, 0x48);
        TextCanvas_SetEntryTextAlignmentMode(object, part, 1);
    } else {
        TextCanvas_HideEntry((unsigned char *)object, group);
        TextCanvas_SetEntryMessageKey(object, part, 0x46);
        TextCanvas_SetEntryTextAlignmentMode(object, part, 1);
    }
}
