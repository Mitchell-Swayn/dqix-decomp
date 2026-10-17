#include <globaldefs.h>
ARM
struct CountRecord { short field; short id; unsigned char field4; unsigned char count; };
extern "C" CountRecord* data_ov004_021707c0;
// Original: arm9/ov004 @ 0x021537E0; symbol: func_ov004_021537e0; size: 0x80.
extern "C" short SumFirstRecordCountsForTwelveIds() {
 short total=0;
 short id=0;
 CountRecord* found;
 CountRecord* table;
 for(;id<=11;id++) {
 unsigned char i=0;
 table=data_ov004_021707c0;
 for(;i<20;i++) {
 found=&table[i];
 if(found->id==id) goto found_record;
 }
 found=0;
 found_record:
 if(found) total+=found->count;
 }
 return total;
}
