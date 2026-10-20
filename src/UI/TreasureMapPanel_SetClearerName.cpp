#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(const char *, char *, int);
extern "C" char TreasureMapPanel_SetClearerName_Text[];
ARM
#pragma optimization_level 4
// Original: arm9/main @ 0x02026528; symbol: func_02026528; size: 0x44.
extern "C" void TreasureMapPanel_SetClearerName(int base, char *text, int flag, int last) {
    if (text != 0 && *(signed char *)text != 0) {
        char *field=(char *)base+0x324;
        Text_MapInputBytesToVariableLengthOutputSequences(text, field+0x400, 1);
        return;
    }
    char *field=(char *)base+0x324;
    strcpy(field+0x400, TreasureMapPanel_SetClearerName_Text);
}
