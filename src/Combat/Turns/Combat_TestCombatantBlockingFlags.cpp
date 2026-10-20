#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* _ZN9GameState19GetCombatantByIndexEi(void*,int);
extern "C" bool GameObject_IsDead(void*);
extern "C" bool CombatStatus_HasSleep(unsigned int*);
extern "C" int Combat_IsCombatantExcludedFromSelection(char*);
extern "C" bool Combat_HasPartyOnlyRetargetingStatus(void*);
extern "C" int Combat_HasParalysis(void*);
extern "C" int Combat_HasTransientActionBlockingStatus(void*);
// Original: arm9/ov000 @ 0x02155F9C; symbol: func_ov000_02155f9c; size: 0x9C.
extern "C" int Combat_TestCombatantBlockingFlags(void* unused,int index,int includeFlag20) {
unsigned char* object=_ZN9GameState19GetCombatantByIndexEi(_ZN9GameState11GetInstanceEv(),index);
if(!object)return 1;
if(GameObject_IsDead(object) || Combat_IsCombatantExcludedFromSelection((char*)object) || Combat_HasParalysis(object) || CombatStatus_HasSleep(*(unsigned int**)(object+0x138)) || Combat_HasTransientActionBlockingStatus(object))return 1;
if(includeFlag20 && Combat_HasPartyOnlyRetargetingStatus(object))return 1;
return 0;
}
