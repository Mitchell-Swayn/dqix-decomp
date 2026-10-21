#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
ARM
struct State;
struct Entry;
extern "C" {
void* __clear(void* destination, unsigned int count);
int GameState_ReadProtagonistObjectIndex(GameState* state);
void* GameState_GetIndexList(GameState* state);
void Window_PopCanvasesAndResetSelection(State* p, int flag);
char* BattleMenu_FindPartyCommandRecord(char* p, int id);
void BattleMenu_AppendUniquePartyActionChoice(char* self, int value);
void BattleMenu_OpenPanelForSelectionState(void*, void*, int, int, int);
Entry* BattleMenu_GetSelectedPartyCommandRecord(char* obj);
// Original data: arm9/ov000 @ 0x218342a; symbol: BattleMenuOpenPartyVocationActionChoices_UnknownRoleInitializedBytes.
extern unsigned short BattleMenuOpenPartyVocationActionChoices_UnknownRoleInitializedBytes[];
// Original data: arm9/ov000 @ 0x2183ff0; symbol: BattleMenuRemovePartyMember_UnknownRoleInitializedBytes.
extern unsigned BattleMenuRemovePartyMember_UnknownRoleInitializedBytes[];
// Original data: arm9/ov000 @ 0x2184288; symbol: BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage.
extern unsigned BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[];
}
// Original: arm9/ov000 @ 0x02175808; symbol: func_ov000_02175808; size: 0x1EC.
// Builds unique vocation-action choices from party members, marks listed command records, and opens the selection panel.
extern "C" void BattleMenu_OpenPartyVocationActionChoices(char* self) {
 memset(self + 0x10, 0, 0xa);
 self[0x1a] = 0;
 unsigned char flags[13];
 __clear(flags, 0xd);
 unsigned char count = 0;
 GameState* game = GameState::GetInstance();
 for (signed char member = 0; member < 4; member = (signed char)(member + 1)) {
  GameObject* object = game->GetPartyMemberByIndex(member);
  if (!object) return;
  unsigned vocation = *(unsigned*)(*(char**)((char*)object + 0x150) + 0x950);
  if (*(int*)(self + 0x20) >= 0) {
   if (BattleMenuOpenPartyVocationActionChoices_UnknownRoleInitializedBytes[vocation] == 0x20a) continue;
  }
  flags[vocation] = 1;
 }
 for (signed char vocation = 0; vocation < 0xd; vocation = (signed char)(vocation + 1)) {
  if (!flags[vocation]) continue;
  BattleMenu_AppendUniquePartyActionChoice(self, BattleMenuOpenPartyVocationActionChoices_UnknownRoleInitializedBytes[vocation]);
  count = (unsigned char)(count + 1);
 }
 if (!count) return;
 game = GameState::GetInstance();
 *(int*)(self + 0x17c) = GameState_ReadProtagonistObjectIndex(game);
 BattleMenu_AppendUniquePartyActionChoice(self, 0);
 unsigned char* list = (unsigned char*)GameState_GetIndexList(game);
 unsigned char listed = list[0xf7c];
 for (unsigned char i = 0; i < listed; i = (unsigned char)(i + 1)) {
  char* record = BattleMenu_FindPartyCommandRecord(self, *(signed char*)(list + i + 0xf78));
  if (record) {
   char* marked = record + *(signed char*)(record + 0x18);
   marked[0x10] = 0xd;
  }
 }
 Window_PopCanvasesAndResetSelection((State*)(self + 0x188), 1);
 self[0x1d6d] = 0;
 *(signed char*)(self + 0x1d68) = (signed char)(*(signed char*)(self + 0x1d68) + 1);
 char* slot = self + *(signed char*)(self + 0x1d68);
 (slot + 0x1000)[0xd60] = 0x17;
 Entry* entry = BattleMenu_GetSelectedPartyCommandRecord(self);
 BattleMenu_OpenPanelForSelectionState(self, entry, 0x17, BattleMenuRemovePartyMember_UnknownRoleInitializedBytes[0], BattleHudUpdateSlotHighlightPalette_UnknownRoleZeroInitializedStorage[1]);
 self[0x1d81] = 0;
}
