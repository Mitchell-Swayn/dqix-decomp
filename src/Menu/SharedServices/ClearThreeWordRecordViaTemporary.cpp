#include <globaldefs.h>
ARM
#pragma always_inline on
struct ThreeWordRecord { unsigned words[3]; };
// Original: arm9/ov004 @ 0x0215E300; symbol: func_ov004_0215e300; size: 0x2C.
// Zero-initializes a three-word temporary and copies it to the destination. Record role unknown.
extern "C" void ClearThreeWordRecordViaTemporary(ThreeWordRecord* destination) {
 ThreeWordRecord temporary={0};
 *destination=temporary;
}
