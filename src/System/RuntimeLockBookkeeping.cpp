#include "System/RuntimeState.h"

// Nine owner/count slots; exit uses slot 0, signal dispatch uses slot 7.
unsigned int RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage[9];
unsigned int RuntimeDispatchSignalHandler_UnknownRoleZeroInitializedStorage_Variant2[9];
