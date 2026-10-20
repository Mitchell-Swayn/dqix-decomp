#include <globaldefs.h>
ARM
struct Random;
extern "C" void Graphics_InitializeAndCopyDisplayRecords(int a, int b);
// Original: arm9/ov001 @ 0x021538C8; symbol: func_ov001_021538c8; size: 0xC.
extern "C" void Event_ResetSceneSessions(int a, int b)
{
    Graphics_InitializeAndCopyDisplayRecords(a, b);
}
