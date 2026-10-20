#include <globaldefs.h>
#include <std_library_functions.h>
struct Record { unsigned char a,b; unsigned short pad; unsigned payload[4]; };
// Original: arm9/main @ 0x0205E3EC; symbol: func_0205e3ec; size: 0x30.
extern "C" ARM Record* Network_CopyMessageTypeAndPayload(Record* dst,const Record* src) {dst->a=src->a;dst->b=src->b;COPY_ARRAY(dst->payload,src->payload);return dst;}
