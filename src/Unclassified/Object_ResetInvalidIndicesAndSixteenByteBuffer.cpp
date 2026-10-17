#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x0209E46C; symbol: func_0209e46c; size: 0x34.
void Object_ResetInvalidIndicesAndSixteenByteBuffer(char *p){*(int *)(p+0x6c)=-1;memset(p+0x70,0,16);*(int *)(p+0x90)=-1;*(int *)(p+0x94)=0;}
}
