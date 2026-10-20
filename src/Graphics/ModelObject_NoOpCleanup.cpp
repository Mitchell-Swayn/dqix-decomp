#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x02047198; symbol: func_02047198; size: 0x4.
// Empty cleanup hook for a model object. The sole direct caller invokes it
// with an embedded object immediately before ReleaseOptionalAllocatorAndClearState.
// The exact object class and original member name are unestablished.
extern "C" void ModelObject_NoOpCleanup(void* object)
{
}
