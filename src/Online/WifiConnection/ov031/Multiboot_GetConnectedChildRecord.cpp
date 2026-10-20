#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" unsigned short* MultibootGetParentState_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02239250; symbol: Multiboot_GetConnectedChildRecord; size: 0x34.
// Returns the 30-byte peer record projection when its shared enabled bit is set.
extern "C" unsigned char* Multiboot_GetConnectedChildRecord(int index)
{
 unsigned short* state=MultibootGetParentState_UnknownRoleZeroInitializedStorage;
 if(!(state[1]&(1<<index)))return 0;
 return (unsigned char*)state + 0xe + (index-1)*30;
}
