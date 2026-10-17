#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char* p,int n,const char* text);
extern "C" int AppendFiveFormattedArguments(char* p,int a0,int a1,int a2,int a3,int a4);
extern "C" int TextMarkup_AppendCursorTag(char *out,int value);
extern "C" int AppendFormatText(char* p,const char* text);
extern "C" void* ResolveIndexedRecordAndReturnSecondWord(void* a,void* b);
extern "C" char data_ov003_0217fe7f[];
// Original: arm9/ov003 @ 0x0215B6F0; symbol: func_ov003_0215b6f0; size: 0xB4.
extern "C" void Text_AppendIndexedRecordList(char *self, char *out, int prefix) {
    if (out) {
        int cursor = *(signed char *)(self + 0x584);
        if (prefix) AppendFiveFormattedArguments(out,cursor,8,5,5,5);
        TextMarkup_AppendCursorTag(out,cursor);
        for (int i = 0; i < *(unsigned char *)(self + 0x589); ++i) {
            int index = *(signed char *)(self + i + 0x58a);
            const char *text = (const char *)ResolveIndexedRecordAndReturnSecondWord(self + 0x64, (void *)index);
            Text_AppendFormattedIntegerAndStringFragment(out,i,text);
            if (i != *(unsigned char *)(self + 0x589) - 1) AppendFormatText(out,data_ov003_0217fe7f);
        }
    }
}
