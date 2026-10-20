#include <globaldefs.h>
ARM
#pragma opt_optimizecontrolflow off
struct GroupedAnimation {char prefix[0x1c];int fixedValue;};
struct SingleAnimation {char prefix[0x1c];int fixedValue;};
// Original: arm9/ov015 @ 0x0218F3C4; symbol: func_ov015_0218f3c4; size: 0x44.
// Returns the nested signed fixed-point animation value as a float for either owner mode family.
extern "C" float Graphics_ReadAnimationFixedValue(unsigned char* self) {
 void* object=*(void**)(self+0x24);
 if(self[0x1c]==0||self[0x1c]==1)return (float)((volatile GroupedAnimation*)object)->fixedValue/4096.0f;
 else return (float)((volatile SingleAnimation*)object)->fixedValue/4096.0f;
}
