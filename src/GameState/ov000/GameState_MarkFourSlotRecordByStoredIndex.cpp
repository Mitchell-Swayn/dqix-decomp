#include <globaldefs.h>
ARM
extern "C" char* FindFourSlotRecordByIndex(void*,int);
// Original: arm9/ov000 @ 0x0218142C; symbol: func_ov000_0218142c; size: 0x90.
extern "C" void GameState_MarkFourSlotRecordByStoredIndex(void* self,int index) {
 if(index<0) {
  for(int i=0;i<4;i++) {
   char* record=FindFourSlotRecordByIndex(self,i);
   if(record) (record+*(signed char*)(record+0x18))[0x10]=0x66;
  }
 } else {
  for(int i=0;i<4;i++) {
   char* record=FindFourSlotRecordByIndex(self,i);
   if(record && index==*(int*)(record+0x4c)) {
    (record+*(signed char*)(record+0x18))[0x10]=0x66;
    return;
   }
  }
 }
}
