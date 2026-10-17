#include <globaldefs.h>
ARM
#pragma optimize_for_size on
// Original: arm9/main @ 0x0203B5A0; symbol: func_0203b5a0; size: 0x40.
extern "C" int Object_TestSelectedFloatWithinSixteen(char* p,int which){
    int value;
    if(which==0)value=(int)*(float*)(p+12);
    else value=(int)*(float*)(p+24);
    if(value>-16 && value<16)return 1;
    return 0;
}
