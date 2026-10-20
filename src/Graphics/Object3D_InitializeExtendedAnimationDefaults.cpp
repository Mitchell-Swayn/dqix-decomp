#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void _ZN8Object3D10InitializeEv(void *);
// Original: arm9/main @ 0x02041244; symbol: func_02041244; size: 0x48.
void Object3D_InitializeExtendedAnimationDefaults(unsigned char *p){_ZN8Object3D10InitializeEv(p);*(short *)(p+0xac)=0;*(int *)(p+0xb0)=0;*(int *)(p+0xc0)=0;p[0xc4]=0;*(int *)(p+0xcc)=0;*(int *)(p+0xc8)=122;p[0xd4]&=~1;p[0xd4]&=~2;*(int *)(p+0xd0)=0;}
}
