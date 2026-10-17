#include <globaldefs.h>
#include <GameState/GameState.h>
extern "C" unsigned GameState_CopyField571DBufferToDestination(GameState*,void*);
// Original: arm9/main @ 0x020DC4D0; symbol: func_020dc4d0; size: 0x78.
extern "C" void GameState_CollectPresentPartyMemberIndices(signed char* out,signed char* count) { GameState* state=GameState::GetInstance(); signed char members[8]; signed char n=GameState_CopyField571DBufferToDestination(state,members); signed char written=0; signed char i=written; for(;i<n;i++) { if(state->GetPartyMemberByIndex(members[i])) {out[written]=members[i]; written++;} } *count=written; }
