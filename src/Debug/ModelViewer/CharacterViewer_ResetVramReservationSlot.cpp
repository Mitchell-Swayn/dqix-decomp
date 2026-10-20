#include <globaldefs.h>
struct Entry { unsigned value; unsigned char active; };
// Original: arm9/ov015 @ 0x021933AC; symbol: func_ov015_021933ac; size: 0x10.
extern "C" ARM void CharacterViewer_ResetVramReservationSlot(Entry* p){p->value=0;p->active=0;}
