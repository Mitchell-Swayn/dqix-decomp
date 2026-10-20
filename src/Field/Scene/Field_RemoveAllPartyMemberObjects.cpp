#include <globaldefs.h>
ARM
extern "C" void Field_RemovePartyMemberAndEquipment(void *, int);
// Original: arm9/ov017 @ 0x02190238; symbol: func_ov017_02190238; size: 0x2C.
extern "C" void Field_RemoveAllPartyMemberObjects(void *object) {
    for (int index = 0; index < 4; ++index)
        Field_RemovePartyMemberAndEquipment(object, index);
}
