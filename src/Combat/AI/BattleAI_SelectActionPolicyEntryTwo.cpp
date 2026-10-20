#include <globaldefs.h>
struct EntryState;
extern "C" int BattleAI_SelectEnabledActionPolicyEntry(EntryState*,int);
// Original: arm9/ov024 @ 0x021FC004; symbol: func_ov024_021fc004; size: 0x14.
// The no-op early return retains the observed test of the selector result.
extern "C" ARM void BattleAI_SelectActionPolicyEntryTwo(EntryState* state){if(!BattleAI_SelectEnabledActionPolicyEntry(state,2))return;}
