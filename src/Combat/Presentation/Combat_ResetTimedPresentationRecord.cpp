#include <globaldefs.h>
ARM
#pragma force_active on
// Retain original presentation entries while some callers remain in weak-reference fallback objects.
struct TimedRecord {
    int state;
    unsigned char lowerFlags : 6;
    unsigned char upperFlags : 2;
    unsigned char kind, mode, padding7;
    int values[6];
    short actor, target;
    int value24, value28;
    short value2c, value2e, value30;
    unsigned char padding32[6];
    unsigned char value38, padding39, value3a, padding3b;
    short value3c;
};
// Original: arm9/ov025 @ 0x021ebb24; symbol: func_ov025_021ebb24; size: 0x6c.
// Resets a timed presentation record, clears its packed flags, and restores invalid actor identifiers.
extern "C" void Combat_ResetTimedPresentationRecord(TimedRecord* self)
{
    self->state = 0;
    self->lowerFlags = 0;
    self->upperFlags = 0;
    self->kind = 0;
    self->values[0] = 0;
    self->values[1] = 0;
    self->values[2] = 0;
    self->values[3] = 0;
    self->values[4] = 0;
    self->values[5] = 0;
    self->actor = -1;
    self->target = -1;
    self->value24 = 0;
    self->mode = 0;
    self->value28 = 0;
    self->value2c = 0;
    self->value30 = 0;
    self->value2e = 0;
    self->value38 = 0;
    self->value3a = 0;
    self->value3c = 0;
}
