#include <globaldefs.h>
ARM
extern "C" { extern unsigned char* data_ov004_021707c4; void Unclassified_InvokeType15ObjectCallbacks(void*,int,int,int); void World_ApplyStateValueToMatchingType6Entry(void*,int); }
// Original: arm9/ov004 @ 0x0215571C; symbol: func_ov004_0215571c; size: 0x90.
extern "C" int Graphics_DisplayClampedPercentageAndRawValue(void* output) {
 short current=*(short*)(data_ov004_021707c4+14);
 short maximum=*(short*)(data_ov004_021707c4+12);
 short percent=current*100/maximum;
 if(percent==0 && current==0) percent=0;
 if(percent==0 && current!=0) percent=1;
 if(percent>100) percent=100;
 if(percent<0) percent=0;
 Unclassified_InvokeType15ObjectCallbacks(output,19,percent,15);
 Unclassified_InvokeType15ObjectCallbacks(output,20,current,15);
 World_ApplyStateValueToMatchingType6Entry(output,16);
 return 0;
}
