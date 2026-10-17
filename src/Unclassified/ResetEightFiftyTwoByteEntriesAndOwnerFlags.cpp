#include <globaldefs.h>
extern "C" {
void ClearRecordAndInitializeInvalidIndices(void *);
// Original: arm9/main @ 0x02093A14; symbol: func_02093a14; size: 0x44.
void ResetEightFiftyTwoByteEntriesAndOwnerFlags(unsigned char *p){for(unsigned char i=0;i<8;i++)ClearRecordAndInitializeInvalidIndices(p+i*52);p[0x3cb]=0;p[0x3cd]&=~4;}
}
