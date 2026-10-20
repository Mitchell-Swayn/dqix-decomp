#include <globaldefs.h>
ARM
extern "C" int GameState_CopyAlchemyOperationCount(void *dest);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021E9ECC; symbol: func_ov023_021e9ecc; size: 0x34.
extern "C" int Script_ReadAlchemyOperationCount(void *out) {
    int value = 0;
    GameState_CopyAlchemyOperationCount(&value);
    Script_WriteIntegerReferenceOutput(out, value);
    return 1;
}
