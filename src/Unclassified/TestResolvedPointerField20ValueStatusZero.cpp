#include <globaldefs.h>
extern "C" int func_02067fec(unsigned*,unsigned,unsigned);
// Original: arm9/main @ 0x02068ABC; symbol: func_02068abc; size: 0x30.
extern "C" ARM bool TestResolvedPointerField20ValueStatusZero(unsigned ignored,char* p,unsigned context)
{
    unsigned* value=*(unsigned**)(p+32);
    if(value)
    {
        return func_02067fec(value,*value,context)==0;
    }return false;
}
