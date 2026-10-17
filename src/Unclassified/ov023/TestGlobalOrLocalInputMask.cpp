#include <globaldefs.h>
extern "C" {
extern char data_02114e30[],data_02114e54[],data_02108760[];
int Object_TestNewlySetHalfwordMask(void*,int);
int TestSelectedRecordReadyAndByteFlagBitOne(void*,int);
}

// Original: arm9/ov023 @ 0x021E6DE4; symbol: func_ov023_021e6de4; size: 0x3C.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM bool TestGlobalOrLocalInputMask(char* p)
{
    int a=Object_TestNewlySetHalfwordMask(data_02114e30,0x601);
    int b=TestSelectedRecordReadyAndByteFlagBitOne(p+0xac,0x14);
    return (a|b)!=0;
}
