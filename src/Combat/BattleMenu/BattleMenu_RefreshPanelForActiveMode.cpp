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
void BattleMenu_RefreshPartyCommandPanelText(char*);
void Resource_RebuildOwnerBufferAndRefreshReadyRecord(char*);
void Owner_ResetCacheAndLoadMatchingRecord(char*);
void BattleMenu_RefreshTacticsPanelText(char*);
void GameState_BuildIndexedNameBufferAndLoadRecord(char*);
void BattleMenu_RefreshAvailableCategoryPanelText(char*);
void BattleMenu_RefreshEquipmentChoicePanelText(char*);
void RebuildPartySelectionTextForOwner(char*);
int BattleMenu_HasTouchSelectionChanged(char*);
void Graphics_RebuildOwnerTextRecords(char*,int);
void BattleMenu_RefreshEnemyGroupTargetWindow(char*,char*,int);
void Object_BuildAlternateSelectionBufferAndLoadOwnerRecord(char*,int,int);
void BattleMenu_RefreshSkillListWindow(char*,int,int);
void Ov000_BuildIndexedDescription(char*,int,int);
void BattleMenu_RefreshAllyTargetWindow(char*,char*,int);
void BattleMenu_RefreshVocationActionWindow(char*,char*);
void BattleMenu_RefreshSharedPartyActionWindow(char*,char*);
void BattleMenu_RefreshSharedActionEnemyGroupWindow(char*,char*,int);
}
// Original: arm9/ov000 @ 0x02177038; symbol: func_ov000_02177038; size: 0x14C.
// Dispatches panel text refresh by mode when the refresh flag is set.
extern "C" void BattleMenu_RefreshPanelForActiveMode(char* self,char* actor,unsigned mode,int option,int count) {
    if(!WORD(self,0x118)) return;
    switch(mode) {
    case 1:BattleMenu_RefreshPartyCommandPanelText(self);break;
    case 2:Resource_RebuildOwnerBufferAndRefreshReadyRecord(self);break;
    case 3:Owner_ResetCacheAndLoadMatchingRecord(self);break;
    case 4:BattleMenu_RefreshTacticsPanelText(self);break;
    case 5:GameState_BuildIndexedNameBufferAndLoadRecord(self);break;
    case 6:BattleMenu_RefreshAvailableCategoryPanelText(self);break;
    case 7:BattleMenu_RefreshEquipmentChoicePanelText(self);break;
    case 8:RebuildPartySelectionTextForOwner(self);break;
    case 13:if(actor)Graphics_RebuildOwnerTextRecords(actor,BattleMenu_HasTouchSelectionChanged(self));break;
    case 14:BattleMenu_RefreshEnemyGroupTargetWindow(self,actor,count);break;
    case 15:Object_BuildAlternateSelectionBufferAndLoadOwnerRecord(self,option,count);break;
    case 16:BattleMenu_RefreshSkillListWindow(self,option,count);break;
    case 17:Ov000_BuildIndexedDescription(self,option,count);break;
    case 18:case 19:case 20:BattleMenu_RefreshAllyTargetWindow(self,actor,option);break;
    case 21:BattleMenu_RefreshVocationActionWindow(self,actor);break;
    case 23:BattleMenu_RefreshSharedPartyActionWindow(self,actor);break;
    case 25:BattleMenu_RefreshSharedActionEnemyGroupWindow(self,actor,count);break;
    }
}
