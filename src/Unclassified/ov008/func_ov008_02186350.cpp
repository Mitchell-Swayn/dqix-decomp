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
// Original: arm9/ov008 @ 0x02186350; symbol: func_ov008_02186350; size: 0x1C.
extern "C" void func_ov008_02186350(Overlay8State* object) { object->variant=3; object->state=13; object->phase=0; }
