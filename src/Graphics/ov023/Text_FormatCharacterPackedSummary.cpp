#include <globaldefs.h>
ARM
struct Packed {unsigned a:12,b:4,c:5,d:4,e:2,hasE:1,hasABC:1,x:2,flag31:1;unsigned unused:9; signed title:10; signed detail:11;unsigned spare:2;};
extern "C" {
char* _ZN9GameState11GetInstanceEv();char* ReadWordFieldAtOffset1C(char*);void* Object_GetGlobalConnectionState();int IsFirstWordNonzero(void*);char* GameState_GetObjectWithFlag100(void*,int);char* ReadWordFieldAtOffset150(char*);int ReadIndexedSignedField1038(void*);
int Text_AppendFormattedIntegerFragmentAt020EFE78(char*,int);int TextMarkup_AppendYTag(char*,int);int AppendFormattedPair_Main02041A90(char*,int,int);int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);int AppendFormattedNumberAndText(char*,const char*,int);int AppendFormatText(char*,const char*);int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);char* FindRecordValueByKeyOrZero(void*,short);void ProcessSixStagesUsingSharedWordScratchBuffer(void*,int,const char*,void*,int,int,unsigned);void SetOneOfSixteenWordFieldsAtOffset8B0(void*,int,unsigned);void Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(void*,int,int);void WriteBoundedIndexedByteAt902(void*,int,int);void* memset(void*,int,unsigned);
}
#define TEXT(k) FindRecordValueByKeyOrZero(*(void**)(self+0x5f4),(short)(k))
#define X(v) Text_AppendFormattedIntegerFragmentAt020EFE78(out,v)
#define APP(v) AppendFormatText(out,v)
#define STAGE(k) ProcessSixStagesUsingSharedWordScratchBuffer(scratch,10,TEXT(k),buffer,256,0,0)
#define FIELD(v,t) SetOneOfSixteenWordFieldsAtOffset8B0(scratch,0,v); Object_WriteBoundedSixteenByteArrayElementAtOffset8F1(scratch,0,1);WriteBoundedIndexedByteAt902(scratch,0,t)
// Original: arm9/ov023 @ 0x021E868C; symbol: func_ov023_021e868c; size: 0x634.
extern "C" void Text_FormatCharacterPackedSummary(char* self){
 char* state=_ZN9GameState11GetInstanceEv();char* scratch=ReadWordFieldAtOffset1C(state);void* connection=Object_GetGlobalConnectionState();char* member=0;
 if(!IsFirstWordNonzero(connection)){char* p=GameState_GetObjectWithFlag100(state,0);if(p)member=ReadWordFieldAtOffset150(p);}else{char* p=GameState_GetObjectWithFlag100(state,ReadIndexedSignedField1038(connection));if(p)member=ReadWordFieldAtOffset150(p);}
 if(!member)return;
 char* out;Packed* record=(Packed*)(state+0x569c);out=*(char**)(self+0x5d8);char buffer[32]={};
 X((208-TextLayout_ComputeWidthWithGlyphSpacing(member+0x3c,0))>>1);AppendFormattedNumberAndText(out,member+0x3c,16);
 char* text=TEXT(record->title+10000);
 Text_AppendFormattedIntegerAndStringFragment(out,0,TEXT(2));APP(TEXT(108));X(((110-TextLayout_ComputeWidthWithGlyphSpacing(text,0))>>1)+86);APP(text);APP(TEXT(0));
 Text_AppendFormattedIntegerAndStringFragment(out,1,TEXT(3));X(76);APP(TEXT(108));
 if(record->flag31)X(90);else{AppendFormattedPair_Main02041A90(out,110,52);STAGE(120);APP(buffer);AppendFormattedPair_Main02041A90(out,90,40);}
 if(record->hasABC){FIELD(record->a,4);STAGE(100);APP(buffer);memset(buffer,0,32);FIELD(record->b,2);STAGE(101);APP(buffer);memset(buffer,0,32);FIELD(record->c,2);STAGE(102);APP(buffer);APP(TEXT(0));}
 else{STAGE(110);APP(buffer);memset(buffer,0,32);STAGE(111);APP(buffer);memset(buffer,0,32);STAGE(112);APP(buffer);APP(TEXT(0));}
 int value=record->detail;short key=value+20000;if(value<700)key=value;
 text=TEXT(key);TextMarkup_AppendYTag(out,66);Text_AppendFormattedIntegerAndStringFragment(out,2,TEXT(4));X(76);APP(TEXT(108));X(((110-TextLayout_ComputeWidthWithGlyphSpacing(text,0))>>1)+86);APP(text);APP(TEXT(0));
 key=109;if(record->hasE)key=record->d+30000;
 text=TEXT(key);Text_AppendFormattedIntegerAndStringFragment(out,3,TEXT(5));X(76);APP(TEXT(108));X(((110-TextLayout_ComputeWidthWithGlyphSpacing(text,0))>>1)+86);APP(text);
}
