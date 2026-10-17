#include <globaldefs.h>
extern "C" {
void FillSixWordsWithMinusOne(void *);
// Original: arm9/main @ 0x020A1FFC; symbol: func_020a1ffc; size: 0x14.
void *FillSixWordsWithMinusOneAndReturnPointer(void *p){FillSixWordsWithMinusOne(p);return p;}
}
