#pragma thumb off
#pragma optimization_level 2

struct TagHandler{const char* name;void(*apply)(const char*,char**,void*,int);};
extern "C" {char* FindUnpairedGreaterThanCharacter(const char*);int String_TestSecondIsPrefixOfFirst(const char*,const char*);unsigned String_CountBytesUntilTerminator(const char*);int Runtime_ParseStringAsBaseTenInteger(const char*);extern TagHandler data_020e7e5c[];}
// Original: arm9/main @ 0x0206831C; symbol: func_0206831c; size: 0xFC.
extern "C" void Text_ExpandRecognizedAngleBracketTags(void* owner,const char* input,char* destination){if(!input || !destination)return;char* output=destination;char character;for(;;){character=*input;if(!character)break;bool handled;if(character=='<'){char* end=FindUnpairedGreaterThanCharacter(input);if(end){TagHandler* handler;const char* tag=input+1;handled=false;for(handler=data_020e7e5c;handler->name;++handler){if(String_TestSecondIsPrefixOfFirst(tag,handler->name)){if(handler->apply){int index=0;unsigned length=String_CountBytesUntilTerminator(handler->name);if(tag[length]>='1' && tag[length]<='9')index=Runtime_ParseStringAsBaseTenInteger(tag+length)-1;handler->apply(tag,&output,owner,index);}input=end+1;handled=true;break;}}if(handled)continue;}}*output=*input++;++output;}*output=character;}
