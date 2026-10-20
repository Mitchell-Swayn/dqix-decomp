#include <globaldefs.h>
ARM
struct CountRecord { short field; short id; unsigned char field4; unsigned char count; };
// Original data: arm9/ov004 @ 0x21707c0; symbol: data_ov004_021707c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" CountRecord* SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov004 @ 0x021537E0; symbol: func_ov004_021537e0; size: 0x80.
extern "C" short Menu_SumCompletedSubtypeCounts() {
 short total=0;
 short id=0;
 CountRecord* found;
 CountRecord* table;
 for(;id<=11;id++) {
 unsigned char i=0;
 table=SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage;
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
