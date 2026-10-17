#include <globaldefs.h>

struct State {
    unsigned short control0, pad0, control1, pad1;
    unsigned short control2, pad2, control3, pad3;
    unsigned char cached;
};

// Preserve the observed hardware snapshot and ordered shadow-register writes.
// The signed volatile stack snapshots have two reads for controls0/2 and one
// for controls1/3 in the original; their higher-level purpose is unresolved.
// Original: arm9/main @ 0x02074AF4; symbol: func_02074af4; size: 0x70.
extern "C" void Graphics_CacheFourMainBackgroundControlsOnce(volatile State* p) {
    volatile short a, b, c, d;
    if (!p->cached) {
        volatile unsigned short* registers = (volatile unsigned short*)0x04000008;
        unsigned short first = registers[0];
        a = first;
        (void)a;
        p->control0 = first;
        (void)a;
        unsigned short second = registers[1];
        p->control1 = second;
        b = second;
        (void)b;
        unsigned short third = registers[2];
        c = third;
        (void)c;
        p->control2 = third;
        (void)c;
        unsigned short fourth = registers[3];
        p->control3 = fourth;
        d = fourth;
        (void)d;
        p->cached = 1;
    }
}
