#include <globaldefs.h>
ARM
extern "C" int ReadSignedByteAtStoredIndex(void*);
// Original: arm9/ov000 @ 0x021751AC; symbol: func_ov000_021751ac; size: 0xAC.
extern "C" void GameState_ResetFlaggedEntriesOutsideSelectedOwner(unsigned char* p){
 unsigned char* entry;
 int selected=ReadSignedByteAtStoredIndex(p);
 for(signed char i=0;i<4;i++){
 entry=p+0x958+*(signed char*)(p+i+0x6c)*0x448;
 if((int)(selected>=0 && selected<=3)!=0 && selected==*(int*)(entry+0x4c))continue;
 if(*(unsigned*)(entry+0x28)&1){
 *(unsigned char*)(entry+*(signed char*)(entry+0x18)+0x10)=100;
 entry[0x24]&=~4;
 entry[0x24]&=~1;
 }
 }
}
