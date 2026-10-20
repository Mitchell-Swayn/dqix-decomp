#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma opt_propagation off
// Original: arm9/ov017 @ 0x02190818; symbol: func_ov017_02190818; size: 0x6C.
// Requires the indexed party member and tests the signed type halfword of object index12*member+20 against 0x2347..0x2349.
// The meaning of these three type values remains unresolved.
extern "C" int GameState_TestIndexedObjectTypeTriple(int index)
{
    GameState* state=GameState::GetInstance();
    if (state->GetPartyMemberByIndex(index)) {
        GameObject* object=state->GetGameObjectByIndex(12*index+20);
        if (object) {
            int type=object->obj3D_.unknown_2_;
            int firstType=0x2347;
            if (type==firstType || type==firstType+1 || type==firstType+2) return 1;
        }
    }
    return 0;
}
