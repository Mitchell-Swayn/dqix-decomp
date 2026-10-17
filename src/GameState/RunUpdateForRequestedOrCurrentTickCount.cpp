#include <globaldefs.h>
#include <GameState/GameState.h>
#pragma optimization_level 4
#pragma optimize_for_size off
extern "C" void func_02067b28(unsigned int);
// Original: arm9/main @ 0x02067E58; symbol: func_02067e58; size: 0x40.
extern "C" void RunUpdateForRequestedOrCurrentTickCount(unsigned int param_1, unsigned int param_2) {
    if (param_2 == 0) return;
    unsigned int ticks = GameState::GetInstance()->GetTickCount();
    if (param_2 < ticks) param_2 = ticks;
    goto loop_check;
loop_body:
    func_02067b28(param_1);
    if (param_2 != 0) param_2 = param_2 - 1;
loop_check:
    if ((int)param_2 > 0) goto loop_body;
}
