#include <globaldefs.h>
ARM
extern "C" int Network_QueueOutgoingRecord(...);
extern "C" int Network_GetCommandRecordPool(...);
extern "C" void* memset(void*,int,unsigned);extern "C" void* memcpy(void*,const void*,unsigned);
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov017 @ 0x021CD35C; symbol: EmitType104PacketsForSixByteEntries; size: 0xc8.
extern "C" void Combat_QueuePendingRequestEntries(unsigned key,char* entries,int count,unsigned char lastFlag){
int sentinel;int last;void* queue=(void*)Network_GetCommandRecordPool();char packet[20];B(packet,0)=104;char* fields=packet+4;H(fields,0)=key;if(count){int i=0;last=count;last-=1;sentinel=-1;for(;i<count;i++,entries+=6){H(fields,2)=H(entries,0);struct Key{unsigned short value:15;unsigned short flag:1;};H(fields,4)=((Key*)(entries+2))->value;B(fields,7)=B(entries,4);B(fields,8)=*(signed char*)(entries+5);if(i==last)B(fields,6)=lastFlag;else *(signed char*)(fields+6)=sentinel;Network_QueueOutgoingRecord(queue,packet,0);}}else{H(fields,2)=0;H(fields,4)=0;B(fields,6)=0;*(signed char*)(fields+8)=-1;Network_QueueOutgoingRecord(queue,packet,0);}
}
