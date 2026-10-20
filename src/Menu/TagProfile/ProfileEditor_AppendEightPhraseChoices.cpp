#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char* p,int n,const char* text);
extern "C" int TextMarkup_AppendFrameTag(char* p,int a0,int a1,int a2,int a3,int a4);
extern "C" int TextMarkup_AppendCursorTag(char *out,int value);
extern "C" int Text_AppendFormatString(char* p,const char* text);
struct T;
extern "C" unsigned int MessageTextTable_FindTextById(T *p,int key);
// Original: arm9/ov012 @ 0x02189CBC; symbol: func_ov012_02189cbc; size: 0xAC.
extern "C" void ProfileEditor_AppendEightPhraseChoices(char *self, char *out, int prefix) {
    if (out) {
        int cursor = *(int *)(self + 0x13e0);
        if (prefix) TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
        TextMarkup_AppendCursorTag(out,cursor);
        for (int i = 0; i < 8; ++i) {
            if (i != 0) Text_AppendFormatString(out,*(const char **)(self + 0x1378));
            const char *text = (const char *)MessageTextTable_FindTextById((T *)(self + 0x133c), (short)(i + 0x27d8));
            Text_AppendFormattedIntegerAndStringFragment(out,i,text);
        }
    }
}
