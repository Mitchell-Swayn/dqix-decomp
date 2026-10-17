#include <globaldefs.h>
ARM
extern "C" void InitializeEmbeddedDisplayRecords(void*);extern "C" void ResetEmbeddedResourceAndRecord(void*);extern "C" void ResetRecordAndIndexedEntries(void*);
// Original: arm9/main @ 0x0205D048; symbol: func_0205d048; size: 0x98.
extern "C" void CleanupTwoRecordArraysAndClearOwnerPointers(unsigned char* p){InitializeEmbeddedDisplayRecords(p);if(*(void**)(p+156)&&p[179]){unsigned i=0;while(i<p[179]){ResetEmbeddedResourceAndRecord(*(unsigned char**)(p+156)+i*224);i=(i+1)&255;}}if(*(void**)(p+152)){unsigned i=0;while(i<p[178]){ResetRecordAndIndexedEntries(*(unsigned char**)(p+152)+i*32);i=(i+1)&255;}}*(void**)(p+152)=0;*(void**)(p+156)=0;p[179]=0;p[180]=0;}
