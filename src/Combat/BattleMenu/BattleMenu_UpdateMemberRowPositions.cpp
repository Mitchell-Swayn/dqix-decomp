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
extern "C" void BattleMenu_RefreshPartySlotMappings(char*);
extern "C" void* Network_GetConnectionManager();
// Original: arm9/ov000 @ 0x02174B14; symbol: func_ov000_02174b14; size: 0x100.
// Refreshes slot mappings and stacks valid party rows, reserving extra height for expanded rows.
extern "C" void BattleMenu_UpdateMemberRowPositions(char* self) {
    BattleMenu_RefreshPartySlotMappings(self);
    GameState::GetInstance();
    Network_GetConnectionManager();
    bool expanded=false;
    for(int i=0;i<4;++i) {
        char* record=self+0x958+SBYTE(self+i,0x6c)*0x448;
        if(WORD(record,0x4c)>=0) expanded |= (BYTE(record,0x24)&4)!=0;
    }
    int y=0;
    if(!expanded) y=32;
    char* record;
    for(int i=0;i<4;++i) {
        record=self+0x958+SBYTE(self+i,0x6c)*0x448;
        int valid=WORD(record,0x4c)>=0 && WORD(record,0x4c)<=3;
        if(valid) {
            WORD(record,0x44)=0;
            WORD(record,0x48)=y;
            if(BYTE(record,0x24)&4) y+=72;
            else y+=40;
        }
    }
}
