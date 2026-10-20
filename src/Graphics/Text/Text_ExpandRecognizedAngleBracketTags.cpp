#pragma thumb off
#pragma optimization_level 2

struct TagHandler{const char* name;void(*apply)(const char*,char**,void*,int);};
// Original data: arm9/main @ 0x20e7e5c; symbol: data_020e7e5c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex e6060f0238820602fa060f02388206020000000000000000.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" {char* TextMarkup_FindClosingAngleBracket(const char*);int String_TestSecondIsPrefixOfFirst(const char*,const char*);unsigned String_CountBytesUntilTerminator(const char*);int Runtime_ParseStringAsBaseTenInteger(const char*);extern TagHandler TextExpandRecognizedAngleBracketTags_UnknownRoleProcedureReferenceRecords[];}
// Original: arm9/main @ 0x0206831C; symbol: func_0206831c; size: 0xFC.
extern "C" void Text_ExpandRecognizedAngleBracketTags(void* owner,const char* input,char* destination){if(!input || !destination)return;char* output=destination;char character;for(;;){character=*input;if(!character)break;bool handled;if(character=='<'){char* end=TextMarkup_FindClosingAngleBracket(input);if(end){TagHandler* handler;const char* tag=input+1;handled=false;for(handler=TextExpandRecognizedAngleBracketTags_UnknownRoleProcedureReferenceRecords;handler->name;++handler){if(String_TestSecondIsPrefixOfFirst(tag,handler->name)){if(handler->apply){int index=0;unsigned length=String_CountBytesUntilTerminator(handler->name);if(tag[length]>='1' && tag[length]<='9')index=Runtime_ParseStringAsBaseTenInteger(tag+length)-1;handler->apply(tag,&output,owner,index);}input=end+1;handled=true;break;}}if(handled)continue;}}*output=*input++;++output;}*output=character;}
