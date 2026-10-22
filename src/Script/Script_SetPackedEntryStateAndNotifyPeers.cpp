#include <globaldefs.h>
extern "C" void* Network_GetConnectionManager();
extern "C" bool Network_IsParentOrOffline(unsigned*);
extern "C" void Network_QueueConnectionValueRecord(unsigned char,unsigned char,unsigned short,unsigned short);
// Serialized progress state (GameState_GetSerializedProgressState): 204 packed four-bit entries at 0x2cc.
struct PackedEntryStateOwner { unsigned char unknown[0x2cc]; unsigned char packedEntryStates[102]; };
// Original: arm9/main @ 0x0206E164; symbol: func_0206e164; size: 0xB4.
// Combines packed entry state and flags; queues kind 7 updates for indices 174..203.
extern "C" ARM void Script_SetPackedEntryStateAndNotifyPeers(PackedEntryStateOwner* owner, int index, int state)
{
    if (index >= 204) return;
    if (index < 0) return;
    int half = index / 2;
    if (index % 2) {
        unsigned char upper = owner->packedEntryStates[half] >> 4;
        upper = (upper & 12) | state;
        owner->packedEntryStates[half] &= 15;
        owner->packedEntryStates[half] |= upper << 4;
    } else {
        unsigned char lower = owner->packedEntryStates[half] & 15;
        lower = (lower & 12) | state;
        owner->packedEntryStates[half] &= 0xf0;
        owner->packedEntryStates[half] |= lower;
    }
    if (!Network_IsParentOrOffline((unsigned*)Network_GetConnectionManager())) return;
    if (index < 174) return;
    Network_QueueConnectionValueRecord(7, 0, index, state);
}
