#include <globaldefs.h>
ARM
extern "C" int Network_ReceiveQueuedDatagram(void*,int,int,int,int,int);
extern "C" int Network_ReceiveStreamWithOptionalWait(void*,int,int,int,int,int);
extern "C" void Network_ScheduleConsumedReceiveRelease(void*);
// Original: arm9/ov031 @ 0x02205A38; symbol: DispatchWithTemporaryLinkedByteFlag; size: 0x9c.
// Temporarily sets linked signed byteFE for flag2, dispatches by byte73, restores linked byte.
extern "C" int Network_DispatchSocketReceiveWithPeek(char* p,int a,int b,int c,int d,int e,unsigned flags){
 char* linked=*(char**)(p+0x64);int temporary=(flags&2)&&linked;int saved;
 if(temporary){saved=*(signed char*)(linked+0xfe);*(signed char*)(linked+0xfe)=1;}
 int result;if(*(signed char*)(p+0x73)==1)result=Network_ReceiveQueuedDatagram(p,a,b,c,d,e);
 else{result=Network_ReceiveStreamWithOptionalWait(p,a,b,c,d,e);if(result>=0)Network_ScheduleConsumedReceiveRelease(p);}
 if(temporary)*(signed char*)(linked+0xfe)=saved;return result;
}
