#include "World/Zone3DEmbeddedState.h"

// The signed key occupies offset 24 of each 32-byte primary record.
struct SerializedRecordKeyView
{
    char unknown[24];
    short key;
    char unknown_1a[6];
};

int GetSerializedRecordKey(const void* record)
{
    return ((const SerializedRecordKeyView*)record)->key;
}
