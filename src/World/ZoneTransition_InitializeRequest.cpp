#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020A3578; symbol: func_020a3578; size: 0x54.
void ZoneTransition_InitializeRequest(char *p){*(short *)p=0;*(short *)(p+6)=0;*(short *)(p+8)=0;*(short *)(p+10)=0;p[42]=-1;*(int *)(p+44)=0;*(int *)(p+48)=0;p[52]=0;*(int *)(p+12)=-1;p[4]=0;*(short *)(p+2)=0x75a4;p[36]=0;p[37]=0;p[53]=0;p[5]=2;}
}
