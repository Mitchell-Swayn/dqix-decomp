struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
extern "C" {WindowCanvasRecord* Window_GetSelectedTextCanvas(WindowCanvasOwner*);bool TextCanvas_IsReady(int);void Grid_SetLastTouchIndex(void*,int);int Window_UpdateCanvasesAndSelection(unsigned char*,unsigned);void EquipmentMenu_AdvanceActionChoice(unsigned char*);void EquipmentMenu_AdvanceEquipmentChangeAction(char*);void GameState_ResetModeAndSetResourceFlags(unsigned char*);void EquipmentMenu_AdvanceDiscardConfirmation(unsigned char*);void Grid_ResetSelectionAndActivateDisplay(unsigned char*);void EquipmentMenu_RefreshActionMenuHighlight(unsigned char*);}
// Original: arm9/ov005 @ 0x02158E04; symbol: func_ov005_02158e04; size: 0xCC.
// Validates selected text record, advances action-specific state and refreshes the menu footer.
extern "C" void EquipmentMenu_UpdateActionMenu(void* owner,unsigned value){
 unsigned saved=value;unsigned char* p=(unsigned char*)owner;
 unsigned char* record=(unsigned char*)(unsigned)Window_GetSelectedTextCanvas((WindowCanvasOwner*)((char*)p+0xee4));
 if(record && TextCanvas_IsReady((int)record) && !(record[0xc5]&2))Grid_SetLastTouchIndex((void*)((unsigned)(p+0xee4)+4),-1);
 p[0x3ddd]=Window_UpdateCanvasesAndSelection(p+0xee4,saved);
 switch(p[0x3ddf]){
  case 0:EquipmentMenu_AdvanceActionChoice(p);break;
  case 1:EquipmentMenu_AdvanceEquipmentChangeAction((char*)p);break;
  case 2:GameState_ResetModeAndSetResourceFlags(p);break;
  case 3:EquipmentMenu_AdvanceDiscardConfirmation(p);break;
  case 4:Grid_ResetSelectionAndActivateDisplay(p);break;
 }
 EquipmentMenu_RefreshActionMenuHighlight(p);
}
