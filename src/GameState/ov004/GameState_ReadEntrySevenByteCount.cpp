#include <globaldefs.h>
ARM
extern "C" short* Util_FindRecordBySignedId(short*, int);
extern "C" short* data_ov004_021707c0;
// Original: arm9/ov004 @ 0x021538F0; symbol: func_ov004_021538f0; size: 0x54.
extern "C" int GameState_ReadEntrySevenByteCount(void) {
    short result = 0;
    short index = 7;
    while (index <= 7) {
        short* record = Util_FindRecordBySignedId(data_ov004_021707c0, index);
        if (record) result = (short)(result + ((unsigned char*)record)[5]);
        index = (short)(index + 1);
    }
    return result;
}
