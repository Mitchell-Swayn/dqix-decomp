#include <globaldefs.h>
#include <Filesystem/CardReadManager.h>
#include <Filesystem/FileAccessor.h>
ARM
#pragma optimization_level 4
extern "C" void Vector3i_ClearThreeWords(void*);
// Original callee argument/return behavior and named SDK declaration reviewed.
// Original: arm9/main @ 0x0205E180; symbol: func_0205e180; size: 0xC.
extern "C" void ClearThreeWordsIndirect(void* a){Vector3i_ClearThreeWords(a);}
