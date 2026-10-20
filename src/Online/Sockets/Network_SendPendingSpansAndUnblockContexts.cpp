#include <globaldefs.h>
#include <System/ProcessorContext.h>
ARM
struct Spans;
extern "C" void Resource_UpdateSelectedRecordModesFromEnableState(int,unsigned short,unsigned int);
extern "C" void WaitForPendingFlagWithTimeout(void);
extern "C" unsigned Network_ConsumeBufferedSendAndCompactRemainder(void*,unsigned);
extern "C" int Network_RoundAmountToTransferUnit(int);
extern "C" int CopyAndConsumeTwoBufferSpans(char*,int,Spans*);
#define F(T,p,o) (*(T*)((char*)(p)+(o)))
inline bool IsTransferMode(char* state){return F(signed char,state,0x73)==0 || F(signed char,state,0x73)==4;}
// Original: arm9/ov031 @ 0x02206584; symbol: func_ov031_02206584; size: 0x130.
// Consumes pending spans through the buffered sender and unblocks waiting contexts.
extern "C" int Network_SendPendingSpansAndUnblockContexts(char* request){
char* buffer;char* state=F(char*,request,4);char* owner=F(char*,state,0x68);int result=0;
if(!IsTransferMode(state) || (F(short,state,0x70)&4)){
if(F(unsigned,request,0x28))Resource_UpdateSelectedRecordModesFromEnableState(F(unsigned short,request,0x24),F(unsigned short,request,0x26),F(unsigned,request,0x28));
buffer=F(char*,state,0x4c);
int prefix=IsTransferMode(state)?54:42;
int capacity;
if(!IsTransferMode(state))capacity=F(int,state,0x48)-prefix;
else capacity=Network_RoundAmountToTransferUnit(F(int,state,0x48)-prefix);
int amount;
for(;;){
amount=CopyAndConsumeTwoBufferSpans(buffer+prefix,capacity,(Spans*)request);if(amount<=0)break;
int sent=Network_ConsumeBufferedSendAndCompactRemainder(buffer+prefix,amount);
if(sent<=0){
if(IsTransferMode(state)){F(short,state,0x70)&=~14;F(short,state,0x70)|=128;WaitForPendingFlagWithTimeout();}
result=-76;break;
}
result+=sent;
}
}else result=-76;
F(unsigned short,owner,0x102)=F(unsigned short,request,0x20);
UnblockContexts((BlockedContextList*)(owner+0x104));return result;
}
