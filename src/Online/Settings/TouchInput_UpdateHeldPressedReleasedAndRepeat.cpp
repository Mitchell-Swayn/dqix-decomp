#include <globaldefs.h>
ARM
#pragma always_inline on
#pragma optimize_for_size off
struct Input {unsigned short x,y,touching,other;};
struct Bits {unsigned char held:1,pressed:1,repeat:1,released:1,rest:4;};
struct Point {unsigned short x,y;};
struct TouchState {Input samples[5];Point current,previous;char pad[8];Bits flags;};
struct Controller {unsigned char pad,count,pad2[2];TouchState* input;};
// Original data: arm9/ov031 @ 0x2290d40; symbol: data_ov031_02290d40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Controller WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage;
extern "C" int FastIntModulus(int,int);
extern "C" unsigned short TP_GetLatestIndexInAuto();
extern "C" void TouchInput_CalibrateAndClampSample(Input*,const Input*);
extern "C" void WfcUtility_WriteCoordinatePair(unsigned short,unsigned short,void*);
// Original: arm9/ov031 @ 0x0223D1B8; symbol: func_ov031_0223d1b8; size: 0x19C.
extern "C" void TouchInput_UpdateHeldPressedReleasedAndRepeat() {
 Input calibrated; int i;
 int old=WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.input->flags.held!=0;
 unsigned char touched=0;
 int index=TP_GetLatestIndexInAuto();
 TouchState* state=WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.input;
 unsigned short x=((volatile TouchState*)state)->current.x;
 unsigned short y=((volatile TouchState*)state)->current.y;
 state->previous.x=x;state->previous.y=y;
 i=0;
 do {
  Input* sample=&WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.input->samples[index];
  if(sample->touching==1 && sample->other==0) {
   touched=1;
   TouchInput_CalibrateAndClampSample(&calibrated,sample);
   WfcUtility_WriteCoordinatePair(calibrated.x,calibrated.y,&WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.input->current);
   break;
  }
  ++i;
  index=FastIntModulus(index+4,5);
 }while(i<4);
 int changed=touched^old;
 WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.input->flags.pressed=(unsigned char)(touched&changed);
 WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.input->flags.released=(unsigned char)(old&changed);
 WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.input->flags.held=touched;
 WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.input->flags.repeat=WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.input->flags.pressed;
 if(!touched)WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.count=0;
 else {
  ++WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.count;
  if(WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.count==40)WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.input->flags.repeat=1;
  else if(WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.count==47) {
   WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.input->flags.repeat=1;
   WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage.count=40;
  }
 }
}
