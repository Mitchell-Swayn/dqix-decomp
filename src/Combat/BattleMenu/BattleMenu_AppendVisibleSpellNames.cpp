#include <globaldefs.h>
ARM
#pragma force_active on
#define WORD(p,o) (*(int*)((p)+(o)))
#define HALF(p,o) (*(short*)((p)+(o)))
#define UHALF(p,o) (*(unsigned short*)((p)+(o)))
#define BYTE(p,o) (*(unsigned char*)((p)+(o)))
#define SBYTE(p,o) (*(signed char*)((p)+(o)))
#define PTR(p,o) (*(char**)((p)+(o)))
extern "C" {
void Selection_ComputeBoundedPageEntryRange(const int*,int*,int*);
bool BattleMenu_HasTouchSelectionChanged(char*);
int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
int TextMarkup_AppendCursorTag(char*,int);
unsigned BattleMenu_GetSpellChoice(unsigned char*,int);
int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
void* ResourceStringTable_GetTextByKey(void*,void*);
int Text_AppendFormatString(char*,const char*);
}
// Original: arm9/ov000 @ 0x02178F28; symbol: func_ov000_02178f28; size: 0xF0.
// Formats the bounded signed-byte spell-choice page with cursor markup and resource separators.
extern "C" void BattleMenu_AppendVisibleSpellNames(char* self,char* actor,char* output) {
    if(!actor || !output) return;
    int begin,end;
    Selection_ComputeBoundedPageEntryRange((int*)(self+0x1dc),&begin,&end);
    signed char first=begin, limit=end;
    int selected=SBYTE(actor,0x20);
    if(BattleMenu_HasTouchSelectionChanged(self)) TextMarkup_AppendFrameTag(output,selected-first,8,5,5,5);
    TextMarkup_AppendCursorTag(output,selected-first);
    for(signed char i=first;i<limit;++i) {
        char* choice=(char*)BattleMenu_GetSpellChoice((unsigned char*)actor,i);
        if(choice) {
            Text_AppendFormattedIntegerAndStringFragment(output,i-first,*(const char**)choice);
            if(i!=limit-1) Text_AppendFormatString(output,(const char*)ResourceStringTable_GetTextByKey(self+0xb8,0));
        }
    }
}
