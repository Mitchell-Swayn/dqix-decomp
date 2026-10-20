#include <globaldefs.h>
#include <World/Zone3D.h>
ARM
struct OverrideFlags { unsigned char low:3,active:1,parity:1,high:3; };
// Original: arm9/ov000 @ 0x021636AC; symbol: func_ov000_021636ac; size: 0x64.
// Applies alternate BMDJ overrides once, sets active bit3 and records the signed word's remainder parity in bit4.
// The role of the word at 0x55D8 remains unknown.
extern "C" void ApplyZoneOverridesAndRecordParity(unsigned char* self) {
 if(((OverrideFlags*)(self+0x5951))->active)return;
 ((Zone3D*)(self+0xec8))->ApplyBMDJFlag4Overrides(true);
 ((OverrideFlags*)(self+0x5951))->active=1;
 ((OverrideFlags*)(self+0x5951))->parity=(unsigned char)(*(int*)(self+0x55d8)%2);
}
