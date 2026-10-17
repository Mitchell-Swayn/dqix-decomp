#include <globaldefs.h>
#include "Resource/Script.h"
struct State
{
    unsigned char flags,pad;
    unsigned short overrideValue;
    unsigned first,second;
    int overrideEnabled;
};
extern "C" State data_02109d94;
extern "C" void AllocateTwelveByteEntriesAndPackedBitset(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020A10CC; symbol: func_020a10cc; size: 0xB4.
extern "C" ARM int Script_SumSelectedFourHalfwordParameters(Script::Parameter* p)
{
    unsigned short result=0;
    unsigned short a=p[0].ToInt();
    unsigned short b=p[1].ToInt();
    unsigned short c=p[2].ToInt();
    unsigned short d=p[3].ToInt();
    unsigned flags=data_02109d94.flags;
    if(flags&1)result+=a;
    if(flags&2)result+=b;
    if(flags&4)result+=c;
    if(flags&8)result+=d;
    if(data_02109d94.overrideEnabled&&data_02109d94.overrideValue)result=data_02109d94.overrideValue;
    AllocateTwelveByteEntriesAndPackedBitset(data_02109d94.first,data_02109d94.second,result);
    return 1;
}
