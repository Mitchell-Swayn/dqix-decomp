#include <globaldefs.h>
ARM
extern "C" void Field_QueueNameAndCacheMemberText(int, int, int);
// Original: arm9/ov017 @ 0x021B042C; symbol: func_ov017_021b042c; size: 0x64.
extern "C" int Field_WaitForPartyJoinPreparationAcknowledgments(unsigned char *self) {
    int valid = 1;
    int index = 1;
    while (index < 4) {
        char *entry = (char *)self + index;
        if (*(unsigned char *)(entry + 0x1B) == 1 && (self[0x20] & (1 << index)) == 0) {
            valid = 0;
            break;
        }
        ++index;
    }
    if (valid == 0) return self[0xA];
    Field_QueueNameAndCacheMemberText(3, 0, 0);
    return 5;
}
