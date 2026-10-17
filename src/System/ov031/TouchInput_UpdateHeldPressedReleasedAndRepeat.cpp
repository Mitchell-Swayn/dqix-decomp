#include <globaldefs.h>
ARM
#pragma always_inline on
#pragma optimize_for_size off
struct Input {unsigned short x,y,touching,other;};
struct Bits {unsigned char held:1,pressed:1,repeat:1,released:1,rest:4;};
struct Point {unsigned short x,y;};
struct TouchState {Input samples[5];Point current,previous;char pad[8];Bits flags;};
struct Controller {unsigned char pad,count,pad2[2];TouchState* input;};
extern "C" Controller data_ov031_02290d40;
extern "C" int FastIntModulus(int,int);
extern "C" unsigned short ReadHalfwordFieldAtOffset10();
extern "C" void TouchInput_CalibrateAndClampSample(Input*,const Input*);
extern "C" void WriteTwoHalfwords(unsigned short,unsigned short,void*);
// Original: arm9/ov031 @ 0x0223D1B8; symbol: func_ov031_0223d1b8; size: 0x19C.
extern "C" void TouchInput_UpdateHeldPressedReleasedAndRepeat() {
 Input calibrated; int i;
 int old=data_ov031_02290d40.input->flags.held!=0;
 unsigned char touched=0;
 int index=ReadHalfwordFieldAtOffset10();
 TouchState* state=data_ov031_02290d40.input;
 unsigned short x=((volatile TouchState*)state)->current.x;
 unsigned short y=((volatile TouchState*)state)->current.y;
 state->previous.x=x;state->previous.y=y;
 i=0;
 do {
  Input* sample=&data_ov031_02290d40.input->samples[index];
  if(sample->touching==1 && sample->other==0) {
   touched=1;
   TouchInput_CalibrateAndClampSample(&calibrated,sample);
   WriteTwoHalfwords(calibrated.x,calibrated.y,&data_ov031_02290d40.input->current);
   break;
  }
  ++i;
  index=FastIntModulus(index+4,5);
 }while(i<4);
 int changed=touched^old;
 data_ov031_02290d40.input->flags.pressed=(unsigned char)(touched&changed);
 data_ov031_02290d40.input->flags.released=(unsigned char)(old&changed);
 data_ov031_02290d40.input->flags.held=touched;
 data_ov031_02290d40.input->flags.repeat=data_ov031_02290d40.input->flags.pressed;
 if(!touched)data_ov031_02290d40.count=0;
 else {
  ++data_ov031_02290d40.count;
  if(data_ov031_02290d40.count==40)data_ov031_02290d40.input->flags.repeat=1;
  else if(data_ov031_02290d40.count==47) {
   data_ov031_02290d40.input->flags.repeat=1;
   data_ov031_02290d40.count=40;
  }
 }
}
