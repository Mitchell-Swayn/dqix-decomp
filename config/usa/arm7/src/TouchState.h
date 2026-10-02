#ifndef ARM7_TOUCH_STATE_H
#define ARM7_TOUCH_STATE_H
#include "VerticalAlarm.h"
typedef struct {
 unsigned short slots[16];
 unsigned int operation;
 int filterThreshold,retryThreshold;
 VerticalAlarm alarms[4];
 short scanlines[4];
} TouchRequest;
typedef struct {
 unsigned char sampleCounters[2];
 unsigned short unknown2;
 TouchRequest request;
} TouchState;
typedef char TouchRequestSizeCheck[sizeof(TouchRequest)==212?1:-1];
typedef char TouchStateSizeCheck[sizeof(TouchState)==216?1:-1];
extern TouchState ARM7_TouchState;
/* This symbol denotes the actual request subobject at state offset four. */
extern TouchRequest ARM7_TouchRequest;
extern VerticalAlarm ARM7_TouchAlarms[4];
#endif
