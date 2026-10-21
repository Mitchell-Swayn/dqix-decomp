#include <globaldefs.h>
ARM
struct State;
struct Entry;
extern "C" {
int Selection_ReadEnabledIndexFromControl(void *p);
bool BattleMenu_TestConfirmInputAfterDelay(unsigned char *p, int delay);
void SoundSfx_StartCurrentSequenceArchiveEntry(char* p, int a, void* b);
unsigned GameState_ComputeTwelveBitObjectAttributeMask(unsigned id);
unsigned GameState_AddLinkedObjectCategoryBit(int id, unsigned mask);
char* BattleMenu_FindPartyCommandRecord(char* p, int id);
void BattleMenu_OpenPanelForSelectionState(void*, void*, int, int, int);
void BattleMenu_RefreshSelectedPartyPanelExpansion(unsigned char* self);
Entry* BattleMenu_GetSelectedPartyCommandRecord(char* obj);
unsigned int GameState_CountSetBitsInWord68(void *object);
void Window_SetCanvasActiveWhileProgressIncomplete(int id, int stopIndex, int progress, void *owner);
void Window_SetCanvasEnabled(unsigned char* p, int enabled, int key);
int BattleMenu_TestCancelInput(void *owner);
void Window_PopCanvasesAndResetSelection(State* p, int flag);
void BattleMenu_ConfigureGlobalCommandSelection(char* self, int value, int option);
extern char Main_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov000 @ 0x0217D674; symbol: func_ov000_0217d674; size: 0x208.
// Confirms or cancels equipment-member targeting, opens the next selection panel, and updates canvas enablement.
extern "C" void BattleMenu_HandleEquipmentMemberInput(char* self, int a, int b) {
 *(unsigned short*)(self + 0x1d72) |= 0x100;
 self[0x1d6b] = Selection_ReadEnabledIndexFromControl(self + 0x188);
 if (BattleMenu_TestConfirmInputAfterDelay((unsigned char*)self, 0)) {
  SoundSfx_StartCurrentSequenceArchiveEntry(Main_UnknownRoleZeroInitializedStorage, 1, 0);
  int member = *(signed char*)(self + *(signed char*)(self + 0x1d6b) + 0x70);
  self[0x1d6e] = 0;
  if (!(*(unsigned*)(self + 0x68) = GameState_AddLinkedObjectCategoryBit(
   member,
   *(unsigned*)(self + 0x68) = GameState_ComputeTwelveBitObjectAttributeMask(member)))) {
   *(signed char*)(self + 0x1d68) = (signed char)(*(signed char*)(self + 0x1d68) + 1);
   char* slot = self + *(signed char*)(self + 0x1d68);
   (slot + 0x1000)[0xd60] = 0x2b;
   char* record = BattleMenu_FindPartyCommandRecord(self, *(int*)(self + 0x17c));
   BattleMenu_OpenPanelForSelectionState(self, record, 0x2b, a, b);
   return;
  }
  *(int*)(self + 0x17c) = member;
  char* record = BattleMenu_FindPartyCommandRecord(self, member);
  if (!record) return;
  char* marked = record + *(signed char*)(record + 0x18);
  marked[0x10] = 1;
  BattleMenu_RefreshSelectedPartyPanelExpansion((unsigned char*)self);
  *(signed char*)(self + 0x1d68) = (signed char)(*(signed char*)(self + 0x1d68) + 1);
  char* slot = self + *(signed char*)(self + 0x1d68);
  (slot + 0x1000)[0xd60] = 6;
  Entry* entry = BattleMenu_GetSelectedPartyCommandRecord(self);
  BattleMenu_OpenPanelForSelectionState(self, entry, 6, a, b);
  unsigned int bits = GameState_CountSetBitsInWord68(self);
  Window_SetCanvasActiveWhileProgressIncomplete(6, bits, 4, self + 0x188);
  Window_SetCanvasEnabled((unsigned char*)(self + 0x188), 0, 1);
  Window_SetCanvasEnabled((unsigned char*)(self + 0x188), 0, 2);
  Window_SetCanvasEnabled((unsigned char*)(self + 0x188), 0, 5);
  return;
 }
 if (!BattleMenu_TestCancelInput(self)) return;
 Window_PopCanvasesAndResetSelection((State*)(self + 0x188), 0);
 char* slot = self + *(signed char*)(self + 0x1d68);
 (slot + 0x1000)[0xd60] = 0;
 *(signed char*)(self + 0x1d68) = (signed char)(*(signed char*)(self + 0x1d68) - 1);
 BattleMenu_ConfigureGlobalCommandSelection(self, a, b);
}
