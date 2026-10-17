#include "globaldefs.h"
#pragma optimize_for_size off
ARM
struct Entry{int words[13];};extern "C" void ClearRecordAndInitializeInvalidIndices(Entry*);extern "C" void Object_CopyBytesToBytesAndCopyAToAAndCopyBToBAndCopyCToC(Entry*,Entry*);
// Original: arm9/main @ 0x02093AD8; symbol: func_02093ad8; size: 0x7C.
extern "C" void MoveCountedEntriesAndResetEightSourceAndDestinationSlots(void*,Entry*src,Entry*dst,int count){for(int i=0;i<8;i++)ClearRecordAndInitializeInvalidIndices(dst+i);for(int i=0;i<count;i++)Object_CopyBytesToBytesAndCopyAToAAndCopyBToBAndCopyCToC(dst+i,src+i);for(int i=0;i<8;i++)ClearRecordAndInitializeInvalidIndices(src+i);}
