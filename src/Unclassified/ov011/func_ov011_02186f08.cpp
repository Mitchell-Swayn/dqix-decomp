#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
struct Argument { unsigned kind; void* pointer; };
struct Arguments { Argument entries[2]; };
extern "C" void Ov023_InitializeFieldsAndSetFlags(void*, void*);
// Original: arm9/ov011 @ 0x02186F08; symbol: func_ov011_02186f08; size: 0x6C.
extern "C" unsigned func_ov011_02186f08(Arguments* self) {
 unsigned id=func_ov011_02184c30(self);
 void* value=self->entries[1].kind==2 ? self->entries[1].pointer : 0;
 if(!value) return 0;
 void* item=func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()),id);
 if(!item) return 0;
 if(OV023_ReadHalfwordField04(item)!=2) return 0;
 Ov023_InitializeFieldsAndSetFlags(item,value);
 return 1;
}
