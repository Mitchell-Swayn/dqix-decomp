#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" unsigned Allocator_DuplicateTerminatedString(unsigned,unsigned);
struct Counter
{
    unsigned short pad;
    unsigned short count:15;
    unsigned short flag:1;
};
// Original: arm9/main @ 0x020DF618; symbol: func_020df618; size: 0xB4.
extern "C" ARM int ZoneSerializedRecord_DeepCopyWithAllocator(unsigned owner,Counter* count,unsigned* out,unsigned* cursor,unsigned ignored,unsigned* source)
{
    memcpy(out,source,32);
    out[1]=source[1]?Allocator_DuplicateTerminatedString(owner,source[1]):0;
    out[0]=0;
    unsigned destination;
    if(source[0]&&(destination=*cursor))
    {
        out[0]=destination;
        *cursor=destination+32;
        memcpy((void*)out[0],(void*)source[0],32);
        ++count->count;
    }return 1;
}
