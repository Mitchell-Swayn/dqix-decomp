#include <globaldefs.h>
extern "C" {
unsigned int *WorldScriptArray_FindEntryByKey();
// Original: arm9/main @ 0x0208DAC4; symbol: func_0208dac4; size: 0x18.
unsigned int ReadResolvedEntryWordIndex4OrZero(){unsigned int *p=WorldScriptArray_FindEntryByKey();if(p)return p[4];return 0;}
}
