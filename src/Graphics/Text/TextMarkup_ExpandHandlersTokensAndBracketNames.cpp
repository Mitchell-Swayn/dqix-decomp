#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
#pragma always_inline on
struct TagHandler{const char *name;void (*apply)(const char*,char**,void*,int);};
struct Token {const char *name;signed char operation,value;short pad;};struct TokenTable {Token entries[16];};
struct Kind{unsigned kind:4;unsigned remaining:28;};
// Original data: arm9/main @ 0x20e7e8c; symbol: data_020e7e8c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex ff060f0220910602ae070f02589106025f080f028c91060242080f02c09106023b070f02f89106025e070f02000000000000000000000000.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e7f04; symbol: data_020e7f04.
// Contains original relocated data addresses. Referenced targets and raw storage values are recorded; semantic role and record layout remain unresolved.
// Initial values: hex 09070f0200000000bc070f0200010000f0060f02010100000e070f02020000001d070f020201000027070f020300000013070f020301000018070f0203020000 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" TagHandler TextMarkupExpandHandlersTokensAndBracketNames_UnknownRoleProcedureReferenceRecords[];extern "C" const TokenTable TextMarkupExpandHandlersTokensAndBracketNames_UnknownRoleDataReferences;
extern "C" const char TextMarkup_ExpandHandlersTokensAndBracketNames_TextWPN[],TextMarkup_ExpandHandlersTokensAndBracketNames_TextACTER[],TextMarkup_ExpandHandlersTokensAndBracketNames_TextError[];
extern "C" char *TextMarkup_FindClosingAngleBracket(const char*);extern "C" int String_TestSecondIsPrefixOfFirst(const char*,const char*),Runtime_ParseStringAsBaseTenInteger(const char*),RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);extern "C" unsigned String_CountBytesUntilTerminator(const char*);extern "C" char *TextMarkup_AppendInflectedNameAndArticles(char**,unsigned,int,int,int,int);extern "C" char* GameState_GetObjectWithFlag100(GameState*,int);
// Original: arm9/main @ 0x02069234; symbol: func_02069234; size: 0x3C0.
extern "C" void TextMarkup_ExpandHandlersTokensAndBracketNames(char *owner,const char *input,char *destination){
if(!input||!destination)return;char *output=destination;char character;
for(;;){character=*input;if(!character)break;
if(character=='<'){char *end=TextMarkup_FindClosingAngleBracket(input);if(end){bool handled=false;const char *tag=input+1;for(TagHandler *handler=TextMarkupExpandHandlersTokensAndBracketNames_UnknownRoleProcedureReferenceRecords;handler->name;handler++){if(String_TestSecondIsPrefixOfFirst(tag,handler->name)){if(handler->apply){int index=0;unsigned length=String_CountBytesUntilTerminator(handler->name);if(tag[length]>='1'&&tag[length]<='9')index=Runtime_ParseStringAsBaseTenInteger(tag+length)-1;handler->apply(tag,&output,owner,index);}input=end+1;handled=true;break;}}if(handled)continue;
int mode=-1;int variant=0;int category=-1;int extra=-1;unsigned textId=0;TokenTable table=TextMarkupExpandHandlersTokensAndBracketNames_UnknownRoleDataReferences;handled=false;
for(Token *token=table.entries;;token++){const char *name=token->name;if(!name)break;unsigned length=String_CountBytesUntilTerminator(name);if(!RuntimeMemory_CompareByteRanges(tag,name,length)){handled=true;tag+=length;int index=0;if(token->value<0&&*tag>='1'&&*tag<='9')index=Runtime_ParseStringAsBaseTenInteger(tag)-1;
switch(token->operation){case 0:mode=token->value;break;case 1:variant=token->value;break;case 2:category=token->value;break;case 3:extra=token->value;break;case 4:textId=*(unsigned*)(owner+index*4+0x18);break;case 5:textId=*(unsigned*)(owner+index*4+0x20);break;case 6:textId=*(unsigned*)(owner+index*4);break;case 7:textId=*(unsigned*)(owner+index*4+0x10);break;case 8:textId=*(unsigned*)(owner+index*4+8);break;case 9:textId=*(unsigned*)(owner+0x2c);break;}}}
if(textId)output=TextMarkup_AppendInflectedNameAndArticles(&output,textId,mode,variant,category,extra);if(handled){input=end+1;continue;}}}
else if(character=='['){if(!RuntimeMemory_CompareByteRanges(input,TextMarkup_ExpandHandlersTokensAndBracketNames_TextWPN,4)){input+=4;char *object=GameState_GetObjectWithFlag100(GameState::GetInstance(),*(signed char*)(owner+0x1880));if(object){char *item=*(char**)(object+0x150)+0x294;if(item&&*(short*)(item+0x18)>0&&((Kind*)(item+8))->kind==0)output+=sprintf(output,*(char**)(item+4));}goto skipBracket;}
else if(!RuntimeMemory_CompareByteRanges(input,TextMarkup_ExpandHandlersTokensAndBracketNames_TextACTER,6)){input+=6;output+=sprintf(output,owner+0x3ac);goto skipBracket;}
++input;*output=character;++output;continue;
skipBracket: while(*input!=']'&&*input)++input;if(!*input){output+=sprintf(output,TextMarkup_ExpandHandlersTokensAndBracketNames_TextError);break;}++input;continue;}
*output=*input++;++output;
}*output=0;
}
