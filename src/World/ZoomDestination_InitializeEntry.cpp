#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void ZoomDestination_ClearPlacementConfiguration(void *);
// Original: arm9/main @ 0x020A8128; symbol: func_020a8128; size: 0x48.
void ZoomDestination_InitializeEntry(unsigned char *p){p[0]=0;p[1]=255;p[2]=0;*(int *)(p+4)=0;*(short *)(p+24)=0;ZoomDestination_ClearPlacementConfiguration(p+8);*(short *)(p+26)=0;*(short *)(p+28)=0;*(int *)(p+32)=0;*(int *)(p+36)=0;*(int *)(p+40)=0;}
}
