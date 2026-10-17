#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void ClearLinkedByteFlagBitZeroAndSetBitOne(void *);void CopyStateByteAndInvalidatePreviousSelector(void *);
// Original: arm9/main @ 0x020E25E8; symbol: func_020e25e8; size: 0x1C.
void SetLinkedFlagStateAndResetOwner(void **p){ClearLinkedByteFlagBitZeroAndSetBitOne(p[4]);CopyStateByteAndInvalidatePreviousSelector(p);}
}
