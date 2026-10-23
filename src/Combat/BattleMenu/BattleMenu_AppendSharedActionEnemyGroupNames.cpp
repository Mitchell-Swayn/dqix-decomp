#include <globaldefs.h>
ARM
#pragma force_active on
#define WORD(p,o) (*(int*)((p)+(o)))
#define UWORD(p,o) (*(unsigned*)((p)+(o)))
#define HALF(p,o) (*(short*)((p)+(o)))
#define UHALF(p,o) (*(unsigned short*)((p)+(o)))
#define BYTE(p,o) (*(unsigned char*)((p)+(o)))
#define SBYTE(p,o) (*(signed char*)((p)+(o)))
#define PTR(p,o) (*(char**)((p)+(o)))
struct GameState; struct Output; struct Record;
extern "C" void __clear(void*,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* GameState_FindIndexedObjectWithFlag400(GameState*,unsigned);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void TextLayout_ResetFormattingWorkspace(signed char*);
extern "C" void TextContext_SetNumericArgument(unsigned*,int,unsigned);
extern "C" void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" void* Text_ClearNameDescriptor(void*);
extern "C" void BuildNameDescriptorAndLastLetterState(Output*,unsigned char*,int);
extern "C" void Text_CopySelectedNameDescriptorFields(const Record*,Record*,unsigned);
extern "C" int BattleMenu_CountEnemyTargetsWithGroupKey(unsigned char*,unsigned);
extern "C" int BattleMenu_HasTouchSelectionChanged(void*);
extern "C" void String_FormatAndTrimSuffix(void*,char*);
// Original data: arm9/ov000 @ 0x02184060; symbol: data_ov000_02184060.
// Literal <X=120> followed by a space; appended after grouped enemy/member-name text to position subsequent text.
// Values (char[9]): "<X=120> " + NUL (9 bytes; includes trailing space).
extern "C" char BattleMenu_GroupedNameColumnSuffix[];

// Original: arm9/ov000 @ 0x0217A688; symbol: func_ov000_0217a688; size: 0x26C.
// Formats grouped enemy names for the shared action using the global selected row and group counts.
extern "C" void BattleMenu_AppendSharedActionEnemyGroupNames(char* self,char* view,int total,char* out) {
 char text[128],nameA[128],nameB[128]; unsigned desc[3],fallback[3];
 int previous; int had; int selected; int cursor; int i; int decorated;
 if(!out) return;
 previous=-1;
 selected=0;had=0;
 cursor=*(signed char*)(self+0x1c);
 for(i=0;i<total;i++) {
  unsigned value=*(unsigned*)(self+0x1d1c+i*4);
  if(previous!=value) {
   previous=value;
   int n=BattleMenu_CountEnemyTargetsWithGroupKey((unsigned char*)self,value);
   if(i<=cursor && cursor<i+n) selected=i;
  }
 }
 signed char* display=(signed char*)TextContext_GetSharedInstance();
 GameState* game=(GameState*)_ZN9GameState11GetInstanceEv();
 const char* separator=(const char*)ResourceStringTable_GetTextByKey(self+0xb8,0);
 void* format=ResourceStringTable_GetTextByKey(self+0xb8,(void*)0x754f);
 previous=-1;
 if(BattleMenu_HasTouchSelectionChanged(self)) TextMarkup_AppendFrameTag(out,selected,8,5,5,5);
 TextMarkup_AppendCursorTag(out,selected);
 for(i=0;i<total;i++) {
  unsigned value=*(unsigned*)(self+0x1d1c+i*4);
  if(previous!=value) {
   previous=value;
   int n=BattleMenu_CountEnemyTargetsWithGroupKey((unsigned char*)self,value);
   if(!n) continue;
   if(had) Text_AppendFormatString(out,separator);
   __clear(text,128);
   int chosen=i;
   if(i<=cursor && cursor<i+n) chosen=cursor;
   TextLayout_ResetFormattingWorkspace(display);
   Text_ClearNameDescriptor(desc);
   unsigned char* member=GameState_FindIndexedObjectWithFlag400(game,*(unsigned*)(self+0x1d3c+chosen*4));
   __clear(nameA,128);__clear(nameB,128);
   if(member) {
    BuildNameDescriptorAndLastLetterState((Output*)desc,member,1);
    BuildNameDescriptorAndLastLetterState((Output*)fallback,member,0);
    String_FormatAndTrimSuffix((void*)desc[0],nameA);
    String_FormatAndTrimSuffix((void*)desc[1],nameB);
    desc[0]=(unsigned)nameA;desc[1]=(unsigned)nameB;
    Text_CopySelectedNameDescriptorFields((Record*)fallback,(Record*)desc,2);
    desc[2]&=~0x80000000;
   }
   *(unsigned**)(display+0x20)=desc;
   TextContext_SetNumericArgument((unsigned*)display,0,n);
   TextMarkup_ExpandAndWrapText(display,10,format,text,256,0,0);
   Text_AppendFormattedIntegerAndStringFragment(out,i,text);
   had=1;
  }
 }
 Text_AppendFormatString(out,BattleMenu_GroupedNameColumnSuffix);
}

