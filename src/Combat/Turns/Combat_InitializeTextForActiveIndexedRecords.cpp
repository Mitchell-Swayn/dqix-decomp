#include <globaldefs.h>
ARM
#pragma opt_propagation off
extern "C" void Resource_InitializeTextCommandState(unsigned char*);
struct Record {unsigned char bytes[0x448];};
// Original: arm9/ov000 @ 0x02180394; symbol: func_ov000_02180394; size: 0x70.
// Visits four signed record indices and initializes text commands for records
// whose state at 0x4C is 0..3 and whose byte at 0x87 is nonzero.
extern "C" void Combat_InitializeTextForActiveIndexedRecords(unsigned char* self) {
 Record* records;
 int i=0;
 for(;i<4;++i){
  records=(Record*)(self+0x958);
  unsigned char* record=records[*(signed char*)(self+0x6c+i)].bytes;
  int valid=0;
  int state=*(int*)(record+0x4c);
  if(state>=0 && state<=3)valid=1;
  if(valid && record[0x87])Resource_InitializeTextCommandState(record);
 }
}
