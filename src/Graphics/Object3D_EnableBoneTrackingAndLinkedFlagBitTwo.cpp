#include <globaldefs.h>
#include <World/Object3D.h>
extern "C" {
// Original: arm9/main @ 0x0204A3F0; symbol: func_0204a3f0; size: 0x48.
void Object3D_EnableBoneTrackingAndLinkedFlagBitTwo(char *p,Object3D *obj){*(Object3D **)(p+0x21c)=obj;obj->EnableBoneTracking();unsigned int *n=*(unsigned int **)(*(char **)(p+0x21c)+8);if(n){if(((int)(n[42]<<31)>>31)==0)n=0;if(n)*n|=4;}}
}
