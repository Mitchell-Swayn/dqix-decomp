/* Read both filtered axes and reconcile the controller state before publication. */
#pragma dont_inline on
#include "TouchSample.h"
extern int ARM7_ReadTouchControllerStatus(void);
extern int ARM7_FilterTouchAxis(unsigned short*,int,int,unsigned short*);
extern void ARM7_ClockTouchCommandByte(void);
/* Cleared by the WRAM startup BSS loop; retained by the controller-status reader. */
unsigned short ARM7_TouchControllerStatus;
extern const char ARM7_TouchSourceFile[];
extern const char ARM7_TouchStateError[];
extern void ARM7_Panic(const char*,int,const char*,...);
#define TOUCH_CONTROL (*(volatile unsigned short*)0x040001c0)
void ARM7_ReadTouchCoordinates(TouchSample *sample,int threshold,unsigned short *spread)
{
 unsigned short coordinate,xSpread,ySpread;
 int initialStatus,status,i;
 *spread=0;
 if(threshold<0)threshold=-threshold;
 initialStatus=ARM7_ReadTouchControllerStatus();
 if(initialStatus==0) {
  sample->fields.x=0;
  sample->fields.y=0;
  sample->fields.touch=0;
  sample->fields.invalid=3;
  ARM7_TouchControllerStatus=0;
  return;
 }
 sample->fields.invalid=ARM7_FilterTouchAxis(&coordinate,threshold,0,&xSpread);
 sample->fields.x=coordinate;
 if(ARM7_FilterTouchAxis(&coordinate,threshold,1,&ySpread)==2)sample->fields.invalid|=2;
 sample->fields.y=coordinate;
 TOUCH_CONTROL=0x8a01;
 i=0;
 do {ARM7_ClockTouchCommandByte();i++;} while(i<12);
 TOUCH_CONTROL=0x8201;
 ARM7_ClockTouchCommandByte();
 if(initialStatus==2)sample->fields.invalid=3;
 status=ARM7_ReadTouchControllerStatus();
 switch(status) {
 case 2:
  sample->fields.touch=1;
  sample->fields.invalid=3;
  ARM7_TouchControllerStatus=0;
  break;
 case 1:
  sample->fields.touch=1;
  ARM7_TouchControllerStatus=1;
  *spread=xSpread>=ySpread?xSpread:ySpread;
  break;
 case 0:
  sample->fields.touch=0;
  ARM7_TouchControllerStatus=0;
  break;
 default:
  ARM7_Panic(ARM7_TouchSourceFile,0x1a1,ARM7_TouchStateError);
  break;
 }
}
