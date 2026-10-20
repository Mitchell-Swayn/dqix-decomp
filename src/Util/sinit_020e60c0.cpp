#include "Util/Random.h"

#pragma define_section init ".init" RX

// The "public" name string is pooled in the existing .data string table.
extern "C" const char ProgramData_TextPublic[];

// Global constructor thunk for the battle random state.
// Original: arm9/main @ 0x020E60C0; symbol: __sinit_020e60c0; size: 0x20.
extern "C" __declspec(section "init") void __sinit_020e60c0()
{
    CreateRandom(&GetBTRandom_UnknownRoleZeroInitializedStorage, ProgramData_TextPublic, 1);
}
