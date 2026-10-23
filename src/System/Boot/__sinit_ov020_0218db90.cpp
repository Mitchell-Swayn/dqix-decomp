#include <globaldefs.h>
extern "C" char* SinitOv0200218Db90_UnknownRoleDataReferences[];
#pragma define_section init ".init" RX
#pragma force_active on
// Original: arm9/ov020 @ 0x0218DB90; symbol: __sinit_ov020_0218db90; size: 0x18.
extern "C" __declspec(section "init") ARM void __sinit_ov020_0218db90()
{
    SinitOv0200218Db90_UnknownRoleDataReferences[0]=SinitOv0200218Db90_UnknownRoleDataReferences[1]+11;
}
#pragma force_active off
