#include <globaldefs.h>
#include <GameState/GameState.h>
// Original: arm9/ov017 @ 0x021A278C; symbol: func_ov017_021a278c; size: 0x5C.
// Field roles are unresolved; observed offsets are retained.
extern "C" ARM GameObject* FindFieldMonsterByRecordIdentifier(int unused, int identifier)
{
    if(identifier<=0) return 0;
    GameState* state=GameState::GetInstance();
    for(int i=0;i<48;++i)
    {
        GameObject* p=state->GetMaybeFieldMonsterByIndex(i+112);
        if(p && identifier==*(unsigned short*)((char*)p+0x16a)) return p;
    }
    return 0;
}
