#include <globaldefs.h>
ARM
extern "C" int WaitForMinimumAvailableCount(char*,int,int,unsigned*,int);
extern "C" int Network_QueueRingBufferSend(char*,char*,int,int,unsigned short,unsigned,unsigned);

#define W(p,o) (*(int*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x02206264; symbol: Network_SendAvailableChunksWithOptionalWaitForAll; size: 0x104.
extern "C" int Network_SendAvailableChunksWithOptionalWaitForAll(char* self,char* source,int size,unsigned short port,unsigned address,unsigned flags){char* limits=P(P(self,0x68),0x10c);int capacity=W(limits,72);int count;int sent=0;int minimum;if(*(signed char*)(self+0x73)==1){if(size>capacity-42)return -35;minimum=size;}else{minimum=capacity-54;if(size<=minimum)minimum=size;}if(size>0){unsigned wait=flags&1;do{unsigned offset;count=WaitForMinimumAvailableCount(self,size,minimum,&offset,flags);if(count>0){if(Network_QueueRingBufferSend(self,source,count,offset,port,address,flags)<=0)return -6;source+=count;size-=count;sent+=count;}if(!wait){if(count<=0)return -6;break;}}while(size>0);}return sent;}