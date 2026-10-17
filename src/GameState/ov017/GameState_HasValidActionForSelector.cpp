#include <globaldefs.h>
ARM
extern "C" unsigned func_ov017_02191b58(void* object);
// Original: arm9/ov017 @ 0x021922AC; symbol: func_ov017_021922ac; size: 0x60.
extern "C" int GameState_HasValidActionForSelector(unsigned char* object, int selector) {
    int result = 0;
    if (object[0x4489] == 0)
        goto set_true;
    int allowed = (unsigned)selector <= 3 ? 1 : result;
    if (allowed == 0)
        goto final_check;
    if ((func_ov017_02191b58(object) & 2) != 0)
        result = 1;
    goto final_check;
set_true:
    result = 1;
final_check:
    if (object[0x4488] == 0)
        result = 0;
    return result;
}
