#include <globaldefs.h>
ARM
// Original: arm9/ov023 @ 0x021EAA00; symbol: func_021eaa00; size: 0xE8.
extern "C" void* _ZN9GameState11GetInstanceEv(); extern "C" void* GameState_GetIndexList(void*); extern "C" short SumIndexedValuesAcrossPresentPartyIds(void*,int); extern "C" void Script_WriteIntegerReferenceOutput(void*,int);
extern "C" int Grotto_SetTotalValueAcrossTenPartyMetrics(void *record) {
 void *gs=_ZN9GameState11GetInstanceEv(); void *owner=GameState_GetIndexList(gs);
 int total=0;
 total+=SumIndexedValuesAcrossPresentPartyIds(owner,22041);
 total+=SumIndexedValuesAcrossPresentPartyIds(owner,22045);
 total+=SumIndexedValuesAcrossPresentPartyIds(owner,22046);
 total+=SumIndexedValuesAcrossPresentPartyIds(owner,22047);
 total+=SumIndexedValuesAcrossPresentPartyIds(owner,22048);
 total+=SumIndexedValuesAcrossPresentPartyIds(owner,22049);
 total+=SumIndexedValuesAcrossPresentPartyIds(owner,22050);
 total+=SumIndexedValuesAcrossPresentPartyIds(owner,22051);
 total+=SumIndexedValuesAcrossPresentPartyIds(owner,22052);
 total+=SumIndexedValuesAcrossPresentPartyIds(owner,22053);
 Script_WriteIntegerReferenceOutput(record,total); return 1;
}
