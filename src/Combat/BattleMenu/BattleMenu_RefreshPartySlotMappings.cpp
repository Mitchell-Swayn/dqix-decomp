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
struct PartySlotView {char unknown[0x70];signed char slots[4];};
extern "C" {
int GameState_CopyActivePartySlotList(GameState*,unsigned char*);
int GameState_CopyProtagonistPartySlotList(GameState*,unsigned char*);
void __clear(void*,unsigned);
char* BattleMenu_FindPartyCommandRecord(char*,int);
int BattleMenu_IsPartyPanelEnabled(char*);
}
// Original: arm9/ov000 @ 0x0217228C; symbol: func_ov000_0217228c; size: 0x11C.
// Completes the active-slot permutation, copies party slots, and counts enabled party panels.
extern "C" void BattleMenu_RefreshPartySlotMappings(char* self) {
    GameState* game=GameState::GetInstance();
    unsigned char active[4], used[4], party[4];
    int count=GameState_CopyActivePartySlotList(game,active);
    __clear(used,4);
    for(int i=0;i<count;++i) {BYTE(self+i,0x6c)=active[i];used[active[i]]=1;}
    for(;count<4;++count) {
        for(int i=0;i<4;++i) {if(!used[i]) {BYTE(self+count,0x6c)=i;used[i]=1;break;}}
    }
    PartySlotView* view=(PartySlotView*)self;
    unsigned char total=0;
    int size=GameState_CopyProtagonistPartySlotList(game,party);
    int i=total;
    for(;i<4;++i) {
        view->slots[i]=-1;
        if(i<size) view->slots[i]=party[i];
        char* record=BattleMenu_FindPartyCommandRecord(self,view->slots[i]);
        if(record && BattleMenu_IsPartyPanelEnabled(record)) total=(unsigned char)(total+1);
    }
    BYTE(self,0x79)=total;
}
