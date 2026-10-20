#include <globaldefs.h>
ARM
#include <std_library_functions.h>
struct State;
extern "C" void Graphics_SnapshotSubBackgroundControlRegistersOnce(State*);
extern "C" void Selection_InitializeDisplayController(State*);
// Original: arm9/ov023 @ 0x021D8A40; symbol: func_ov023_021d8a40; size: 0xB8.
extern "C" void Graphics_InitializeSubDisplayStateAndRecordGrid(unsigned char* self) {
 self[0x18]=0; self[0x19]=0;
 Graphics_SnapshotSubBackgroundControlRegistersOnce((State*)(self+8));
 *(unsigned*)(self+0x1c)=(*(volatile unsigned*)0x04001000&0x1f00)>>8;
 *(unsigned*)self=0;
 *(unsigned*)(self+4)=0;
 Selection_InitializeDisplayController((State*)(self+0x20));
 for(int i=0;i<4;i++) *(unsigned*)(self+i*4+0xdc)=0;
 *(int*)(self+0xec)=-1;
 memset(self+0xf0,0,0x14);
 memset(self+0x104,0,0x14);
 self[0x118]=0; self[0x119]=0; self[0x11a]=0; self[0x11b]=0;
 self[0x11c]=0; self[0x11d]=0;
 *(unsigned*)(self+0x120)=0;
 self[0x11e]=0;
}
