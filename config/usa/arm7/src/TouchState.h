#ifndef ARM7_TOUCH_STATE_H
#define ARM7_TOUCH_STATE_H
typedef struct {unsigned short slots[16];} TouchRequest;
typedef struct {
 unsigned char sampleCounters[2];
 unsigned short unknown2;
 TouchRequest request;
 unsigned int operation,filterThreshold,retryThreshold;
} TouchState;
typedef char TouchStateSizeCheck[sizeof(TouchState)==48?1:-1];
extern TouchState ARM7_TouchState;
/* This symbol denotes the actual request subobject at state offset four. */
extern TouchRequest ARM7_TouchRequest;
#endif
