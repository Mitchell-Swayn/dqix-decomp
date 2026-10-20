#include <globaldefs.h>
ARM
extern "C" void BattleScene_MarkPartyAndMonsterSetupReady(void*);
// Original: arm9/ov017 @ 0x021B86E0; symbol: func_ov017_021b86e0; size: 0x18.
extern "C" void FieldBattle_MarkSceneSetupReady(void* p) { void* q = *(void**)((char*)p + 0x6ac); if (q) BattleScene_MarkPartyAndMonsterSetupReady(q); }
