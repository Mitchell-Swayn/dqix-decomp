#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" void UntrackPreviouslyTrackedModelBones(int);
ARM
// Original: arm9/main @ 0x0204A464; symbol: func_0204a464; size: 0x24.
extern "C" void CopyNameAndInvalidateCachedIndex(int p, char *name) { strcpy((char *)(p+0x234),name); *(int *)(p+600)=-1; UntrackPreviouslyTrackedModelBones(p); }
