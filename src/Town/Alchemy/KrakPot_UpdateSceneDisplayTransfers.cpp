#include <globaldefs.h>
ARM
struct Bits {unsigned char bit0:1;unsigned char bit1:1;unsigned char rest:6;};
extern "C" void Graphics_AdvanceTaskAndToggleMainPlaneZero(void*);
extern "C" void Graphics_ResetCountedTransferEntriesWithModeZero(void*);
// Original: arm9/ov006 @ 0x02154FE4; symbol: Graphics_UpdateActiveObjectAndResetTransfers; size: 0x84.
extern "C" void KrakPot_UpdateSceneDisplayTransfers(char *self) {
 if(!*(unsigned char*)(self+0xadc))return;
 if(*(unsigned char*)(self+0x12bd)) {
 volatile unsigned *display=(volatile unsigned*)0x04000000;
 unsigned planes=(*display&0x1f00)>>8;
 *display=(*display&~0x1f00)|((planes|1)<<8);
 *(unsigned char*)(self+0x12bd)=0;
 }
 Graphics_AdvanceTaskAndToggleMainPlaneZero(self+0xae4);
 if(((Bits*)(self+0x127f))->bit1)return;
 if(*(void**)(self+0x1d4))Graphics_ResetCountedTransferEntriesWithModeZero(*(void**)(self+0x1d4));
}
