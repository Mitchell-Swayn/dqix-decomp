#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
extern "C" {int BattleMenu_HasTouchSelectionChanged(void*);int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);int TextMarkup_AppendCursorTag(char*,int);void* ResourceStringTable_GetTextByKey(void*,void*);int Text_AppendFormatString(char*,const char*);int BattleHud_ClassifyHealthRatio(void*);int TextMarkup_AppendPaletteTagForType(char*,unsigned);void __clear(void*,unsigned);void TextSprite_DecodeCachedText(unsigned char*,unsigned);int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);}
// Original: arm9/ov000 @ 0x02179A70; symbol: Text_AppendVisibleRatioClassifiedEntryList; size: 0x100.
// Formats cursor and visible entry names with ratio-class markup and separators.
extern "C" void BattleMenu_AppendAllyTargetNames(unsigned char* self,signed char* record,int unused,char* output){if(!record)return;int cursor=record[0x21];int count=0;if(BattleMenu_HasTouchSelectionChanged(self))TextMarkup_AppendFrameTag(output,cursor,8,5,5,5);TextMarkup_AppendCursorTag(output,cursor);unsigned char* entry;for(int i=0;i<((signed char*)self)[0x78];++i){entry=self+0x958+((signed char*)(self+i))[0x74]*0x448;if(W(entry,0x4c)<0)continue;if(count)Text_AppendFormatString(output,(char*)ResourceStringTable_GetTextByKey(self+0xb8,0));TextMarkup_AppendPaletteTagForType(output,BattleHud_ClassifyHealthRatio(entry));char text[128];__clear(text,128);TextSprite_DecodeCachedText(entry+0x68,(unsigned)text);Text_AppendFormattedIntegerAndStringFragment(output,count,text);++count;}}
