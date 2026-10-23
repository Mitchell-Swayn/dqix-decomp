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
struct PartyFlagWord {unsigned low:30;unsigned flag:1;unsigned top:1;};
extern "C" {
void* GameState_GetIndexList(GameState*);
bool BattleMenu_HasTouchSelectionChanged(char*);
int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
int TextMarkup_AppendCursorTag(char*,int);
int BattleHud_ClassifyHealthRatio(void*);
int TextMarkup_AppendPaletteTagForType(char*,unsigned);
int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
int TextMarkup_AppendPaletteTag(char*,int);
int TextMarkup_AppendXPositionTag(char*,int);
void* ResourceStringTable_GetTextByKey(void*,void*);
int Text_AppendFormatString(char*,const char*);
}
// Original: arm9/ov000 @ 0x02178648; symbol: func_ov000_02178648; size: 0x170.
// Appends each present party member name and the label selected by stats bit 30.
extern "C" void BattleMenu_AppendPartyBattleOptionLabels(char* self,char* output) {
    if(!output) return;
    int cursor=SBYTE(self,0x1d6b);
    int line=0;
    GameState* game=GameState::GetInstance();
    GameState_GetIndexList(game);
    if(BattleMenu_HasTouchSelectionChanged(self)) TextMarkup_AppendFrameTag(output,cursor,8,5,5,5);
    TextMarkup_AppendCursorTag(output,cursor);
    unsigned count=BYTE(self,0x79);
    for(unsigned char i=0;i<count;++i) {
        char* record=self+0x958+SBYTE(self+i,0x70)*0x448;
        GameObject* object=game->GetPartyMemberByIndex((signed char)WORD(record,0x4c));
        if(object) {
            TextMarkup_AppendPaletteTagForType(output,BattleHud_ClassifyHealthRatio(record));
            Text_AppendFormattedIntegerAndStringFragment(output,line,(const char*)object->baseStats_);
            TextMarkup_AppendPaletteTag(output,15);
            TextMarkup_AppendXPositionTag(output,70);
            unsigned short bit=(unsigned short)((PartyFlagWord*)((char*)object->baseStats_+0x3c))->flag;
            short key=bit+0x7551;
            Text_AppendFormatString(output,(const char*)ResourceStringTable_GetTextByKey(self+0xb8,(void*)key));
            if(i!=count-1) Text_AppendFormatString(output,(const char*)ResourceStringTable_GetTextByKey(self+0xb8,0));
        }
        ++line;
    }
    TextMarkup_AppendXPositionTag(output,122);
}
