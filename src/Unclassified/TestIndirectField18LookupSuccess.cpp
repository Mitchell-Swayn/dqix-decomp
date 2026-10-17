#include <globaldefs.h>
extern "C" int TextLookup_TestRecordOrTokenBitFlag(unsigned*,unsigned,unsigned);
// Original: arm9/main @ 0x02068C6C; symbol: func_02068c6c; size: 0x30.
extern "C" ARM bool TestIndirectField18LookupSuccess(unsigned ignored,char* p,unsigned context)
{
    unsigned* value=*(unsigned**)(p+24);
    if(value)
    {
        return TextLookup_TestRecordOrTokenBitFlag(value,*value,context)==0;
    }return false;
}
