#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma opt_propagation off
extern "C" void* GameState_GetIndexList(GameState*);
// Original: arm9/ov003 @ 0x02160C58; symbol: Tavern_GetRosterCapacityAndFreeStoredSlots; size: 0x68.
// Caps the saved count at four, reports a total capped at twelve and its difference from byte 0x2C8C.
// The role of the byte and the unused first parameter remains unresolved.
extern "C" void Tavern_GetRosterCapacityAndFreeStoredSlots(void* unused, short* total, short* remaining)
{
    short count = 12;
    unsigned char used = *((unsigned char*)GameState_GetIndexList(GameState::GetInstance()) + 0x2c8c);
    count -= 4;
    unsigned int* savedCount = (unsigned int*)((unsigned char*)GameState_GetIndexList(GameState::GetInstance()) + 0xf70);
    if (*savedCount > 4) *savedCount = 4;
    count += *savedCount;
    if (count > 12) count = 12;
    *total = count;
    *remaining = count - used;
}
