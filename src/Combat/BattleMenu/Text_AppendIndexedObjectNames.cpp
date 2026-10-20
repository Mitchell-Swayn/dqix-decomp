#include <globaldefs.h>
ARM
extern "C" void __clear(void*,unsigned);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" void* GameState_GetIndexList(void*);
extern "C" int TextMarkup_AppendXPositionTag(char*,int);
extern "C" int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
extern "C" int TextMarkup_AppendPaletteTagForType(char*,unsigned);
extern "C" int TextMarkup_AppendCursorTag(char*,int);
extern "C" int Text_AppendFormatString(char*,const char*);
extern "C" char* GameObject_GetLinkedActionDataWhenEnabled(char*);
extern "C" void Text_FormatAndConditionallyUppercaseOutput(const char*,char*,int);
extern "C" void* ResourceStringTable_GetTextByKey(void*,void*);
extern "C" void* BattleMenu_FindPartyCommandRecord(void*,int);
extern "C" int BattleHud_ClassifyHealthRatio(void*);
extern "C" int BattleMenu_HasTouchSelectionChanged(void*);
// Original: arm9/ov000 @ 0x02177D04; symbol: func_ov000_02177d04; size: 0x14C.
extern "C" void Text_AppendIndexedObjectNames(char* p,char* out) {
 void* state=_ZN9GameState11GetInstanceEv();
 unsigned count=*((unsigned char*)GameState_GetIndexList(state)+0xf7c);
 const char* sep=(const char*)ResourceStringTable_GetTextByKey(p+0xb8,0);
 int cursor=*(signed char*)(p+0x1d6b);
 if(BattleMenu_HasTouchSelectionChanged(p)) TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);
 TextMarkup_AppendCursorTag(out,cursor);
 for(unsigned char i=0;i<count;i++) {
 int index=*(signed char*)(p+0x70+i);
 void* rec=BattleMenu_FindPartyCommandRecord(p,index);
 if(rec) {
 char* obj=(char*)GameState_GetObjectWithFlag100(state,index);
 if(obj) {
 TextMarkup_AppendPaletteTagForType(out,BattleHud_ClassifyHealthRatio(rec));
 Text_AppendFormattedIntegerAndStringFragment(out,i,*(const char**)(obj+0x134));
 TextMarkup_AppendXPositionTag(out,0x46);
 TextMarkup_AppendPaletteTagForType(out,0);
 char* link=GameObject_GetLinkedActionDataWhenEnabled(obj);
 if(link) { char buf[256]; __clear(buf,256); Text_FormatAndConditionallyUppercaseOutput(*(char**)(link+4),buf,0); Text_AppendFormatString(out,buf); }
 if(i!=count-1) Text_AppendFormatString(out,sep);
 }
 }
 }
}
