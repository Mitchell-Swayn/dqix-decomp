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
void* Zone3D_GetMainInstance();
void Memory_CopyConstantBlock16(char*,int*);
int BattleMenu_SelectFirstEligiblePartyInCommandOrder(char*);
void Combat_InitializeTextForActiveIndexedRecords(char*);
}

// Original: arm9/ov000 @ 0x0217CB5C; symbol: func_ov000_0217cb5c; size: 0x2C8.
// Maps the selected root command to party actions, tactics, shared options, or active-record text setup.
extern "C" void BattleMenu_HandleRootCommandInput(char* self,int a,int b) {
    Zone3D_GetMainInstance();
    UHALF(self,0x1d72)|=256;
    int selected=Selection_ReadEnabledIndexFromControl(self+0x188);
    if(selected<0)selected=0;
    BYTE(self,0x1d69)=selected;
    if(BattleMenu_TestConfirmInputAfterDelay((unsigned char*)self,0)) {
        SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage,1,0);
        int commands[4];
        Memory_CopyConstantBlock16(self,commands);
        switch(commands[SBYTE(self,0x1d69)]) {
        case 0:
            BattleMenu_RefreshPanelForActiveMode(self,0,SBYTE(self+SBYTE(self,0x1d68),0x1d60),a,b);
            ++SBYTE(self,0x1d68);
            BYTE(self+SBYTE(self,0x1d68),0x1d60)=13;
            Window_PopCanvasesAndResetSelection(self+0x188,1);
            UHALF(self,0x1d72)|=4;
            if(!BattleMenu_SelectFirstEligiblePartyInCommandOrder(self)) {
                UHALF(self,0x1d72)&=~4;
                WORD(self,0x17c)=-1;
                unsigned char count=BYTE(GameState_GetIndexList(GameState::GetInstance()),0xf7c);
                for(unsigned char i=0;i<count;++i) {
                    char* record=BattleMenu_FindPartyCommandRecord(self,SBYTE(self+i,0x70));
                    if(record)BYTE(record+SBYTE(record,0x18),0x10)=100;
                }
            }
            break;
        case 1:
            BattleMenu_RefreshPanelForActiveMode(self,0,SBYTE(self+SBYTE(self,0x1d68),0x1d60),a,b);
            BYTE(self,0x1d6a)=0;
            ++SBYTE(self,0x1d68);
            BYTE(self+SBYTE(self,0x1d68),0x1d60)=2;
            BattleMenu_OpenPanelForSelectionState(self,BattleMenu_GetSelectedPartyCommandRecord(self),2,a,b);
            break;
        case 2:
            UHALF(self,0x1d72)&=~256;
            BattleMenu_RefreshExistingPanel(self,0,SBYTE(self+SBYTE(self,0x1d68),0x1d60),a,b,1);
            BYTE(self,0x1d70)=0;
            ++SBYTE(self,0x1d68);
            BYTE(self+SBYTE(self,0x1d68),0x1d60)=10;
            break;
        case 3:
            BattleMenu_RefreshPanelForActiveMode(self,0,SBYTE(self+SBYTE(self,0x1d68),0x1d60),a,b);
            ++SBYTE(self,0x1d68);
            BYTE(self+SBYTE(self,0x1d68),0x1d60)=11;
            Window_PopCanvasesAndResetSelection(self+0x188,1);
            Combat_InitializeTextForActiveIndexedRecords(self);
            break;
        }
    }
}
