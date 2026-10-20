#include <globaldefs.h>
struct State {volatile unsigned short a,x,b,y,c,z,d,w;unsigned char unused,initialized;};
extern "C" void Graphics_InitializeCanvasTransferState(char*);
extern "C" void Graphics_SnapshotSubBackgroundControlRegistersOnce(State*);
struct CanvasOwner {int words[6];char canvas[32];State saved;char pad[2];int selection[3];signed char flags[6];};
// Original: arm9/ov003 @ 0x0215376C; symbol: func_ov003_0215376c; size: 0x68.
// Clears owner state and captures the current sub-screen BG controls once.
extern "C" ARM void Graphics_ResetCanvasAndCaptureSubBackgroundState(CanvasOwner* owner){
 owner->words[0]=0;owner->words[1]=0;owner->words[2]=0;owner->words[3]=0;owner->words[5]=0;owner->words[4]=0;
 Graphics_InitializeCanvasTransferState(owner->canvas);
 owner->saved.unused=0;owner->saved.initialized=0;
 owner->selection[0]=-1;owner->selection[1]=-1;owner->selection[2]=-1;
 owner->flags[1]=-1;owner->flags[2]=0;owner->flags[3]=0;owner->flags[5]=0;owner->flags[0]=0;
 Graphics_SnapshotSubBackgroundControlRegistersOnce(&owner->saved);
}
