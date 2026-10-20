#include <globaldefs.h>
ARM
typedef unsigned int undefined4;
extern "C" unsigned GameObject_GetLinkedIndexedState(int);
struct TenBitValue {unsigned value:10;unsigned rest:22;};
struct FloatPairRecord {int object;unsigned pad[4];float first,second,resultFirst,resultSecond;};
#pragma opt_propagation off
#pragma opt_common_subs off
// Original: arm9/ov024 @ 0x021F72F8; symbol: func_ov024_021f72f8; size: 0x74.
// Adds the object's low ten-bit field to half of each of two stored floats.
extern "C" int BattleAI_AddLinkedStatToHalvedDamageEstimates(FloatPairRecord* self) {
 unsigned char* nested=(unsigned char*)GameObject_GetLinkedIndexedState(self->object);
 int value=((TenBitValue*)(nested+4))->value;
 self->resultFirst=self->first/2.0f+(float)value;
 self->resultSecond=self->second/2.0f+(float)value;
 return 1;
}
