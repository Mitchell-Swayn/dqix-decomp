#include "Filesystem/FSInnerDefs.h"

#if defined(usa)
typedef char CardSharedDataSizeCheck[sizeof(Arm7CardReadData) == 0x60 ? 1 : -1];

// Existing read/initialization code establishes the context, stack and scratch
// ranges. Fields whose roles are not established remain explicitly unknown.
Arm7CardReadData data_02111880;
#endif
