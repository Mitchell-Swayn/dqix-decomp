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
int Selection_ReadEnabledIndexFromControl(void*);
bool BattleMenu_TestConfirmInputAfterDelay(unsigned char*,int);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
char* BattleMenu_FindPartyCommandRecord(char*,int);
char* GameObject_GetLinkedIndexedState(GameObject*);
void BattleMenu_RefreshUncontrolledMemberLabel(char*);
void Owner_ResetCacheAndLoadMatchingRecord(char*);
void GameState_ProcessEligibleListedMemberRecords(char*);
void BattleMenu_ResetPanelsToFirstEligibleMember(char*);
void Window_PopCanvasesAndResetSelection(void*,int);
void BattleMenu_ConfigureGlobalCommandSelection(char*,int,int);
int BattleMenu_TestCancelInput(void*);
void GameState_QueueIndexedObjectFieldSnapshot();
// Original data: arm9/main @ 0x02108760; sound state.
extern char Main_UnknownRoleZeroInitializedStorage[];
}

// Original: arm9/ov000 @ 0x0217D438; symbol: func_ov000_0217d438; size: 0x23C.
// Applies a tactics choice to the selected member or all eligible members, then restores command selection.
extern "C" void BattleMenu_HandleTacticsPolicyInput(char* self,int a,int b) {
    GameState* game;
    signed char member;
    char* record;
    UHALF(self,0x1d72)|=256;
    BYTE(self,0x1d6c)=Selection_ReadEnabledIndexFromControl(self+0x188);
    if(BattleMenu_TestConfirmInputAfterDelay((unsigned char*)self,0)) {
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
        game=GameState::GetInstance();
        UHALF(self,0x1d72)|=256;
        member=SBYTE(self+SBYTE(self,0x1d6b),0x1d74);
        int valid=(member>=0 && member<=3) ? 1 : 0;
        if(valid) {
            record=BattleMenu_FindPartyCommandRecord(self,member);
            if(record) {
                GameObject* object=game->GetPartyMemberByIndex(member);
                if(object) {
                    char* state=GameObject_GetLinkedIndexedState(object);
                    if((signed char)WORD(state,0x94c)!=SBYTE(self,0x1d6c)) {
                        WORD(state,0x94c)=SBYTE(self,0x1d6c);
                        BattleMenu_RefreshUncontrolledMemberLabel(record);
                        Owner_ResetCacheAndLoadMatchingRecord(self);
                    }
                }
            }
        } else {
            for(int i=0;i<4;++i) {
                record=self+0x958+i*0x448;
                GameObject* object=game->GetPartyMemberByIndex(WORD(record,0x4c));
                if(object && !(BYTE(record,0x24)&2) && (UHALF((char*)object,0)&0x1000)) {
                    char* state=GameObject_GetLinkedIndexedState(object);
                    if((signed char)WORD(state,0x94c)!=SBYTE(self,0x1d6c)) {
                        WORD(state,0x94c)=SBYTE(self,0x1d6c);
                        BattleMenu_RefreshUncontrolledMemberLabel(record);
                    }
                }
            }
            GameState_QueueIndexedObjectFieldSnapshot();
            GameState_ProcessEligibleListedMemberRecords(self);
            BattleMenu_ResetPanelsToFirstEligibleMember(self);
            return;
        }
        Window_PopCanvasesAndResetSelection(self+0x188,0);
        BYTE(self+SBYTE(self,0x1d68),0x1d60)=0;
        --SBYTE(self,0x1d68);
        BattleMenu_ConfigureGlobalCommandSelection(self,a,b);
        GameState_QueueIndexedObjectFieldSnapshot();
        return;
    }
    if(BattleMenu_TestCancelInput(self)) {
        Window_PopCanvasesAndResetSelection(self+0x188,0);
        BYTE(self+SBYTE(self,0x1d68),0x1d60)=0;
        --SBYTE(self,0x1d68);
        BattleMenu_ConfigureGlobalCommandSelection(self,a,b);
    }
}
