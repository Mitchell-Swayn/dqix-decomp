#include <globaldefs.h>
#include <World/Object3D.h>
ARM
struct RenderState { char unknown0[0x7f8]; void* resource; char unknown1[0x45c]; signed char phase; char unknown2[0x143]; unsigned flags; };
extern "C" void Graphics_DrawObjectWithBoneAttachments(void*);

// Original: arm9/ov009 @ 0x02184C30; symbol: func_ov009_02184c30; size: 0x74.
extern "C" void World_DrawStageObjectAttachments(RenderState* state) {
 if(state->phase==0 || state->phase==12) return;
 *(volatile unsigned*)0x04000444=0;Graphics_DrawObjectWithBoneAttachments(state->resource);
 if(state->flags&0x200) {((Object3D*)((char*)state+0x878))->Draw(true);((Object3D*)((char*)state+0xcd8))->Draw(true);}
 *(volatile unsigned*)0x04000448=1;
}
