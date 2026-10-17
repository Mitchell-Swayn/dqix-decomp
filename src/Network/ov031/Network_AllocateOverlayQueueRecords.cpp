#include <globaldefs.h>
ARM
extern "C" void InitializeEightWordQueueStateWithTwoParameters(int*,int,int);
extern "C" void SendMessageToOverlayQueueIfArgumentPresent(void*);
extern "C" char* data_ov031_022496a4;
extern "C" int data_ov031_0224e204[];
extern "C" char* data_ov031_0224e200;
// Original: arm9/ov031 @ 0x02205030; symbol: func_ov031_02205030; size: 0x94.
extern "C" int Network_AllocateOverlayQueueRecords(int count) {
unsigned indexBytes=(count*4+3)&~3;
unsigned recordBytes=(count*0x2c+3)&~3;
char* block=(*(char*(**)(unsigned))(data_ov031_022496a4+0x18))(recordBytes+indexBytes);
if(!block) return -1;
InitializeEightWordQueueStateWithTwoParameters(data_ov031_0224e204,(int)block,count);
char* record=block+indexBytes;
if(count>0) do {
SendMessageToOverlayQueueIfArgumentPresent(record);
--count;
record+=0x2c;
} while(count>0);
data_ov031_0224e200=block;
return 0;
}
