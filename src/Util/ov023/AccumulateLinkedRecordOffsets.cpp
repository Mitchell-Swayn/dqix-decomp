#include <globaldefs.h>
ARM
extern "C" char* FindTwentyFourByteRecordBySignedKey(char*,int);
// Original: arm9/ov023 @ 0x021E2ACC; symbol: func_ov023_021e2acc; size: 0x90.
extern "C" void AccumulateLinkedRecordOffsets(char* owner,int key,short* x,short* y){
char* record=FindTwentyFourByteRecordBySignedKey(owner,key);
*x+=*(short*)(record+8);*y+=*(short*)(record+10);
while(record){
int next=*(short*)(record+16);
if(next>0){record=FindTwentyFourByteRecordBySignedKey(owner,next);}
else{
next=*(short*)(record+12);
if(next<0)return;
record=FindTwentyFourByteRecordBySignedKey(owner,next);
if(!record)return;
AccumulateLinkedRecordOffsets(owner,*(short*)record,x,y);
return;
}
}
}
