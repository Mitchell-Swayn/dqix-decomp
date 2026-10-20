#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned CombatantMotion_DisableSidestep(...);
extern "C" unsigned Combat_CollectPresentEnemyIndices(...);
extern "C" unsigned CombatantMotion_SetReservedGridCell(...);
extern "C" unsigned ResetLinkedMotionFieldsAndRestorePosition(...);
extern "C" unsigned CombatantMotion_SetPrimaryTargetIndex(...);
extern "C" unsigned CombatantMotion_SetFallbackTargetIndex(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned _ZN9GameState19GetCombatantByIndexEi(...);
extern "C" unsigned Combat_CollectEligiblePartyIds(...);
// Original: arm9/ov000 @ 0x021629EC; symbol: ResetCollectedCombatantMotionAndSentinels; size: 0xc0.
// Collects up to12 enabled IDs, resets linked motion and clears flags/sentinel bytes on each combatant.
extern "C" void Combat_ResetCollectedMotionAndTargets(char* p){
 unsigned state=_ZN9GameState11GetInstanceEv();short ids[12];int count=0;count+=Combat_CollectEligiblePartyIds(U(p,0x29c),ids,12,0);count+=Combat_CollectPresentEnemyIndices(U(p,0x29c),ids+count,12-count,0);
 for(int i=0;i<count;i++){unsigned combatant=_ZN9GameState19GetCombatantByIndexEi(state,ids[i]);if(combatant){ResetLinkedMotionFieldsAndRestorePosition(combatant);CombatantMotion_DisableSidestep(combatant);CombatantMotion_SetPrimaryTargetIndex(combatant,255);CombatantMotion_SetFallbackTargetIndex(combatant,255);CombatantMotion_SetReservedGridCell(combatant,255);}}
}
