#include <globaldefs.h>
ARM
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int TextMarkup_AppendSDRCTag(char*,int,int,int,int,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int Text_AppendFormatString(char*,const char*);
// Original: arm9/ov023 @ 0x021DA100; symbol: Text_AppendTwoIndexedRecordRows; size: 0xDC.
// Appends cursor markup and two formatted record entries, optionally prefixing a five-argument text tag.
extern "C" void Text_AppendTwoIndexedRecordRows(void* manager, char* output, int includeArguments) {
    if (!output) return;
    int cursor = *(signed char*)((char*)manager + 0xd84);
    if (includeArguments) TextMarkup_AppendFrameTag(output,cursor,8,5,5,5);
    TextMarkup_AppendCursorTag(output,cursor);
    TextMarkup_AppendSDRCTag(output,0,0,0,0x30,0x28);
    for (int row=0; row<2; ++row) {
        short key = (short)(row + 0x465a);
        const char* text = (const char*)ResourceStringTable_GetTextByKey((char*)manager+0xe0,key);
        Text_AppendFormattedIntegerAndStringFragment(output,row,text);
        if (row != 1) {
            const char* format = (const char*)ResourceStringTable_GetTextByKey((char*)manager+0xe0,0x4273);
            Text_AppendFormatString(output,format);
        }
    }
}
