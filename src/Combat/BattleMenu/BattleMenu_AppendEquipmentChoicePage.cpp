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
#include <GameState/GameState.h>
extern "C" {
void Selection_ComputeBoundedPageEntryRange(void*,int*,int*);
const char* ResourceStringTable_GetTextByKey(void*,int);
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
char* GameObject_GetLinkedActionDataWhenEnabled(GameObject*);
int BattleMenu_HasTouchSelectionChanged(void*);
int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
int TextMarkup_AppendCursorTag(char*,int);
void __clear(void*,unsigned);
char* ZoneState2754_FindPrimaryRecordByKey(void*,int);
void Text_FormatAndConditionallyUppercaseOutput(const char*,char*,int);
int Text_AppendFormatString(char*,const char*);
int TextMarkup_AppendWidthTag(char*,int);
int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
}

// Original: arm9/ov000 @ 0x0217831C; symbol: func_ov000_0217831c; size: 0x1B8.
// Appends the current equipment-choice page and marks the equipped action with its label and palette.
extern "C" void BattleMenu_AppendEquipmentChoicePage(char* self,char* out) {
    int first,last;
    Selection_ComputeBoundedPageEntryRange(self+0x1dc,&first,&last);
    signed char begin=first,end=last;
    const char* separator=ResourceStringTable_GetTextByKey(self+0xb8,0);
    int selected=SBYTE(self,0x1d6f);
    const char* empty=ResourceStringTable_GetTextByKey(self+0xb8,5);
    int line=0;
    int equipped=-1;
    int member=SBYTE(self+SBYTE(self,0x1d6b),0x70);
    GameState* game=GameState::GetInstance();
    GameObject* object=GameState_GetObjectWithFlag100(game,member);
    char* action=GameObject_GetLinkedActionDataWhenEnabled(object);
    if(action)equipped=HALF(action,0x18);
    if(BattleMenu_HasTouchSelectionChanged(self))TextMarkup_AppendFrameTag(out,selected-begin,8,5,5,5);
    TextMarkup_AppendCursorTag(out,selected-begin);
    selected=end-1;
    for(;begin<end;++begin) {
        char text[64],formatted[256];
        __clear(text,64);
        int id=HALF(self+begin*2,0x26);
        char* record=ZoneState2754_FindPrimaryRecordByKey(self+0x100,id);
        const char* name=empty;
        if(record) {
            __clear(formatted,256);
            Text_FormatAndConditionallyUppercaseOutput(PTR(record,4),formatted,0);
            name=formatted;
        }
        if(equipped==id) {
            Text_AppendFormatString(text,ResourceStringTable_GetTextByKey(self+0xb8,19));
            TextMarkup_AppendWidthTag(text,3);
        } else TextMarkup_AppendWidthTag(text,8);
        Text_AppendFormatString(text,name);
        Text_AppendFormattedIntegerAndStringFragment(out,line,text);
        if(begin!=selected)Text_AppendFormatString(out,separator);
        ++line;
    }
}
