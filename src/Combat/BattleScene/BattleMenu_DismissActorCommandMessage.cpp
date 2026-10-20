#include <globaldefs.h>
ARM
extern "C" {extern int KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage;extern int BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[];int Input_IsKeyMaskNewlyPressed(void*,unsigned);int Window_ClassifyTouchAgainstSelectedCanvas(void*);void BattleMenu_PopSelectionPanels(void*,int);void BattleMenu_ConfigureActorCommandSelection(void*,int,int);void BattleMenu_RefreshExistingPanel(int,void*,int,int,int,int);}
// Original: arm9/ov000 @ 0x0217BFBC; symbol: func_ov000_0217bfbc; size: 0xd8.
// Handles dismissal input, pops the current command panel and refreshes its actor selection.
extern "C" int BattleMenu_DismissActorCommandMessage(unsigned char* panel,int first,int second) {
 int dismiss=Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x601);
 dismiss|=Input_IsKeyMaskNewlyPressed(&KeyRepeaterUpdate_UnknownRoleZeroInitializedStorage,0x802);
 dismiss|=(Window_ClassifyTouchAgainstSelectedCanvas(*(void**)(panel+0x38))==2);
 if(dismiss) {
  panel[0x444]=0;
  BattleMenu_PopSelectionPanels(panel,0);
  (panel+((signed char*)panel)[0x18])[0x10]=0;
  ((signed char*)panel)[0x18]--;
  BattleMenu_ConfigureActorCommandSelection(panel,first,second);
  BattleMenu_RefreshExistingPanel(BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[2],panel,(((signed char*)panel)+((signed char*)panel)[0x18])[0x10],BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[1],BattleMenuHandleSkillListInput_UnknownRoleZeroInitializedStorage[0],0);
 }
 return -1;
}
