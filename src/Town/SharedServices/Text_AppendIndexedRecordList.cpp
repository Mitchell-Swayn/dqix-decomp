#include <globaldefs.h>
ARM
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char* p,int n,const char* text);
extern "C" int TextMarkup_AppendFrameTag(char* p,int a0,int a1,int a2,int a3,int a4);
extern "C" int TextMarkup_AppendCursorTag(char *out,int value);
extern "C" int Text_AppendFormatString(char* p,const char* text);
extern "C" void* ResourceStringTable_GetTextByKey(void* a,void* b);
// Original data: arm9/ov003 @ 0x217fe7f; symbol: data_ov003_0217fe7f.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0a00000000.
// Observed span: 5 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" char TextAppendIndexedRecordList_UnknownRoleInitializedBytes[];
// Original: arm9/ov003 @ 0x0215B6F0; symbol: func_ov003_0215b6f0; size: 0xB4.
extern "C" void Text_AppendIndexedRecordList(char *self, char *out, int prefix) {
    if (out) {
        int cursor = *(signed char *)(self + 0x584);
        if (prefix) TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
        TextMarkup_AppendCursorTag(out,cursor);
        for (int i = 0; i < *(unsigned char *)(self + 0x589); ++i) {
            int index = *(signed char *)(self + i + 0x58a);
            const char *text = (const char *)ResourceStringTable_GetTextByKey(self + 0x64, (void *)index);
            Text_AppendFormattedIntegerAndStringFragment(out,i,text);
            if (i != *(unsigned char *)(self + 0x589) - 1) Text_AppendFormatString(out,TextAppendIndexedRecordList_UnknownRoleInitializedBytes);
        }
    }
}
