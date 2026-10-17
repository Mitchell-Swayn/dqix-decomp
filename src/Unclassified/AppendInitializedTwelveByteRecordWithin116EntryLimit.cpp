#include <globaldefs.h>
ARM
extern "C" void CopyTwelveByteScalarRecord(void*,int);
// Original: arm9/main @ 0x0209A55C; symbol: func_0209a55c; size: 0x38.
extern "C" void AppendInitializedTwelveByteRecordWithin116EntryLimit(unsigned char* p,int value){if(!*(void**)p)return;int index=*(int*)(p+4);if(index>=116)return;*(int*)(p+4)=index+1;CopyTwelveByteScalarRecord(*(unsigned char**)p+index*12,value);}
