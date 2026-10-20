#include <globaldefs.h>
struct Object {char pad[0x10];unsigned char active;};
extern "C" void Graphics_ApplyMainBackgroundControlRegisters(Object*);
// Original: arm9/main @ 0x02074BD0; symbol: func_02074bd0; size: 0x24.
extern "C" void Graphics_ApplyMainBackgroundSnapshotAndClearPending(Object* p) {if(!p->active)return;Graphics_ApplyMainBackgroundControlRegisters(p);p->active=0;}
