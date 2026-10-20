#include <globaldefs.h>
ARM
extern "C" int Network_GetLocalMemberId(char *p);
extern "C" void *Zone3D_GetMainInstance();
// Original: arm9/ov017 @ 0x021D1C84; symbol: func_ov017_021d1c84; size: 0x34.
extern "C" void GameState_CopyTwoIndexedBytesWhenSignedFieldIsNonzero(void *unused, unsigned char *record, unsigned int arg3, unsigned int arg4, char *indexedField) {
    if (Network_GetLocalMemberId(indexedField) == 0) return;
    unsigned char *global = (unsigned char *)Zone3D_GetMainInstance();
    *(unsigned short *)(global + 0x27B4) = record[4];
    *(unsigned short *)(global + 0x27B6) = record[5];
}
