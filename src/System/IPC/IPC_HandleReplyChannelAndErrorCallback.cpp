struct TouchPoint { unsigned short x, y, touched, validity; };
union RawTouchPoint {
    struct { unsigned short low, high; } halves;
    struct { unsigned int x:12, y:12, touched:1, validity:2, reserved:5; } bits;
};
struct TouchState {
    unsigned int reserved;
    void (*callback)(unsigned int, unsigned int, unsigned int);
    TouchPoint point;
    unsigned short index, reserved12;
    TouchPoint* samples;
    unsigned short capacity;
    unsigned short reserved1A[14];
    unsigned short samplingState, errors, pending;
};
// Original data: arm9/main @ 0x21117b0; symbol: data_021117b0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" TouchState TPWaitBusy_UnknownRoleZeroInitializedStorage;
extern "C" void DisableInterruptsAndHaltForever();
#pragma optimize_for_size off
// Original: arm9/main @ 0x020CD610; symbol: func_020cd610; size: 0x280.
extern "C" void IPC_HandleReplyChannelAndErrorCallback(unsigned int tag, unsigned int message, int error)
{
    unsigned short reply = message;
    unsigned short channel = (reply & 0x7f00) >> 8;
    if (error) {
        TPWaitBusy_UnknownRoleZeroInitializedStorage.errors |= 1 << channel;
        if (TPWaitBusy_UnknownRoleZeroInitializedStorage.callback) TPWaitBusy_UnknownRoleZeroInitializedStorage.callback(channel, 4, 0);
        return;
    }
    if (channel == 16) {
        TPWaitBusy_UnknownRoleZeroInitializedStorage.index++;
        if (TPWaitBusy_UnknownRoleZeroInitializedStorage.index >= TPWaitBusy_UnknownRoleZeroInitializedStorage.capacity) TPWaitBusy_UnknownRoleZeroInitializedStorage.index = 0;
        unsigned short index;
        TouchPoint* samples;
        RawTouchPoint raw;
        volatile unsigned short* hardware = (volatile unsigned short*)0x027fffaa;
        raw.halves.low = hardware[0];
        raw.halves.high = hardware[1];
        index = TPWaitBusy_UnknownRoleZeroInitializedStorage.index;
        samples = TPWaitBusy_UnknownRoleZeroInitializedStorage.samples;
        TouchPoint* point = &samples[index];
        point->x = raw.bits.x;
        point->y = raw.bits.y;
        point->touched = (unsigned char)raw.bits.touched;
        point->validity = (unsigned char)raw.bits.validity;
        if (TPWaitBusy_UnknownRoleZeroInitializedStorage.callback) TPWaitBusy_UnknownRoleZeroInitializedStorage.callback(channel, 0, (unsigned char)TPWaitBusy_UnknownRoleZeroInitializedStorage.index);
        return;
    }
    if (!(message & 0x01000000)) return;
    unsigned int status;
    switch (reply & 0xff) {
    case 0:
        switch (channel) { case 0: {
            RawTouchPoint raw;
            volatile unsigned short* hardware = (volatile unsigned short*)0x027fffaa;
            raw.halves.low = hardware[0];
            raw.halves.high = hardware[1];
            TPWaitBusy_UnknownRoleZeroInitializedStorage.point.x = raw.bits.x;
            TPWaitBusy_UnknownRoleZeroInitializedStorage.point.y = raw.bits.y;
            TPWaitBusy_UnknownRoleZeroInitializedStorage.point.touched = (unsigned char)raw.bits.touched;
            TPWaitBusy_UnknownRoleZeroInitializedStorage.point.validity = (unsigned char)raw.bits.validity;
            TPWaitBusy_UnknownRoleZeroInitializedStorage.samplingState = 0;
        } break;
        case 1: TPWaitBusy_UnknownRoleZeroInitializedStorage.samplingState = 2; break;
        case 2: TPWaitBusy_UnknownRoleZeroInitializedStorage.samplingState = 0; break;
        }
        TPWaitBusy_UnknownRoleZeroInitializedStorage.pending &= ~(1 << channel);
        if (TPWaitBusy_UnknownRoleZeroInitializedStorage.callback) TPWaitBusy_UnknownRoleZeroInitializedStorage.callback(channel, 0, 0);
        return;
    case 4: status = 3; break;
    case 2: status = 1; break;
    case 3: status = 2; break;
    default: goto unexpectedReply;
    }
    TPWaitBusy_UnknownRoleZeroInitializedStorage.errors |= 1 << channel;
    TPWaitBusy_UnknownRoleZeroInitializedStorage.pending &= ~(1 << channel);
    if (TPWaitBusy_UnknownRoleZeroInitializedStorage.callback) TPWaitBusy_UnknownRoleZeroInitializedStorage.callback(channel, (unsigned char)status, 0);
    return;
unexpectedReply:
    DisableInterruptsAndHaltForever();
}
