#include <globaldefs.h>
ARM
class GameState {public:static GameState* GetInstance();};
class SafeAllocator {public:void Reset();};
extern "C" {void* Network_GetConnectionManager();int GameState_ReadProtagonistObjectIndex(GameState*);void Util_SeedRandomFromWordPair(void*,int,int);void BattleScene_CommitPartyCommandSelections(void*);void Combat_ProcessTurn(void*,void*);void Combat_FinishTurnAndDetermineOutcome(void*);void BattleScene_ClearFlags(void*,unsigned);void BattleScene_QueueBattlePlaybackOverlay(void*);unsigned char* GameState_GetSerializedProgressState();void BitArray_SetIndexedBoolean(void*,void*,int,int);unsigned char* GameState_GetIndexList(GameState*);void PartyRoster_QueueSynchronizedConfigurationWord();}
// Original: arm9/ov000 @ 0x02169770; symbol: func_ov000_02169770; size: 0xe0.
// Processes the pending turn, queues playback and records the special synchronized progression flag.
extern "C" void BattleScene_ProcessTurnAndQueuePlayback(unsigned char* scene) {
 GameState* state=GameState::GetInstance();Network_GetConnectionManager();
 unsigned char* battle=*(unsigned char**)(scene+0x29c);
 GameState_ReadProtagonistObjectIndex(state);
 Util_SeedRandomFromWordPair(battle,*(int*)(scene+0x6e3c),*(int*)(scene+0x6e40));
 BattleScene_CommitPartyCommandSelections(scene);
 ((SafeAllocator*)(scene+0x30))->Reset();
 if(scene[0x5950]!=2){Combat_ProcessTurn(battle,scene+0x30);Combat_FinishTurnAndDetermineOutcome(battle);}
 ((SafeAllocator*)(scene+0x30))->Reset();
 scene[0x5950]=1;
 BattleScene_ClearFlags(scene,0x800000);
 BattleScene_QueueBattlePlaybackOverlay(scene);
 if(*(int*)(*(unsigned char**)(scene+0x2a0)+0xc)==0x19 && *(signed char*)(*(unsigned char**)(scene+0x29c)+0x8e14)==1) {
  unsigned char* progress=GameState_GetSerializedProgressState();BitArray_SetIndexedBoolean(progress,progress+0x8c,3,1);
  *(int*)(GameState_GetIndexList(state)+0x2c94)=0x6d;
  PartyRoster_QueueSynchronizedConfigurationWord();
 }
}
