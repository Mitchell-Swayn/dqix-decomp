#include "World/Zone3DEmbeddedState.h"

int GetSerializedRecordKey(const void* record)
{
    return ((const ZoneSerializedRecord*)record)->key;
}
