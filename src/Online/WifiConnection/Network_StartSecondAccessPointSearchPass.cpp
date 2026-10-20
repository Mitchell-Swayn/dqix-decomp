#include <globaldefs.h>
ARM
struct PriorityModeNibbles { unsigned char low:4,high:4; };
extern "C" unsigned Resource_RebuildPriorityStateByMode(int);
// Original: arm9/ov031 @ 0x02214D38; symbol: func_ov031_02214d38; size: 0x48.
// Clears D15, advances D0B's high nibble, rebuilds priority state in mode zero, and publishes D11=1/result3.
extern "C" int Network_StartSecondAccessPointSearchPass(unsigned char* state)
{
 state[0xd15]=0;
 ++((PriorityModeNibbles*)(state+0xd0b))->high;
 Resource_RebuildPriorityStateByMode(0);
 state[0xd11]=1;
 return 3;
}
