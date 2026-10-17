#include <globaldefs.h>
extern "C" void* memset(void*,int,unsigned int);
// Original: arm9/ov000 @ 0x0215E958; symbol: func_ov000_0215e958; size: 0x60.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM void* ClearCurrentIndexedRecord(unsigned char* p) {
 int index=p[0x8e02]; if(index>=360) return 0;
 unsigned char* entry=p+0x21e0+index*36;
 memset(entry,0,32); *(unsigned int*)(entry+32)=0;
 return p+0x21e0+p[0x8e02]*36;
}
