#ifndef ARM7_TOUCH_SAMPLE_H
#define ARM7_TOUCH_SAMPLE_H
typedef struct {unsigned short low,high;} TouchSharedSample;
typedef union {
 unsigned int word;
 unsigned short halves[2];
 TouchSharedSample shared;
 struct {unsigned int x:12,y:12,touch:1,invalid:2,reserved:5;} fields;
} TouchSample;
typedef char TouchSampleSizeCheck[sizeof(TouchSample)==4?1:-1];
#define ARM7_SHARED_TOUCH_SAMPLE (*(volatile TouchSharedSample*)0x027fffaa)
#endif
