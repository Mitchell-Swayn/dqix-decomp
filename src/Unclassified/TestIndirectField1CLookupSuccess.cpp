#include <globaldefs.h>
extern "C" int func_02067fec(unsigned*,unsigned,unsigned);
// Original: arm9/main @ 0x02068A8C; symbol: func_02068a8c; size: 0x30.
extern "C" ARM bool TestIndirectField1CLookupSuccess(unsigned ignored,char* p,unsigned context)
{
    unsigned* value=*(unsigned**)(p+28);
    if(value)
    {
        return func_02067fec(value,*value,context)==0;
    }return false;
}
