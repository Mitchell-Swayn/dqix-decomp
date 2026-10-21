#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct Obj;
struct A;
extern "C" {
void UpdateFourRectangleCorners(char* p, int mode, unsigned short value);
void Graphics_AdjustTwoRecordPositionsForPendingFlags(unsigned char* self);
void EquipmentMenu_DrawCategoryTabHighlight(char* self);
void GameState_TriggerModeThreeResourceUpdate(unsigned char* state);
void EquipmentMenu_DrawSharedMenuButton(char* self);
void DrawCurrentAndTotalPhaseNumbers(unsigned char* p);
void EquipmentMenu_DrawInventoryQuantities(unsigned char* p);
void Window_ClearResourceBuffers(unsigned char* p);
void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void* object);
void Graphics_ResetCountedThirtyTwoByteTransfers(unsigned char* state);
void EquipmentMenu_DrawItemDisplays(unsigned char* p);
unsigned int Window_IsVisible(A** p);
void Window_UpdateEnabledEntryAndRoot(Obj* p, void* q);
void EquipmentMenu_PositionActionCursor(char* self);
void EquipmentMenu_DrawEquipmentSlotList(unsigned char* p);
void EquipmentMenu_DrawEquippedItemNames(unsigned char* p);
}
#define B(o) (*(unsigned char*)(p+(o)))
#define S(o) (*(signed char*)(p+(o)))
#define W(o) (*(unsigned*)(p+(o)))
// Original: arm9/ov005 @ 0x02154EF0; symbol: func_ov005_02154ef0; size: 0x218.
// Advances header/page blink timers and dispatches menu row, text and selection rendering.
extern "C" void EquipmentMenu_DrawController(unsigned char* p){
 if(B(0x3db8)==1)return;
 if(B(0x3db8)!=0){
  if(B(0x3db8)==3){
   unsigned ticks=GameState::GetInstance()->GetTickCount();if(!ticks)ticks=1;
   if(S(0x3df0)>0){S(0x3df1)-=ticks;if(S(0x3df1)<=0){if(!(W(0x3dcc)&0x1000)){W(0x3dcc)|=0x1000;S(0x3df1)+=30;}else{W(0x3dcc)&=~0x1000;S(0x3df1)+=30;S(0x3df0)--;}}}
   S(0x3df2)-=ticks;if(S(0x3df2)<=0){if(!(W(0x3dcc)&0x2000)){W(0x3dcc)|=0x2000;S(0x3df2)+=30;}else{W(0x3dcc)&=~0x2000;S(0x3df2)+=30;}}
  }
  if(!(W(0x3dcc)&0x1000))UpdateFourRectangleCorners((char*)p+0x1a34,0,0x7fff);
  if(!(W(0x3dcc)&0x2000))GameState_TriggerModeThreeResourceUpdate(p);
  EquipmentMenu_DrawCategoryTabHighlight((char*)p);Graphics_AdjustTwoRecordPositionsForPendingFlags(p);EquipmentMenu_DrawSharedMenuButton((char*)p);DrawCurrentAndTotalPhaseNumbers(p);EquipmentMenu_DrawInventoryQuantities(p);
  Window_ClearResourceBuffers(p+0xee4);ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(p+0xee4);Graphics_ResetCountedThirtyTwoByteTransfers(p+0xee4);
 }
 EquipmentMenu_DrawItemDisplays(p);
 if(W(0xe64) && Window_IsVisible((A**)W(0xe64)))Window_UpdateEnabledEntryAndRoot((Obj*)W(0xe64),(void*)W(0xe68));
 EquipmentMenu_PositionActionCursor((char*)p);EquipmentMenu_DrawEquipmentSlotList(p);
 if(!(W(0x3dcc)&0x200) && S(0x3e04)<=0){EquipmentMenu_DrawEquippedItemNames(p);return;}
 S(0x3e04)--;
}
