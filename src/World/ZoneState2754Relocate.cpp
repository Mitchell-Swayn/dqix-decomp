#include "World/Zone3DEmbeddedState.h"

extern const short gSpecialSerializedRecordKeys[2] = { 22125, 22126 };

bool RelocateSerializedRecordPayload(ZoneState2754* state, void* rawRecord)
{
    ZoneSerializedRecord* record = (ZoneSerializedRecord*)rawRecord;
    bool missing;
    // Before relocation this pointer slot encodes an offset from address zero.
    // Preserve the target compiler's pointer-offset conversion idiom here.
    unsigned int offset = (char*)record->payload.pointer - (char*)0;
    missing = true;
    if (offset != (unsigned int)-1 && state->data.payload) missing = false;
    record->payload.pointer = missing ? 0 : (char*)state->data.payload + offset;
    return true;
}

bool ZoneState2754::RelocateSecondaryRecordLinks()
{
    ZoneSerializedRecord* secondary;
    ZoneSerializedRecord* record;
    int count = data.primaryCount;
    record = (ZoneSerializedRecord*)data.records;
    secondary = record + count;
    for (int i = 0; i < count; ++i, ++record)
    {
        ZoneSerializedRecord* target = 0;
        if (record->secondary.index != (unsigned int)-1)
            target = secondary + record->secondary.index;
        record->secondary.pointer = target;
    }
    ApplySpecialRecordFlags();
    return true;
}

bool ZoneState2754::ApplySpecialRecordFlags()
{
    const short* key = gSpecialSerializedRecordKeys;
    for (int i = 0; i < 2; ++i, ++key)
    {
        ZoneSerializedRecord* record = (ZoneSerializedRecord*)FindPrimaryRecord(*key, GetSerializedRecordKey);
        if (record) record->unknown_16 = 0xfc;
    }
    return true;
}
