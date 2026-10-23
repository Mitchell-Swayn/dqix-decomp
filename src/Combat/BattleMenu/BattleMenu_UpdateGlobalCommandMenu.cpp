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
extern "C" {
void BattleMenu_HandleRootCommandInput(char*,int,int);
void BattleMenu_HandlePartyOptionsInput(char*,int,int);
void BattleMenu_HandleTacticsMemberInput(char*,int,int);
void BattleMenu_HandleTacticsPolicyInput(char*,int,int);
void BattleMenu_HandleEquipmentMemberInput(char*,int,int);
void BattleMenu_HandleEquipmentCategoryInput(char*,int,int);
void BattleMenu_HandleEquipmentItemInput(char*,int,int);
void BattleMenu_TogglePartyMemberBattleOption(char*,int,int);
void BattleMenu_FinishPartyTransitionDialogue(char*,int,int);
void BattleMenu_UpdateEnemyStatusMessage(char*,int,int);
void BattleMenu_ResetCommandsOnReviewCancel(char*,int,int);
void BattleMenu_HandleSharedPartyActionInput(char*,int,int);
void BattleMenu_HandleSharedActionEnemyTargetInput(char*,int,int);
int BattleMenu_CountLivingEnabledCommandParticipants(char*);
void Window_PopCanvasesAndResetSelection(void*,int);
void BattleMenu_DismissGlobalCommandMessage(char*,int,int);
int BattleMenu_AdvanceActionListPage(char*);
void BattleMenu_RefreshPanelForActiveMode(char*,char*,int,int,int);
}

// Original: arm9/ov000 @ 0x0217C908; symbol: func_ov000_0217c908; size: 0x254.
// Dispatches the active global command menu input, advances list pages, and refreshes its text.
extern "C" void BattleMenu_UpdateGlobalCommandMenu(char* self,int a,int b) {
    if(!BattleMenu_CountLivingEnabledCommandParticipants(self)) {
        Window_PopCanvasesAndResetSelection(self+0x188,1);
        return;
    }
    switch(SBYTE(self+SBYTE(self,0x1d68),0x1d60)) {
    case 1: BattleMenu_HandleRootCommandInput(self,a,b);break;
    case 2: BattleMenu_HandlePartyOptionsInput(self,a,b);break;
    case 3: BattleMenu_HandleTacticsMemberInput(self,a,b);break;
    case 4: BattleMenu_HandleTacticsPolicyInput(self,a,b);break;
    case 5: BattleMenu_HandleEquipmentMemberInput(self,a,b);break;
    case 6: BattleMenu_HandleEquipmentCategoryInput(self,a,b);break;
    case 7: BattleMenu_HandleEquipmentItemInput(self,a,b);break;
    case 8: BattleMenu_TogglePartyMemberBattleOption(self,a,b);break;
    case 9: BattleMenu_FinishPartyTransitionDialogue(self,a,b);break;
    case 10: BattleMenu_UpdateEnemyStatusMessage(self,a,b);break;
    case 11: BattleMenu_ResetCommandsOnReviewCancel(self,a,b);break;
    case 23: BattleMenu_HandleSharedPartyActionInput(self,a,b);break;
    case 25: BattleMenu_HandleSharedActionEnemyTargetInput(self,a,b);break;
    case 12:case 32:case 41:case 42:case 43:BattleMenu_DismissGlobalCommandMessage(self,a,b);break;
    }
    if(BattleMenu_AdvanceActionListPage(self))WORD(self,0x118)=1;
    BattleMenu_RefreshPanelForActiveMode(self,0,SBYTE(self+SBYTE(self,0x1d68),0x1d60),a,b);
}
