#include <globaldefs.h>
struct Object;
typedef void (*Method)(Object*,unsigned);
typedef void (*Method0)(Object*);
typedef void (*Method3)(Object*,unsigned,unsigned,unsigned);
struct VTable { Method slots[54]; };
struct Object { VTable* methods; unsigned short kind; char pad[6]; unsigned char flags; };
struct GlobalState { char pad[0x998]; unsigned field998,field99c,field9a0; char pad9a4[0x1026]; unsigned char enabled; };
extern "C" GlobalState* ReadWordFieldAtOffset1C();
extern "C" int func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" Object* func_ov023_021f6880(void*,unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(Object*);
extern "C" void func_ov011_02184c68(void*,unsigned);
extern "C" void func_ov011_02184a40(void*,unsigned);
// Original: arm9/ov011 @ 0x021883E8; symbol: func_ov011_021883e8; size: 0x50.
extern "C" unsigned func_ov011_021883e8(void* self) { unsigned id=func_ov011_02184c30(self); unsigned value1=func_ov011_02184c30((char*)self+8); Object* item=func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()),id); if(!item) return 0; item->methods->slots[13](item,value1); return 1; }
