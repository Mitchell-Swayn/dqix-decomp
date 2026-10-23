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
// Original data: arm9/main @ 0x02114E54; shared input state.
extern char Main_UnknownRoleZeroInitializedStorage_Variant4[];
void BattleMenu_SynchronizeEnemyGroupAndMemberSelection(char*,int,int,char*);
int BattleMenu_UpdateMemberCommandState(char*);
void Ov000_ApplyIndexedSlotOrReset(char*);
void GameState_CollectPresentFourSlotPartyIndices(char*,char*,char*);
void FilterAndCompactSignedObjectIndices(char*,char*,signed char,int);
char* Window_FindActiveCanvasById(void*,unsigned char);
int BattleMenu_CountSpellChoices(char*);
int BattleMenu_CountAbilityChoices(char*);
int Grid_GetEntryCount(void*);
void DisplayRecord_SetActiveAndResetSelection(void*,int);
int UpdateMarginSelectionAndSkipEmptyRecords(char*);
}

// Original: arm9/ov000 @ 0x0217F00C; symbol: func_ov000_0217f00c; size: 0x2F8.
// Finds the selected member, updates command state, builds target lists and scrolling controls, and refreshes the active panel.
extern "C" void BattleMenu_UpdateSelectedPartyCommandWindows(char* self,int a,int b) {
    if(WORD(self,0x17c)<0) {
        if(Input_IsKeyMaskNewlyPressed(KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x802) || BYTE(Main_UnknownRoleZeroInitializedStorage_Variant4,0x55)) {
            GameState_ProcessEligibleListedMemberRecords(self);
            BattleMenu_ResetPanelsToFirstEligibleMember(self);
        }
        return;
    }
    char* records=self+0x958;
    for(int i=0;i<4;++i) {
        char* record=records+SBYTE(self+i,0x6c)*0x448;
        if(WORD(self,0x17c)!=WORD(record,0x4c))continue;
        char* canvas;
        int mode;
        int scrolling;
        BattleMenu_SynchronizeEnemyGroupAndMemberSelection(self,a,b,record);
        mode=BattleMenu_UpdateMemberCommandState(record);
        switch(mode) {
        case -3:
            GameState_ProcessEligibleListedMemberRecords(self);
            BattleMenu_ResetPanelsToFirstEligibleMember(self);
            break;
        case -2:
            Ov000_ApplyIndexedSlotOrReset(self);
            break;
        case 15:case 16:case 17:case 18: {
            scrolling=0;
            GameState_CollectPresentFourSlotPartyIndices(self,self+0x74,self+0x78);
            signed char count=SBYTE(self,0x78);
            PTR(record,0x30)=self+0x74;
            BYTE(record,0x34)=count;
            BYTE(record,0x441)=a;
            BattleMenu_OpenPanelForSelectionState(self,record,mode,a,b);
            canvas=Window_FindActiveCanvasById(PTR(record,0x38),(unsigned char)mode);
            if(mode==15) {
                if(BattleMenu_CountSpellChoices(record)>4)scrolling=1;
            } else if(mode==16) {
                if(BattleMenu_CountAbilityChoices(record)>4)scrolling=1;
            } else if(mode==17) {
                if(Grid_GetEntryCount(PTR(record,0x38)+0x54)>4)scrolling=1;
            }
            if(canvas)DisplayRecord_SetActiveAndResetSelection(canvas,scrolling);
            break;
        }
        case 19: {
            GameState_CollectPresentFourSlotPartyIndices(self,self+0x74,self+0x78);
            FilterAndCompactSignedObjectIndices(self+0x74,self+0x78,-1,1);
            signed char count=SBYTE(self,0x78);
            PTR(record,0x30)=self+0x74;
            BYTE(record,0x34)=count;
            BYTE(record,0x441)=a;
            BattleMenu_OpenPanelForSelectionState(self,record,mode,a,b);
            break;
        }
        case 20: {
            GameState_CollectPresentFourSlotPartyIndices(self,self+0x74,self+0x78);
            FilterAndCompactSignedObjectIndices(self+0x74,self+0x78,(signed char)WORD(record,0x4c),2);
            signed char count=SBYTE(self,0x78);
            PTR(record,0x30)=self+0x74;
            BYTE(record,0x34)=count;
            BYTE(record,0x441)=a;
            BattleMenu_OpenPanelForSelectionState(self,record,mode,a,b);
            break;
        }
        default:
            BattleMenu_OpenPanelForSelectionState(self,record,mode,a,b);
            break;
        }
        if(UpdateMarginSelectionAndSkipEmptyRecords(record))WORD(self,0x118)=1;
        BattleMenu_RefreshPanelForActiveMode(self,record,SBYTE(record+SBYTE(record,0x18),0x10),a,b);
        return;
    }
}
