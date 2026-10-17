#include <globaldefs.h>
ARM
extern "C" void SetFlagOneForEachListedId(char *, int);
extern "C" void Object_ApplyModeOneToSelectedPartGroup(unsigned char *, int);
extern "C" int Object_CreateAndConfigureSelectedDisplayPart(char *, int);
// Original: arm9/ov017 @ 0x021AB060; symbol: func_ov017_021ab060; size: 0x60.
extern "C" void ApplySelectedPartModesByObjectType(void *self) {
    short mode = 2;
    if (*(short *)((unsigned char *)self + 0x4c) == 1) mode = 5;
    unsigned char *object = *(unsigned char **)((unsigned char *)self + 0x18);
    SetFlagOneForEachListedId((char *)object, 1);
    for (int i = 0; i < 3; ++i) {
        Object_ApplyModeOneToSelectedPartGroup(object, mode);
        mode = (short)(mode + 1);
    }
    Object_CreateAndConfigureSelectedDisplayPart((char *)object, 1);
}
