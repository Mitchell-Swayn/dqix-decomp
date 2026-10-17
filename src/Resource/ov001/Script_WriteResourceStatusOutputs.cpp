#include <globaldefs.h>
ARM
struct GameResources;
extern "C" GameResources* GameResources_GetInstance();
extern "C" void SetNestedSecondWordForTypeThree(void*,int);
// Original: arm9/ov001 @ 0x02160A7C; symbol: func_ov001_02160a7c; size: 0x8C.
extern "C" int Script_WriteResourceStatusOutputs(unsigned char* output,int count) {
int value;
unsigned char* status=*(unsigned char**)((unsigned char*)GameResources_GetInstance()+0x3734);
SetNestedSecondWordForTypeThree(output,status[0xcd]);output+=8;
if(count>=2){SetNestedSecondWordForTypeThree(output,status[0xcf]);output+=8;}
if(count>=3){SetNestedSecondWordForTypeThree(output,status[0xce]);output+=8;}
if(count>=4){if(status[0xcc]==2)value=0;else if(status[0xcc]==1)value=1;SetNestedSecondWordForTypeThree(output,value);}
return 1;
}
