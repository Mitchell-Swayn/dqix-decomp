#include <globaldefs.h>
ARM
struct Packed {unsigned a:12,b:4,c:5,d:4,e:2,hasE:1,hasABC:1,x:2,flag31:1;unsigned unused:9; signed title:10; signed detail:11;unsigned spare:2;};
extern "C" {
char* _ZN9GameState11GetInstanceEv();char* TextContext_GetSharedInstance(char*);void* Network_GetConnectionManager();int Network_IsSessionActive(void*);char* GameState_GetObjectWithFlag100(void*,int);char* GameObject_GetLinkedIndexedState(char*);int Network_GetLocalMemberId(void*);
int TextMarkup_AppendXPositionTag(char*,int);int TextMarkup_AppendYTag(char*,int);int Text_AppendFormattedXYPair(char*,int,int);int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);int AppendFormattedNumberAndText(char*,const char*,int);int Text_AppendFormatString(char*,const char*);int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);char* MessageTextTable_FindTextById(void*,short);void TextMarkup_ExpandAndWrapText(void*,int,const char*,void*,int,int,unsigned);void TextContext_SetNumericArgument(void*,int,unsigned);void TextContext_SetNumericArgumentAlignment(void*,int,int);void TextContext_SetNumericArgumentWidth(void*,int,int);void* memset(void*,int,unsigned);
}
#define TEXT(k) MessageTextTable_FindTextById(*(void**)(self+0x5f4),(short)(k))
#define X(v) TextMarkup_AppendXPositionTag(out,v)
#define APP(v) Text_AppendFormatString(out,v)
#define STAGE(k) TextMarkup_ExpandAndWrapText(scratch,10,TEXT(k),buffer,256,0,0)
#define FIELD(v,t) TextContext_SetNumericArgument(scratch,0,v); TextContext_SetNumericArgumentAlignment(scratch,0,1);TextContext_SetNumericArgumentWidth(scratch,0,t)
// Original: arm9/ov023 @ 0x021E868C; symbol: func_ov023_021e868c; size: 0x634.
extern "C" void Text_FormatCharacterPackedSummary(char* self){
 char* state=_ZN9GameState11GetInstanceEv();char* scratch=TextContext_GetSharedInstance(state);void* connection=Network_GetConnectionManager();char* member=0;
 if(!Network_IsSessionActive(connection)){char* p=GameState_GetObjectWithFlag100(state,0);if(p)member=GameObject_GetLinkedIndexedState(p);}else{char* p=GameState_GetObjectWithFlag100(state,Network_GetLocalMemberId(connection));if(p)member=GameObject_GetLinkedIndexedState(p);}
 if(!member)return;
 char* out;Packed* record=(Packed*)(state+0x569c);out=*(char**)(self+0x5d8);char buffer[32]={};
 X((208-TextLayout_ComputeWidthWithGlyphSpacing(member+0x3c,0))>>1);AppendFormattedNumberAndText(out,member+0x3c,16);
 char* text=TEXT(record->title+10000);
 Text_AppendFormattedIntegerAndStringFragment(out,0,TEXT(2));APP(TEXT(108));X(((110-TextLayout_ComputeWidthWithGlyphSpacing(text,0))>>1)+86);APP(text);APP(TEXT(0));
 Text_AppendFormattedIntegerAndStringFragment(out,1,TEXT(3));X(76);APP(TEXT(108));
 if(record->flag31)X(90);else{Text_AppendFormattedXYPair(out,110,52);STAGE(120);APP(buffer);Text_AppendFormattedXYPair(out,90,40);}
 if(record->hasABC){FIELD(record->a,4);STAGE(100);APP(buffer);memset(buffer,0,32);FIELD(record->b,2);STAGE(101);APP(buffer);memset(buffer,0,32);FIELD(record->c,2);STAGE(102);APP(buffer);APP(TEXT(0));}
 else{STAGE(110);APP(buffer);memset(buffer,0,32);STAGE(111);APP(buffer);memset(buffer,0,32);STAGE(112);APP(buffer);APP(TEXT(0));}
 int value=record->detail;short key=value+20000;if(value<700)key=value;
 text=TEXT(key);TextMarkup_AppendYTag(out,66);Text_AppendFormattedIntegerAndStringFragment(out,2,TEXT(4));X(76);APP(TEXT(108));X(((110-TextLayout_ComputeWidthWithGlyphSpacing(text,0))>>1)+86);APP(text);APP(TEXT(0));
 key=109;if(record->hasE)key=record->d+30000;
 text=TEXT(key);Text_AppendFormattedIntegerAndStringFragment(out,3,TEXT(5));X(76);APP(TEXT(108));X(((110-TextLayout_ComputeWidthWithGlyphSpacing(text,0))>>1)+86);APP(text);
}
