#include <globaldefs.h>
#include <Resource/Script.h>
struct TextSelection {
    unsigned int unknown0 : 21;
    unsigned int type : 4;
    unsigned int unknown1 : 6;
    unsigned int alternate : 1;
    unsigned int unknown4;
    char extra[1];
};
struct BuildTextContext { unsigned char flags,padding[3]; char* output; TextSelection* selection; };
struct PrefixText { char bytes[7]; };
struct LineDelimiter { char bytes[2]; };
extern "C" {
// Original data: arm9/main @ 0x21098e8; symbol: data_021098e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern BuildTextContext BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage;
extern const PrefixText Script_RenderSelectedTextAndConditionalExtraStrings_MarkupPAGE;
// Original data: arm9/main @ 0x20e8dac; symbol: data_020e8dac.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0a00.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern const LineDelimiter ScriptRenderSelectedTextAndConditionalExtraStrings_UnknownRoleInitializedBytes;
void* TextContext_GetSharedInstance();
void TextMarkup_ExpandAndWrapText(void*,int,const char*,char*,int,int,int);
const char* Text_LookupStandardString(int);
unsigned int String_CountBytesUntilTerminator(const char*);
void __clear(void*,unsigned int);
void Text_MapInputBytesToVariableLengthOutputSequences(const char*,char*,int);
void Text_AppendRawPrefixAndRenderedValue(char**,const char*,const char*,unsigned int);
}
// Original: arm9/main @ 0x02099004; symbol: func_02099004; size: 0x300.
extern "C" int Script_RenderSelectedTextAndConditionalExtraStrings(Script::Parameter* params) {
    params[0].ToInt();
    unsigned int type=params[1].ToInt();
    if (BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage.selection->type != type) return 0;
    void* renderer=TextContext_GetSharedInstance();
    params[2].ToInt();
    const char* text=params[3].ToString();
    if (BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage.selection->alternate) params+=5;
    else { params+=4; text=(params++)->ToString(); }
    if (BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage.flags & 16) text+=17;
    TextMarkup_ExpandAndWrapText(renderer,12,text,BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage.output,227,0,1);
    struct TextScratch {
        LineDelimiter delimiter;
        char prefix[10];
        char* cursor;
        char chunk[32];
        char header[32];
        char converted[1024];
    } scratch;
    char* output=BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage.output;
    scratch.cursor=output+strlen(output);
    *(PrefixText*)scratch.prefix=Script_RenderSelectedTextAndConditionalExtraStrings_MarkupPAGE;
    unsigned int prefixLength=String_CountBytesUntilTerminator(scratch.prefix);
    TextMarkup_ExpandAndWrapText(renderer,12,Text_LookupStandardString(1002),scratch.header,227,0,1);
    scratch.delimiter=ScriptRenderSelectedTextAndConditionalExtraStrings_UnknownRoleInitializedBytes;
    const char* extra;
    if ((BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage.flags & 32) && *(extra=BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage.selection->extra)) {
        memcpy(scratch.cursor,scratch.prefix,prefixLength);
        scratch.cursor+=prefixLength;
        unsigned int headerLength=strlen(scratch.header);
        memcpy(scratch.cursor,scratch.header,headerLength);
        scratch.cursor+=headerLength;
        int length=String_CountBytesUntilTerminator(extra);
        int offset=0;
        do {
            int count=length-offset;
            if (count>19) count=19;
            __clear(scratch.chunk,32);
            memcpy(scratch.chunk,extra+offset,count);
            __clear(scratch.converted,1024);
            Text_MapInputBytesToVariableLengthOutputSequences(scratch.chunk,scratch.converted,1);
            scratch.cursor+=sprintf(scratch.cursor,scratch.converted);
            offset+=19;
            if (offset>=length) break;
            scratch.cursor+=sprintf(scratch.cursor,scratch.delimiter.bytes);
        } while (true);
    }
    const char* first=params[0].ToString();
    const char* second=params[1].ToString();
    const char* third=params[2].ToString();
    const char* finalText=params[3].ToString();
    const char* selected=0;
    if (BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage.flags & 2) selected=first;
    else if (BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage.flags & 4) selected=second;
    else if (BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage.flags & 8) selected=third;
    if (selected) Text_AppendRawPrefixAndRenderedValue(&scratch.cursor,selected,scratch.prefix,prefixLength);
    selected=0;
    if (BuildRequestBufferAndExecuteScript_UnknownRoleZeroInitializedStorage.flags & 1) selected=finalText;
    if (selected) Text_AppendRawPrefixAndRenderedValue(&scratch.cursor,selected,scratch.prefix,prefixLength);
    return 1;
}
