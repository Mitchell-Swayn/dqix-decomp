#include "World/Zone3DEmbeddedState.h"

// Original: arm9/main @ 0x020DE56C; symbol: _Z22GetSerializedRecordKeyPKv; size: 0x8.
int GetSerializedRecordKey(const void* record)
{
    return ((const ZoneSerializedRecord*)record)->key;
}
