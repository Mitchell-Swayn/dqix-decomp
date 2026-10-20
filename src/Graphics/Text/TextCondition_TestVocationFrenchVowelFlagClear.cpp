#include <globaldefs.h>
extern "C" int TextLookup_TestFrenchVowelInitial(unsigned*,unsigned,unsigned);
// Original: arm9/main @ 0x02068AEC; symbol: func_02068aec; size: 0x30.
extern "C" ARM bool TextCondition_TestVocationFrenchVowelFlagClear(unsigned ignored,char* p,unsigned context)
{
    unsigned* value=*(unsigned**)(p+40);
    if(value)
    {
        return TextLookup_TestFrenchVowelInitial(value,*value,context)==0;
    }return false;
}
