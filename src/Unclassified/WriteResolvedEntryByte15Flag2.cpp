#include <globaldefs.h>
ARM
extern "C" unsigned char* FindNonnegativeKeyInCountedRecordArray(void*,int);
// Original: arm9/main @ 0x02081164; symbol: func_02081164; size: 0x34.
extern "C" void WriteResolvedEntryByte15Flag2(unsigned char* p,int key,int enabled){unsigned char* q=FindNonnegativeKeyInCountedRecordArray(p+12,key);if(!q)return;if(enabled)q[21]|=2;else q[21]&=~2;}
