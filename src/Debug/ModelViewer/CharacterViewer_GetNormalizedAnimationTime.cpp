#include <globaldefs.h>
ARM
#pragma opt_optimizecontrolflow off
struct ModelAnimation { char prefix[0x24]; int time; };
struct SingleAnimation { char prefix[0x24]; int time; };
// Original: arm9/ov015 @ 0x0218F408; symbol: func_ov015_0218f408; size: 0x44.
// Returns the animation time divided by the 4096-unit fixed-point scale.
// Volatile preserves the original branch-local animation counter load.
extern "C" float CharacterViewer_GetNormalizedAnimationTime(unsigned char* self) {
 void* object=*(void**)(self+0x24);
 switch(self[0x1c]) {
 case 0: case 1: return (float)((volatile ModelAnimation*)object)->time/4096.0f;
 default: return (float)((volatile SingleAnimation*)object)->time/4096.0f;
 }
}
