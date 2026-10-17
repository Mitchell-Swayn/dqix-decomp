#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
#pragma always_inline on
struct TagHandler{const char *name;void (*apply)(const char*,char**,void*,int);};
struct Token {const char *name;signed char operation,value;short pad;};struct TokenTable {Token entries[16];};
struct Kind{unsigned kind:4;unsigned remaining:28;};
extern "C" TagHandler data_020e7e8c[];extern "C" const TokenTable data_020e7f04;
extern "C" const char data_020f0904[],data_020f0909[],data_020f0910[];
extern "C" char *FindUnpairedGreaterThanCharacter(const char*);extern "C" int String_TestSecondIsPrefixOfFirst(const char*,const char*),Runtime_ParseStringAsBaseTenInteger(const char*),RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);extern "C" unsigned String_CountBytesUntilTerminator(const char*);extern "C" char *func_020e4958(char**,unsigned,int,int,int,int);extern "C" char* GameState_GetObjectWithFlag100(GameState*,int);
// Original: arm9/main @ 0x02069234; symbol: func_02069234; size: 0x3C0.
extern "C" void TextMarkup_ExpandHandlersTokensAndBracketNames(char *owner,const char *input,char *destination){
if(!input||!destination)return;char *output=destination;char character;
for(;;){character=*input;if(!character)break;
if(character=='<'){char *end=FindUnpairedGreaterThanCharacter(input);if(end){bool handled=false;const char *tag=input+1;for(TagHandler *handler=data_020e7e8c;handler->name;handler++){if(String_TestSecondIsPrefixOfFirst(tag,handler->name)){if(handler->apply){int index=0;unsigned length=String_CountBytesUntilTerminator(handler->name);if(tag[length]>='1'&&tag[length]<='9')index=Runtime_ParseStringAsBaseTenInteger(tag+length)-1;handler->apply(tag,&output,owner,index);}input=end+1;handled=true;break;}}if(handled)continue;
int mode=-1;int variant=0;int category=-1;int extra=-1;unsigned textId=0;TokenTable table=data_020e7f04;handled=false;
for(Token *token=table.entries;;token++){const char *name=token->name;if(!name)break;unsigned length=String_CountBytesUntilTerminator(name);if(!RuntimeMemory_CompareByteRanges(tag,name,length)){handled=true;tag+=length;int index=0;if(token->value<0&&*tag>='1'&&*tag<='9')index=Runtime_ParseStringAsBaseTenInteger(tag)-1;
switch(token->operation){case 0:mode=token->value;break;case 1:variant=token->value;break;case 2:category=token->value;break;case 3:extra=token->value;break;case 4:textId=*(unsigned*)(owner+index*4+0x18);break;case 5:textId=*(unsigned*)(owner+index*4+0x20);break;case 6:textId=*(unsigned*)(owner+index*4);break;case 7:textId=*(unsigned*)(owner+index*4+0x10);break;case 8:textId=*(unsigned*)(owner+index*4+8);break;case 9:textId=*(unsigned*)(owner+0x2c);break;}}}
if(textId)output=func_020e4958(&output,textId,mode,variant,category,extra);if(handled){input=end+1;continue;}}}
else if(character=='['){if(!RuntimeMemory_CompareByteRanges(input,data_020f0904,4)){input+=4;char *object=GameState_GetObjectWithFlag100(GameState::GetInstance(),*(signed char*)(owner+0x1880));if(object){char *item=*(char**)(object+0x150)+0x294;if(item&&*(short*)(item+0x18)>0&&((Kind*)(item+8))->kind==0)output+=sprintf(output,*(char**)(item+4));}goto skipBracket;}
else if(!RuntimeMemory_CompareByteRanges(input,data_020f0909,6)){input+=6;output+=sprintf(output,owner+0x3ac);goto skipBracket;}
++input;*output=character;++output;continue;
skipBracket: while(*input!=']'&&*input)++input;if(!*input){output+=sprintf(output,data_020f0910);break;}++input;continue;}
*output=*input++;++output;
}*output=0;
}
