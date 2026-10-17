#include <globaldefs.h>
ARM
extern "C" unsigned char* FindNonnegativeKeyInCountedRecordArray(void*,int);extern "C" unsigned char* FindNonnegativeKeyInEntryArray(void*,int);
// Original: arm9/main @ 0x020804FC; symbol: func_020804fc; size: 0x5C.
extern "C" void Object_ClearBit4OnReferencedGroupParts(unsigned char* p,int key){unsigned char* q=FindNonnegativeKeyInCountedRecordArray(p+12,key);if(!q)return;for(unsigned char i=0;i<q[19];++i){short id=(*(short**)q)[i];unsigned char* entry=FindNonnegativeKeyInEntryArray(p+4,id);if(entry)entry[42]&=~4;}}
