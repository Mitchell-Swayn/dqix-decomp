#include <globaldefs.h>
ARM
extern "C" void ReleaseIndexedRecordAndInvalidateIndex(unsigned char*);
extern "C" unsigned char* FindFourSlotRecordByIndex(unsigned char*,int);
struct IndexedRecord { unsigned char bytes[24]; };
// Original: arm9/ov000 @ 0x02181608; symbol: func_ov000_02181608; size: 0x8C.
extern "C" void Resource_ReleaseObjectIndexedRecords(unsigned char* p) {
for(int i=0;i<4;++i) {
unsigned char* slot=FindFourSlotRecordByIndex(p,i);
if(slot) ReleaseIndexedRecordAndInvalidateIndex(slot+0x50);
}
IndexedRecord* a=(IndexedRecord*)(p+0x1b0c);
for(int i=0;i<3;++i) ReleaseIndexedRecordAndInvalidateIndex((unsigned char*)&a[i]);
IndexedRecord* b=(IndexedRecord*)(p+0x1c5c);
for(int i=0;i<8;++i) ReleaseIndexedRecordAndInvalidateIndex((unsigned char*)&b[i]);
}
