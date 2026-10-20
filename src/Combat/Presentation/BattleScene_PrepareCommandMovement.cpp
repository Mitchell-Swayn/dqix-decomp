#include <globaldefs.h>
ARM
extern "C" void* BattleScene_ResolveCurrentActionRecord(void*);
extern "C" void BattleScene_RefreshCombatantMotionTargets(void*);
extern "C" int Combat_ClassifySpecialEncounterSpecies(unsigned char*);
extern "C" char* Combat_GetCommandActorSnapshot(void*,int);
extern "C" int BattleScene_PlanCommandGridDestinations(void*);
extern "C" void BattleScene_BuildCoordinatedCombatantPaths(void*);
struct Flags {unsigned char low:2;unsigned char active:1;unsigned char rest:5;};
// Original: arm9/ov025 @ 0x021DC0D8; symbol: UpdateLinkedRecordAndDispatchWhenFlagTwoSet; size: 0x90.
extern "C" void BattleScene_PrepareCommandMovement(char* self) {
 unsigned char* record=*(unsigned char**)(self+0x29c);void* resolved=BattleScene_ResolveCurrentActionRecord(self);BattleScene_RefreshCombatantMotionTargets(self);
 if(Combat_ClassifySpecialEncounterSpecies(record)){char* primary=Combat_GetCommandActorSnapshot(resolved,0);if(primary && !*(unsigned short*)(primary+32))return;}
 Flags* flags=(Flags*)(self+0x5951);flags->active=(unsigned char)BattleScene_PlanCommandGridDestinations(self);if(flags->active==1)BattleScene_BuildCoordinatedCombatantPaths(self);
}
