#include <globaldefs.h>
ARM
#pragma opt_optimizecontrolflow off
struct ViewerObject { char prefix[12]; void* packages; };
// Original: arm9/ov015 @ 0x0218F344; symbol: func_ov015_0218f344; size: 0x20.
// Returns the loaded animation package list for either viewer model family.
extern "C" void* CharacterViewer_GetAnimationPackageList(unsigned char* self) {
 switch(self[0x1c]) {
 case 0: case 1: return (*(ViewerObject**)(self+0x24))->packages;
 default: return (*(ViewerObject**)(self+0x24))->packages;
 }
}
