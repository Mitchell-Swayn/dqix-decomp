#include <globaldefs.h>
ARM
struct Record { unsigned id; float score; unsigned value; };
extern "C" void* memcpy(void*,const void*,unsigned);
// Original: arm9/ov024 @ 0x021F6830; symbol: func_ov024_021f6830; size: 0x98.
extern "C" void Math_InsertScoredRecordIntoFourSlots(Record* records,Record* candidate) {
 if(candidate->score<records[3].score) return;
 for(int i=0;i<4;++i) {
  if(candidate->score>records[i].score) {
   for(int j=2;j>=i;--j) memcpy(records+(i+1),records+i,12);
   memcpy(records+i,candidate,12);
   return;
  }
 }
}
