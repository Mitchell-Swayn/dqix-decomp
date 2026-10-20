#include <globaldefs.h>
ARM
extern "C" int TextMarkup_AppendSizeTag(char *out,int value);
extern "C" int Text_AppendFormatString(char* p,const char* text);
extern "C" void* ResourceStringTable_GetTextByKey(void* a,void* b);
// Original: arm9/ov013 @ 0x02185900; symbol: func_ov013_02185900; size: 0x90.
extern "C" void Graphics_AppendModeSelectedSizeTaggedText(unsigned char *self, char *out) {
    TextMarkup_AppendSizeTag(out, 12);
    if (self[0x63c] == 4) {
        Text_AppendFormatString(out, (const char*)ResourceStringTable_GetTextByKey(self + 0x620, (void*)1000));
    } else if (self[0x63c] == 3) {
        Text_AppendFormatString(out, (const char*)ResourceStringTable_GetTextByKey(self + 0x620, (void*)1001));
    } else if (self[0x63c] == 2) {
        Text_AppendFormatString(out, (const char*)ResourceStringTable_GetTextByKey(self + 0x620, (void*)1002));
    }
}
