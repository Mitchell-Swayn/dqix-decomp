#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
extern "C" unsigned BattleScene_GetActiveInstance();
extern "C" void Combat_ResetActionProcedureState(int*);
struct TimerState { unsigned char pad[0x34];unsigned elapsed; };
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" TimerState CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov025 @ 0x21ef9a8; symbol: data_ov025_021ef9a8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" int CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov025 @ 0x021E30E8; symbol: func_ov025_021e30e8; size: 0x70.
// Advances the shared millisecond timer until the requested delay, then resets the request.
extern "C" int System_WaitForOverlayTimerAndResetRequest(unsigned char* request)
{
 GameState* state=GameState::GetInstance();
 if(*(unsigned*)(request+8)<=CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.elapsed) {
  if(request[0xc]) { unsigned control=BattleScene_GetActiveInstance();*(unsigned*)(control+0x6fd0)=*(unsigned*)(request+8); }
  Combat_ResetActionProcedureState(CombatInitializeActionPresentation_UnknownRoleZeroInitializedStorage);
  return 1;
 }
 CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.elapsed+=state->GetEffectiveDeltaTime();
 return 0;
}
