#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_repositioncode off
#pragma force_active on
#define WORD(p,o) (*(int*)((p)+(o)))
#define HALF(p,o) (*(short*)((p)+(o)))
#define UHALF(p,o) (*(unsigned short*)((p)+(o)))
#define BYTE(p,o) (*(unsigned char*)((p)+(o)))
#define SBYTE(p,o) (*(signed char*)((p)+(o)))
#define PTR(p,o) (*(char**)((p)+(o)))
#include <GameState/GameState.h>
extern "C" {
bool BattleMenu_HasTouchSelectionChanged(char*);
int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);
int TextMarkup_AppendCursorTag(char*,int);
void* Network_GetConnectionManager();
bool Network_IsSessionActive(int*);
int GameState_ReadProtagonistObjectIndex(GameState*);
void* ResourceStringTable_GetTextByKey(void*,void*);
int Text_AppendFormattedIntegerAndStringFragment(char*,int,const char*);
int Text_AppendFormatString(char*,const char*);
// Original data: arm9/ov000 @ 0x021834bc; signed halfword resource keys.
extern short BattleMenuAppendSessionOptions_UnknownRoleInitializedBytes[];
}
// Original: arm9/ov000 @ 0x021775A4; symbol: func_ov000_021775a4; size: 0xE8.
// Formats three resource-key options, adding a fourth for the network protagonist at index zero.
extern "C" void BattleMenu_AppendSessionOptions(char* self,char* output) {
    if(!output) return;
    int cursor=SBYTE(self,0x1d6a);
    int line=0;
    if(BattleMenu_HasTouchSelectionChanged(self)) TextMarkup_AppendFrameTag(output,cursor,8,5,5,5);
    TextMarkup_AppendCursorTag(output,cursor);
    int* network=(int*)Network_GetConnectionManager();
    int count=3;
    if(Network_IsSessionActive(network)) {
        if(GameState_ReadProtagonistObjectIndex(GameState::GetInstance())==0) count=4;
    }
    for(int i=0;i<count;++i) {
        const char* text=(const char*)ResourceStringTable_GetTextByKey(self+0xb8,(void*)BattleMenuAppendSessionOptions_UnknownRoleInitializedBytes[i]);
        Text_AppendFormattedIntegerAndStringFragment(output,line,text);
        if(i!=count-1) Text_AppendFormatString(output,(const char*)ResourceStringTable_GetTextByKey(self+0xb8,0));
        ++line;
    }
}
