#include <globaldefs.h>
ARM
#pragma opt_optimizecontrolflow off
extern "C" void _ZN8Object3D18SetAnimationByNameEPKci(void*,const char*,int);
// Original: arm9/ov015 @ 0x0218F364; symbol: func_ov015_0218f364; size: 0x38.
// Plays a named animation using the viewer animation flags with bit 3 set.
extern "C" void CharacterViewer_PlayNamedAnimation(unsigned char* self,const char* name) {
 if(self[0x1c]==0 || self[0x1c]==1) _ZN8Object3D18SetAnimationByNameEPKci(*(void**)(self+0x24),name,*(int*)(self+0x44)|8);
 else _ZN8Object3D18SetAnimationByNameEPKci(*(void**)(self+0x24),name,*(int*)(self+0x44)|8);
}
