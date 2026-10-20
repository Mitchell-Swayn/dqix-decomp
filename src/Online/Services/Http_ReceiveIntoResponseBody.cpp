#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" int Http_IsResponseBodyOffsetAtCapacity(void*,unsigned);
extern "C" int Http_ReceiveSocketBytes(void*,int,int,int,int);
// Original: arm9/ov031 @ 0x02240820; symbol: func_ov031_02240820; size: 0x70.
// Rejects an out-of-bounds offset and forwards a range capped by the record's remaining length.
extern "C" int Http_ReceiveIntoResponseBody(unsigned char* self,int destination,int offset,int length,int extra) {
 unsigned char* record=*(unsigned char**)(self+0x30);
 if(Http_IsResponseBodyOffsetAtCapacity(record,offset))return -1003;
 int remaining=*(int*)(record+12)-offset;
 if(length<=remaining)remaining=length;
 return Http_ReceiveSocketBytes(self,destination,*(int*)(record+24)+offset,remaining,extra);
}
