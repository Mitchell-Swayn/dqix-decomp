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
extern BuildTextContext data_021098e8;
extern const PrefixText data_020e8dae;
extern const LineDelimiter data_020e8dac;
void* ReadWordFieldAtOffset1C();
void ProcessSixStagesUsingSharedWordScratchBuffer(void*,int,const char*,char*,int,int,int);
const char* LookupGlobalResourceByKey(int);
unsigned int String_CountBytesUntilTerminator(const char*);
void __clear(void*,unsigned int);
void Text_MapInputBytesToVariableLengthOutputSequences(const char*,char*,int);
void Text_AppendRawPrefixAndRenderedValue(char**,const char*,const char*,unsigned int);
}
// Original: arm9/main @ 0x02099004; symbol: func_02099004; size: 0x300.
extern "C" int Script_RenderSelectedTextAndConditionalExtraStrings(Script::Parameter* params) {
    params[0].ToInt();
    unsigned int type=params[1].ToInt();
    if (data_021098e8.selection->type != type) return 0;
    void* renderer=ReadWordFieldAtOffset1C();
    params[2].ToInt();
    const char* text=params[3].ToString();
    if (data_021098e8.selection->alternate) params+=5;
    else { params+=4; text=(params++)->ToString(); }
    if (data_021098e8.flags & 16) text+=17;
    ProcessSixStagesUsingSharedWordScratchBuffer(renderer,12,text,data_021098e8.output,227,0,1);
    struct TextScratch {
        LineDelimiter delimiter;
        char prefix[10];
        char* cursor;
        char chunk[32];
        char header[32];
        char converted[1024];
    } scratch;
    char* output=data_021098e8.output;
    scratch.cursor=output+strlen(output);
    *(PrefixText*)scratch.prefix=data_020e8dae;
    unsigned int prefixLength=String_CountBytesUntilTerminator(scratch.prefix);
    ProcessSixStagesUsingSharedWordScratchBuffer(renderer,12,LookupGlobalResourceByKey(1002),scratch.header,227,0,1);
    scratch.delimiter=data_020e8dac;
    const char* extra;
    if ((data_021098e8.flags & 32) && *(extra=data_021098e8.selection->extra)) {
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
    if (data_021098e8.flags & 2) selected=first;
    else if (data_021098e8.flags & 4) selected=second;
    else if (data_021098e8.flags & 8) selected=third;
    if (selected) Text_AppendRawPrefixAndRenderedValue(&scratch.cursor,selected,scratch.prefix,prefixLength);
    selected=0;
    if (data_021098e8.flags & 1) selected=finalText;
    if (selected) Text_AppendRawPrefixAndRenderedValue(&scratch.cursor,selected,scratch.prefix,prefixLength);
    return 1;
}
