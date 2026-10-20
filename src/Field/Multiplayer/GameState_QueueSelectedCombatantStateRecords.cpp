#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameResources_GetInstance();
extern "C" void* FieldBattle_GetEncounterRequest(void*);
extern "C" void* Network_GetCommandRecordPool();
extern "C" void* _ZN9GameState19GetCombatantByIndexEi(void*, int);
extern "C" unsigned int PartySelection_GetMemberMask(unsigned char*, unsigned int);
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" void Network_QueueOutgoingRecord(void*, const void*, short);
// Original: arm9/ov017 @ 0x021c6ff0; GameState_QueueSelectedCombatantStateRecords; 240 bytes
extern "C" void GameState_QueueSelectedCombatantStateRecords(void) {
 void* state = _ZN9GameState11GetInstanceEv();
 void* resources = GameResources_GetInstance();
 void* embedded = FieldBattle_GetEncounterRequest(*(void**)((char*)resources + 0x3718));
 void* global = Network_GetCommandRecordPool();
 unsigned char record[0x14];
 record[0] = 0x70;
 unsigned short* payload = (unsigned short*)(record + 4);
 for (int index = 0; index < 4; ++index) {
  if (!PartySelection_GetMemberMask((unsigned char*)embedded, index & 0xff)) continue;
  void* combatant = _ZN9GameState19GetCombatantByIndexEi(state, index);
  if (!combatant || !*(unsigned char*)(*(unsigned char**)((char*)combatant + 0x138) + 0x26)) continue;
  payload[0] = *(unsigned short*)((char*)embedded + 8);
  payload[1] = index;
  memcpy(payload + 2, *(unsigned char**)((char*)combatant + 0x138) + 0x58, 4);
  payload[4] = *(short*)(*(unsigned char**)((char*)combatant + 0x138) + 0x28);
  payload[5] = *(short*)(*(unsigned char**)((char*)combatant + 0x138) + 0x2a);
  payload[6] = *(short*)(*(unsigned char**)((char*)combatant + 0x138) + 0x2c);
  payload[7] = *(short*)(*(unsigned char**)((char*)combatant + 0x138) + 0x2e);
  Network_QueueOutgoingRecord(global, record, 0);
 }
}
