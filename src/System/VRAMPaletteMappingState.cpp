#include "System/VRAMMappingState.h"

ExtPaletteMappingData LoadToMainBGExtendedPalette_UnknownRoleZeroInitializedStorage;

typedef char ExtPaletteMappingDataSizeCheck[sizeof(ExtPaletteMappingData) == 28 ? 1 : -1];
