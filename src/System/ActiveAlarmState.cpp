#include "System/Timing.h"

// Initialization flag and first/last links for the time-ordered alarm queue.
ActiveAlarmList data_02111648;
typedef char ActiveAlarmListSizeCheck[sizeof(ActiveAlarmList) == 12 ? 1 : -1];
