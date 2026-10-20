#include "System/VRAMMappingState.h"

TextureMappingData LoadClearImage_UnknownRoleZeroInitializedStorage;

typedef char TextureMappingDataSizeCheck[sizeof(TextureMappingData) == 32 ? 1 : -1];
