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
// Original data: arm9/ov000 @ 0x02184294; shared command-menu references.
extern unsigned BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x02114E30; key input state.
extern char KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x02108760; sound state.
extern char Main_UnknownRoleZeroInitializedStorage[];
int Selection_ReadEnabledIndexFromControl(void*);
void Window_SetCanvasEnabled(void*,int,int);
int Input_IsKeyMaskNewlyPressed(void*,int);
int TestSelectedRecordReadyAndByteFlagBitOne(char*,int);
void SoundSfx_StartCurrentSequenceArchiveEntry(char*,int,void*);
int System_TestNewInputMaskOrStateModeTwo(char*);
void BattleMenu_PopSelectionPanels(char*);
void BattleMenu_ConfigureActorCommandSelection(char*,int,int);
void BattleMenu_ConfigureGlobalCommandSelection(char*,int,int);
void BattleMenu_RefreshExistingPanel(char*,char*,int,int,int,unsigned char);
void BattleMenu_RefreshPanelForActiveMode(char*,char*,int,int,int);
char* BattleMenu_FindPartyCommandRecord(char*,int);
char* GameState_GetIndexList(GameState*);
int GameState_ReadProtagonistObjectIndex(GameState*);
bool BattleMenu_TestConfirmInputAfterDelay(unsigned char*,int);
int BattleMenu_TestCancelInput(void*);
void Window_PopCanvasesAndResetSelection(void*,int);
char* BattleMenu_GetSelectedPartyCommandRecord(char*);
void BattleMenu_OpenPanelForSelectionState(char*,char*,int,int,int);
void GameState_ProcessEligibleListedMemberRecords(char*);
void BattleMenu_ResetPanelsToFirstEligibleMember(char*);
}
extern "C" {
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
int GameObject_IsDead(GameObject*);
char* BattleMenu_FindActionDefinition(char*,int);
int BattleMenu_HandleSpellListInput(char*,int,int);
int BattleMenu_HandleSkillListInput(char*,int,int);
int BattleMenu_HandleCarriedItemListInput(char*,int,int);
}
struct ActionIdWord {unsigned id:12;unsigned other:20;};
struct ActionTargetWord {unsigned low:5;unsigned kind:7;unsigned high:20;};

// Original: arm9/ov000 @ 0x0217BB2C; symbol: func_ov000_0217bb2c; size: 0x2C8.
// Restores action-list input when its context changes, validates ally targets, and handles confirmation or cancellation.
extern "C" int BattleMenu_HandleAllyTargetInput(char* self,int a,int b) {
    UHALF((char*)BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[2],0x1d72)|=256;
    BYTE(self,0x21)=Selection_ReadEnabledIndexFromControl(PTR(self,0x38));
    SBYTE(self,0x2e)=-1;
    if(SBYTE(self,0x441)!=a) {
        BYTE(self,0x441)=a;
        BYTE(self,0x442)=SBYTE(PTR(self,0x30),SBYTE(self,0x21));
        BYTE(self,0x444)=1;
        BattleMenu_PopSelectionPanels(self);
        BYTE(self+SBYTE(self,0x18),0x10)=0;
        --SBYTE(self,0x18);
        SBYTE(self,0x21)=-1;
        SBYTE(self,0x2e)=-1;
        BattleMenu_ConfigureActorCommandSelection(self,a,b);
        int result=-1;
        switch(SBYTE(self+SBYTE(self,0x18),0x10)) {
        case 15: result=BattleMenu_HandleSpellListInput(self,BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[1],BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[0]);break;
        case 16: result=BattleMenu_HandleSkillListInput(self,BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[1],BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[0]);break;
        case 17: result=BattleMenu_HandleCarriedItemListInput(self,BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[1],BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[0]);break;
        }
        return result;
    }
    int pressed=Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x601);
    bool confirm=(pressed|TestSelectedRecordReadyAndByteFlagBitOne(PTR(self,0x38),20))!=0;
    if(confirm) {
        GameObject* object=GameState_GetObjectWithFlag100(GameState::GetInstance(),SBYTE(PTR(self,0x30),SBYTE(self,0x21)));
        if(!object)return -1;
        int eligible=!GameObject_IsDead(object);
        char* action=BattleMenu_FindActionDefinition(self,UHALF(self,0x26));
        if(action) {
            if(((ActionTargetWord*)(action+0x18))->kind==18)eligible=GameObject_IsDead(object);
            unsigned id=((ActionIdWord*)(action+4))->id;
            if(id==38 || id==39 || id==84)eligible=1;
        } else eligible=1;
        if(eligible) {
            BYTE(self,0x43d)=SBYTE(self+SBYTE(self,0x18),0x10);
            BYTE(self,0x2e)=SBYTE(PTR(self,0x30),SBYTE(self,0x21));
            SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
            ++SBYTE(self,0x18);
            BYTE(self+SBYTE(self,0x18),0x10)=100;
        }
    } else if(System_TestNewInputMaskOrStateModeTwo(self)) {
        BattleMenu_PopSelectionPanels(self);
        BYTE(self+SBYTE(self,0x18),0x10)=0;
        --SBYTE(self,0x18);
        SBYTE(self,0x21)=-1;
        SBYTE(self,0x2e)=-1;
        BattleMenu_ConfigureActorCommandSelection(self,a,b);
        unsigned* refs=BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage;
        BattleMenu_RefreshExistingPanel((char*)refs[2],self,SBYTE(self+SBYTE(self,0x18),0x10),refs[1],refs[0],0);
    }
    return -1;
}
