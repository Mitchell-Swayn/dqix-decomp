#include <globaldefs.h>
extern "C" int func_02067fec(unsigned*,unsigned,unsigned);
// Original: arm9/main @ 0x02068AEC; symbol: func_02068aec; size: 0x30.
extern "C" ARM bool Object_TestNestedOffset28StatsPredicate(unsigned ignored,char* p,unsigned context)
{
    unsigned* value=*(unsigned**)(p+40);
    if(value)
    {
        return func_02067fec(value,*value,context)==0;
    }return false;
}
