// Original data: arm9/main @ 0x2111638; symbol: data_02111638.
// Timer-0 overflow accounting and deferred counter reload state, represented by Timer64Bit. Initially zero; runtime fields are mutable.
#include "System/Timing.h"

// Timer-0 overflow accounting and deferred counter reload state.
Timer64Bit OS_TimerState;
typedef char Timer64BitSizeCheck[sizeof(Timer64Bit) == 16 ? 1 : -1];
