#include <globaldefs.h>
ARM
extern "C" int OverlayLoader_GetSecondarySelectionOrMinusOne(void);
extern "C" void BattleScene_AdmitPendingPartyMembersWhenQueuesReady(char* state);
// Original: arm9/ov000 @ 0x02163B40; symbol: func_ov000_02163b40; size: 0x20.
extern "C" void System_CallStateFunctionWhenLastStackEntryIsThree(char* state) { if (OverlayLoader_GetSecondarySelectionOrMinusOne() == 3) BattleScene_AdmitPendingPartyMembersWhenQueuesReady(state); }
