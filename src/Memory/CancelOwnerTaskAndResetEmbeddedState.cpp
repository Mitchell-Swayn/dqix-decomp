// Field widths/callee contracts reviewed against original ARM; hardware MMIO addresses retained.
#include <globaldefs.h>
#include <Memory/SafeAllocator.h>
ARM
extern "C" { int BackgroundLoader_CancelTaskAndResetCountAndValue(void*);void ClearRecordAndInvalidateTwoIndices(void*);void** Object_ReadInitialOptionalResourceWord(void*);void InitializeTag4DRecordAndTwoIndexSentinels(void*);void* Object_GetValidSixtyByteEntry(void*,int); }
struct Bits{unsigned char a:1,b:1,c:1,d:5;};struct Block{unsigned words[12];};
// Original: arm9/main @ 0x020DFC6C; symbol: func_020dfc6c; size: 0x18.
extern "C" void CancelOwnerTaskAndResetEmbeddedState(void* p){BackgroundLoader_CancelTaskAndResetCountAndValue(p);ClearRecordAndInvalidateTwoIndices(p);}
