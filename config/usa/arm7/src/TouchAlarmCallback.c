/* Queue an alarm's sample index; report invalid coordinates if the queue is full. */
#pragma dont_inline on
#include "TouchSample.h"
extern int ARM7_EnqueueSpiTask(int,unsigned int,unsigned short,...);
extern void ARM7_SendSpiReply(int,unsigned int);
void ARM7_TouchAlarmCallback(void *argument)
{
 TouchSample sample;
 unsigned short high;
 if(!ARM7_EnqueueSpiTask(0,0x10,1,(unsigned int)argument)) {
  /* With both axes marked invalid, the coordinate/reserved bits are unspecified. */
  sample.fields.invalid=3;
  high=sample.halves[1];
  ARM7_SHARED_TOUCH_SAMPLE.low=sample.halves[0];
  ARM7_SHARED_TOUCH_SAMPLE.high=high;
  ARM7_SendSpiReply(0x10,(unsigned int)argument&0xff);
 }
}
