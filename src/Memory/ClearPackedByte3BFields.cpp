// Field widths/callee contracts reviewed against original ARM; hardware MMIO addresses retained.
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
extern "C" { int BackgroundLoader_CancelTaskAndResetCountAndValue(void*);void ClearRecordAndInvalidateTwoIndices(void*);void** Object_ReadInitialOptionalResourceWord(void*);void InitializeTag4DRecordAndTwoIndexSentinels(void*);void* Object_GetValidSixtyByteEntry(void*,int); }
struct Bits{unsigned char a:1,b:1,c:1,d:5;};struct Block{unsigned words[12];};
// Original: arm9/main @ 0x0208979C; symbol: func_0208979c; size: 0x18.
extern "C" void ClearPackedByte3BFields(char* p){((Bits*)(p+59))->a=0;((Bits*)(p+59))->c=0;}
