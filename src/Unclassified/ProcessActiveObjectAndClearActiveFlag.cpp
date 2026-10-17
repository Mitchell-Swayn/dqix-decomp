#include <globaldefs.h>
struct Object {char pad[0x10];unsigned char active;};
extern "C" void func_02074c18(Object*);
// Original: arm9/main @ 0x02074BD0; symbol: func_02074bd0; size: 0x24.
extern "C" void ProcessActiveObjectAndClearActiveFlag(Object* p) {if(!p->active)return;func_02074c18(p);p->active=0;}
