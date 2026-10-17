#include <globaldefs.h>
struct Slot { unsigned value;unsigned char active;char opaque[3]; }; struct SlotPool { char opaque[0xe4];Slot slots[4]; };
// Original: arm9/ov015 @ 0x0219322C; symbol: func_ov015_0219322c; size: 0x34.
extern "C" ARM Slot* func_ov015_0219322c(SlotPool* p){for(int i=0;i<4;++i){if(p->slots[i].active==0)return &p->slots[i];}return 0;}
