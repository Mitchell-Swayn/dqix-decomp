#include <globaldefs.h>
struct Slot { unsigned value;unsigned char active;char opaque[3]; }; struct SlotPool { char opaque[0xc4];Slot slots[4]; };
// Original: arm9/ov015 @ 0x021931F8; symbol: func_ov015_021931f8; size: 0x34.
extern "C" ARM Slot* CharacterViewer_FindUnusedPlayerVramReservation(SlotPool* p){for(int i=0;i<4;++i){if(p->slots[i].active==0)return &p->slots[i];}return 0;}
