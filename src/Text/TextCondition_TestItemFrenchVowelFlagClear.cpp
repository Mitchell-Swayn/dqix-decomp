#include <globaldefs.h>
extern "C" int TextLookup_TestFrenchVowelInitial(unsigned*,unsigned,unsigned);
// Original: arm9/main @ 0x02068A5C; symbol: func_02068a5c; size: 0x30.
extern "C" ARM bool TextCondition_TestItemFrenchVowelFlagClear(unsigned ignored,char* p,unsigned context)
{
    unsigned* value=*(unsigned**)(p+24);
    if(value)
    {
        return TextLookup_TestFrenchVowelInitial(value,*value,context)==0;
    }return false;
}
