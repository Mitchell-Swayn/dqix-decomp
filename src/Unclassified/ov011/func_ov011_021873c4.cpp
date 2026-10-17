#include <globaldefs.h>
extern "C" unsigned func_ov011_02184c30(void*);
extern "C" void* func_ov017_021b2164();
extern "C" void* func_ov011_021849c8(void*);
extern "C" void* func_ov023_021f6880(void*, unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
struct GlobalState { char header[0x998]; unsigned field998; char padding99c[0x1036]; unsigned char enabled; };
extern "C" void* OV023_GetEmbeddedField20(void*);
extern "C" GlobalState* ReadWordFieldAtOffset1C();
extern "C" unsigned FindRecordValueByKeyOrZero(void*,int);
extern "C" void func_0204500c(GlobalState*,unsigned,unsigned,unsigned);
// Original: arm9/ov011 @ 0x021873C4; symbol: func_ov011_021873c4; size: 0x9C.
extern "C" unsigned func_ov011_021873c4(void* self) {
 unsigned id=func_ov011_02184c30(self);
 unsigned value=func_ov011_02184c30((char*)self+8);
 void* item=func_ov023_021f6880(func_ov011_021849c8(func_ov017_021b2164()),id);
 if(!item) return 1;
 if(OV023_ReadHalfwordField04(item)!=4) return 1;
 void* contents=OV023_GetEmbeddedField20(item);
 if(!contents) return 1;
 GlobalState* state=ReadWordFieldAtOffset1C();
 unsigned result=FindRecordValueByKeyOrZero(contents,(short)value);
 func_0204500c(state,result,0,0xe3);
 state->field998=1;
 state->enabled=1;
 return 1;
}
