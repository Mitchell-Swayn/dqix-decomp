#include <globaldefs.h>
struct Object {char pad[0x11];unsigned char active;};
extern "C" void Graphics_ApplySubBackgroundControlRegisters(Object*);
// Original: arm9/main @ 0x02074BF4; symbol: func_02074bf4; size: 0x24.
extern "C" void Object_ResetAndDeactivateState(Object* p) {if(!p->active)return;Graphics_ApplySubBackgroundControlRegisters(p);p->active=0;}
