#include <globaldefs.h>
ARM
extern "C" void PartyMenu_CopySelectableMemberIndices(void *, unsigned int *);
// Original: arm9/ov002 @ 0x021574D4; symbol: func_ov002_021574d4; size: 0x2C.
extern "C" int PartyMenu_GetSelectableMemberIndex(void *data, int index) {
    if (index < 0)
        return -1;
    unsigned int fields[4];
    PartyMenu_CopySelectableMemberIndices(data, fields);
    return (int)fields[index];
}
