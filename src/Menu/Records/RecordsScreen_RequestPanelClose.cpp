// Field meanings beyond the state-control bytes remain unresolved.
struct Overlay8State {
    unsigned char unknown[0xb10];
    unsigned char state;
    unsigned char phase;
    unsigned char unknownB12;
    unsigned char variant;
    unsigned char unknownB14[4];
    unsigned flags;
};
// Original: arm9/ov008 @ 0x02184A2C; symbol: func_ov008_02184a2c; size: 0x10.
extern "C" void RecordsScreen_RequestPanelClose(Overlay8State* object) { object->flags |= 0x100000; }
