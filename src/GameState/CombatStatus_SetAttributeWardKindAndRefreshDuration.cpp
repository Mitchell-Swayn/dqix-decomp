#include <globaldefs.h>
ARM
struct Object {char pad[0x22]; unsigned short low:9; unsigned short kind:3; unsigned short high:4; char pad24[0x46]; unsigned char state; char pad6b[0x22]; unsigned char value;};
// Original: arm9/main @ 0x02088818; symbol: func_02088818; size: 0x28.
extern "C" void CombatStatus_SetAttributeWardKindAndRefreshDuration(Object* p,unsigned short a){p->kind=a;p->state=5;p->value=0;}
