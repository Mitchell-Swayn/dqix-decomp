#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma optimization_level 1
#pragma always_inline on
inline void BeginIdleTransition(unsigned char* self){
 if(self[0x636])return;
 int previous=*(signed char*)(self+0x4e6);
 int active=1,reset=0;
 self[0x4e7]=previous;
 self[0x4e6]=active;
 self[0x4e4]=reset;
 unsigned counter=self[0x636];
 self[0x636]=counter+1;
}
// Original: arm9/ov023 @ 0x021E4E3C; symbol: Menu_BeginRequestedPartyPreviewClose; size: 0x50.
// Starts the byte-state transition once when flag1000 is set and flag2000 is clear.
extern "C" void Menu_BeginRequestedPartyPreviewClose(unsigned char* self){
 unsigned flags=*(unsigned short*)(self+0x634);
 if(!(flags&0x1000))return;
 if(flags&0x2000)return;
 BeginIdleTransition(self);
}
