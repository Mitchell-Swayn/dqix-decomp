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
extern "C" TouchState data_021117b0;
extern "C" void DisableInterruptsAndHaltForever();
#pragma optimize_for_size off
// Original: arm9/main @ 0x020CD610; symbol: func_020cd610; size: 0x280.
extern "C" void IPC_HandleReplyChannelAndErrorCallback(unsigned int tag, unsigned int message, int error)
{
    unsigned short reply = message;
    unsigned short channel = (reply & 0x7f00) >> 8;
    if (error) {
        data_021117b0.errors |= 1 << channel;
        if (data_021117b0.callback) data_021117b0.callback(channel, 4, 0);
        return;
    }
    if (channel == 16) {
        data_021117b0.index++;
        if (data_021117b0.index >= data_021117b0.capacity) data_021117b0.index = 0;
        unsigned short index;
        TouchPoint* samples;
        RawTouchPoint raw;
        volatile unsigned short* hardware = (volatile unsigned short*)0x027fffaa;
        raw.halves.low = hardware[0];
        raw.halves.high = hardware[1];
        index = data_021117b0.index;
        samples = data_021117b0.samples;
        TouchPoint* point = &samples[index];
        point->x = raw.bits.x;
        point->y = raw.bits.y;
        point->touched = (unsigned char)raw.bits.touched;
        point->validity = (unsigned char)raw.bits.validity;
        if (data_021117b0.callback) data_021117b0.callback(channel, 0, (unsigned char)data_021117b0.index);
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
            data_021117b0.point.x = raw.bits.x;
            data_021117b0.point.y = raw.bits.y;
            data_021117b0.point.touched = (unsigned char)raw.bits.touched;
            data_021117b0.point.validity = (unsigned char)raw.bits.validity;
            data_021117b0.samplingState = 0;
        } break;
        case 1: data_021117b0.samplingState = 2; break;
        case 2: data_021117b0.samplingState = 0; break;
        }
        data_021117b0.pending &= ~(1 << channel);
        if (data_021117b0.callback) data_021117b0.callback(channel, 0, 0);
        return;
    case 4: status = 3; break;
    case 2: status = 1; break;
    case 3: status = 2; break;
    default: goto unexpectedReply;
    }
    data_021117b0.errors |= 1 << channel;
    data_021117b0.pending &= ~(1 << channel);
    if (data_021117b0.callback) data_021117b0.callback(channel, (unsigned char)status, 0);
    return;
unexpectedReply:
    DisableInterruptsAndHaltForever();
}
