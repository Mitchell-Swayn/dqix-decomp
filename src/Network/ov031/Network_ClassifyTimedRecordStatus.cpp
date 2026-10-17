#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
unsigned long long _Z19GetCurrentTimestampv();
int RuntimeMemory_CompareByteRanges(const void*,const void*,unsigned);
void func_ov031_0223e2c0(unsigned,unsigned);
extern unsigned char* data_ov031_02290d0c;
extern const unsigned char data_ov031_02249280[];
}
typedef void (*StatusCallback)(int);
// Original: arm9/ov031 @ 0x022379F0; symbol: func_ov031_022379f0; size: 0x13C.
extern "C" void Network_ClassifyTimedRecordStatus(unsigned argument) {
 volatile unsigned saved=argument;
 unsigned long long now=_Z19GetCurrentTimestampv();
 unsigned char* p=data_ov031_02290d0c;
 int i,nonzero,zero;
 unsigned char *keys,*scan;
 zero=0;
 if(now<*(unsigned long long*)(p+0x1b88)+0x17f898ULL) return;
 nonzero=zero;
 i=0;
 scan=p;
 keys=p+0x1300;
 for(;i<16;i++,keys+=7,scan+=7) {
  if(RuntimeMemory_CompareByteRanges(keys,data_ov031_02249280,6)!=0) {
   if(scan[0x1306]) nonzero=1;
   else zero=1;
  }
 }
 if(nonzero && zero) {
  StatusCallback callback=*(StatusCallback*)(p+0x1370);
  if(callback) callback(2);
 } else if(nonzero) {
  StatusCallback callback=*(StatusCallback*)(p+0x1370);
  if(callback) callback(1);
 } else if(!zero) {
  StatusCallback callback=*(StatusCallback*)(p+0x1370);
  if(callback) callback(0);
 }
 *(unsigned*)(data_ov031_02290d0c+0x1b90)=0;
 data_ov031_02290d0c[0x1b96]=1;
 func_ov031_0223e2c0(0,saved);
}
