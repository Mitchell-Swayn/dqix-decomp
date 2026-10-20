#include <globaldefs.h>
ARM
#pragma optimization_level 2
extern "C" void* memset(void*, int, unsigned int);
extern "C" void InitializeIndexedThreePartRecords(void *context);
// Original: arm9/ov001 @ 0x021575EC; symbol: func_ov001_021575ec; size: 0x7C.
// Clears paired arrays of sixteen 12-byte records and initializes two indexed groups.
extern "C" void InitializePairedRecordGroups(void *context) {
 char *p = (char*)context;
 for (int i=0;i<16;++i) {
  int offset=i*12;
  memset(p+offset,0,12);
  memset(p+0xc0+offset,0,12);
 }
 *(int*)(p+0x180)=0;
 *(int*)(p+0x8c0)=0;
 *(int*)(p+0x184)=0;
 InitializeIndexedThreePartRecords(p+0x188);
 InitializeIndexedThreePartRecords(p+0x524);
}
