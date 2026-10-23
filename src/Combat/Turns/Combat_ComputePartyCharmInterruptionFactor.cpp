#include <globaldefs.h>
ARM
#include <GameState/GameState.h>
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*, int);
#pragma always_inline on
namespace {
struct CharmModifier { unsigned char unknown[0xc]; unsigned charm:10, high:22; };
inline int IsPartyIndex(int index) { return index >= 0 && index <= 3; }
inline unsigned short CurrentCharm(GameObject* p) { return p->currentStats_->primaryStats.charm; }
inline unsigned short BaseCharm(GameObject* p) { return p->baseStats_->primaryStats.charm; }
inline unsigned short ModifierCharm(GameObject* p) { return (*(CharmModifier**)((unsigned char*)p + 0x150))->charm; }
}
// Original: arm9/ov000 @ 0x0215641C; symbol: func_ov000_0215641c; size: 0xb0.
// Computes two percent of current charm minus base charm plus the linked modifier minus one hundred.
extern "C" float Combat_ComputePartyCharmInterruptionFactor(void*, int index)
{
    GameState* state = GameState::GetInstance();
    float result = 0;
    if (IsPartyIndex(index)) {
        GameObject* object = GameState_GetObjectWithFlag100(state, index);
        if (!object) return 0;
        GameObject* p = object;
        unsigned short base = BaseCharm(p);
        unsigned short current = CurrentCharm(p);
        int difference = current - base;
        result = (float)(difference + ModifierCharm(p) - 100) * 0.02f;
    }
    return result;
}
