#include "System/Timing.h"

// Timer-0 overflow accounting and deferred counter reload state.
Timer64Bit data_02111638;
typedef char Timer64BitSizeCheck[sizeof(Timer64Bit) == 16 ? 1 : -1];
