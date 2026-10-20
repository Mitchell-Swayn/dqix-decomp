#include <globaldefs.h>
ARM
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov025 @ 0x021ED444; symbol: InsertPrioritizedRecordIntoParallelFieldArrays.
extern "C" int Combat_InsertPriorityActionMessage(char*self,unsigned short id,short key,int mode,void*value,short argument,unsigned short flags){
struct Arrays{unsigned short ids[16];short keys[16],arguments[16],sequence[16];unsigned short flags[16];unsigned char modes[16];char*values[16];char pad[96];unsigned char count,pad1;short counter;char pad2[8];short insertion;};Arrays*arrays=(Arrays*)self;if(mode>=6)return -1;int result=-1;if(id&&arrays->count<16){int insertion=arrays->insertion;for(int i=arrays->count-1;i>=insertion;i--){arrays->ids[i+1]=arrays->ids[i];arrays->keys[i+1]=arrays->keys[i];arrays->modes[i+1]=arrays->modes[i];arrays->values[i+1]=arrays->values[i];arrays->sequence[i+1]=arrays->sequence[i];arrays->arguments[i+1]=arrays->arguments[i];arrays->flags[i+1]=arrays->flags[i];}H(self,insertion*2)=id;S(self+insertion*2,32)=key;B(self+insertion,160)=mode;P(self+insertion*4,176)=(char*)value;if(arrays->counter==32767)arrays->counter=0;arrays->counter++;result=arrays->counter;S(self+insertion*2,96)=result;S(self+insertion*2,64)=argument;H(self+insertion*2,128)=flags;arrays->count++;}return result;
}
