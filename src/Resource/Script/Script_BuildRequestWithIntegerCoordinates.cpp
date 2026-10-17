#include <globaldefs.h>
#include <Resource/Script.h>
struct Request{unsigned char a,b;short pad;short x,y,z;char tail[6];};extern "C" void ClearFourLeadingBytesAndWordAtOffsetC(Request*);extern "C" void* data_020fdd30;extern "C" void AppendEightFieldRecordWithinCapacity(void*,Request*);
// Original: arm9/main @ 0x02027CE4; symbol: func_02027ce4; size: 0xB0.
extern "C" ARM int Script_BuildRequestWithIntegerCoordinates(Script::Parameter* p){Request r;ClearFourLeadingBytesAndWordAtOffsetC(&r);r.a=p[0].ToInt();r.b=p[1].ToInt();r.x=((int)(4096.f*p[2].ToFloat()))>>12;r.y=((int)(4096.f*p[3].ToFloat()))>>12;r.z=((int)(4096.f*p[4].ToFloat()))>>12;AppendEightFieldRecordWithinCapacity(data_020fdd30,&r);return 1;}
