#include <globaldefs.h>
#include <World/WorldScriptRecordNode.h>
ARM
struct RequirementBits {unsigned short low:2, requirement:7, selector:6, flag:1;};
struct Sprite;struct T;struct Entry{unsigned value;float score;};
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*,int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" unsigned char Vocation_GetSkillLineId(unsigned,unsigned);
extern "C" unsigned MessageTextTable_FindTextById(T*,int);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" void TextCanvas_RenderStyledTextAndMeasure(Sprite*,short,short,char*,unsigned char,unsigned char,short*,short*,int);
extern "C" void* memset(void*,int,unsigned);
extern "C" WorldScriptRecordNode* WorldScriptRecordNode_FindNthSelectorMatch(WorldScriptRecordNode**,int,int);
extern "C" WorldScriptRecordNode* WorldScriptRecordList_FindNodeByNonnegativeKey(WorldScriptRecordNode**,int);
extern "C" void Util_QuickSortPairsByFloatScore(Entry*,int,int,int);
extern "C" int sprintf(char*,const char*,...);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
extern "C" void String_ReplaceBracketedNamesByRowColumnTable(const signed char*,signed char*,int,unsigned,unsigned,int);
// Original data: arm9/ov013 @ 0x2187dc8; symbol: data_ov013_02187dc8.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0102030405060708090a0b0c0eff0000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov013.md.
extern "C" signed char DrawSortedSelectorEntries_UnknownRoleInitializedBytes[];
// Original data: arm9/ov013 @ 0x2187ec3; symbol: data_ov013_02187ec3.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 2564000000000000000000000000000000000000000000000000000000.
// Observed span: 29 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov013.md.
extern "C" char DrawSortedSelectorEntries_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/ov013 @ 0x02187A58; symbol: func_ov013_02187a58; size: 0x330.
// Sorts ten selector records by numeric requirement and draws their values and resolved text.
extern "C" void DrawSortedSelectorEntries(char* p,Sprite* canvas){
 if(!canvas)return;
 void* member=GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(),p[0x67]);if(!member)return;
 int selector;unsigned char* object=GameObject_GetLinkedIndexedState(member);if(!object)return;
 selector=Vocation_GetSkillLineId(*(unsigned*)(object+0x950)&255,*(unsigned char*)(p+0x68));
 int available=*(object+selector+0x464);int y=30;
 char* title=(char*)MessageTextTable_FindTextById((T*)(p+4),selector);
 short width,height;
 TextCanvas_RenderStyledTextAndMeasure(canvas,(short)((256-TextLayout_ComputeWidthWithGlyphSpacing(title,0))>>1),12,title,10,15,&width,&height,0);
 Entry entries[10];memset(entries,0,80);
 for(unsigned char i=0;i<10;i++){
 Entry* entry=entries+i;WorldScriptRecordNode* node=WorldScriptRecordNode_FindNthSelectorMatch((WorldScriptRecordNode**)(p+12),selector,i);
 if(node){entry->value=node->key;entry->score=(unsigned)((RequirementBits*)&node->selector)->requirement;}
 }
 Util_QuickSortPairsByFloatScore(entries,0,9,0);
 WorldScriptRecordNode* first=WorldScriptRecordList_FindNodeByNonnegativeKey((WorldScriptRecordNode**)(p+12),(short)entries[0].value);
 for(int i=0;DrawSortedSelectorEntries_UnknownRoleInitializedBytes[i]>=0;i++)if(DrawSortedSelectorEntries_UnknownRoleInitializedBytes[i]==first->selector.selectorBits.selectorValue){p[0x6a]=i;break;}
 for(unsigned char i=0;i<10;i++){
 selector=3;WorldScriptRecordNode* node=WorldScriptRecordList_FindNodeByNonnegativeKey((WorldScriptRecordNode**)(p+12),(short)entries[i].value);
 if(node){int requirement=((RequirementBits*)&node->selector)->requirement;if(available>=requirement)selector=15;
 char number[32]={0};sprintf(number,DrawSortedSelectorEntries_UnknownRoleInitializedBytes_Variant2,requirement);
 TextCanvas_RenderStyledTextAndMeasure(canvas,(short)(34-TextLayout_ComputeWidthWithGlyphSpacing(number,0)),(short)y,number,10,(unsigned char)selector,&width,&height,0);
 char text[256]={0};char resolved[256]={0};
 TextMarkup_ExpandAndWrapText((void*)TextContext_GetSharedInstance(),10,(void*)node->opaque4,text,256,0,0);
 String_ReplaceBracketedNamesByRowColumnTable((signed char*)text,(signed char*)resolved,1,0,0,0);
 if(node->selector.selectorBits.unknown15 && p[0x6a]>=0){
 (*(short**)(p+0x50))[i]=TextLayout_ComputeWidthWithGlyphSpacing(resolved,0)+46;(*(short**)(p+0x54))[i]=y-2;
 if(selector==15)(*(char**)(p+0x58))[i]=1;
 }
 TextCanvas_RenderStyledTextAndMeasure(canvas,46,(short)y,resolved,10,(unsigned char)selector,&width,&height,0);y+=15;
 }
 }
}
