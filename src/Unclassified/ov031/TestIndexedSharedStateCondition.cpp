#include <globaldefs.h>
ARM
extern "C" char* GetSharedObjectRegionAtOffset1024();
// Original: arm9/ov031 @ 0x0222FD9C; symbol: func_ov031_0222fd9c; size: 0x94.
extern "C" int TestIndexedSharedStateCondition(unsigned action) {
unsigned char* p=(unsigned char*)GetSharedObjectRegionAtOffset1024();
int result=1;
switch(action) {
case 7: if(p[0xf5]==0) result=0;break;
case 0: case 1: if((unsigned char)(p[0xe7]+255)<=1) result=0;break;
case 4: case 5: case 6: if(p[0xf5]!=0) result=0;break;
case 9: case 10: if(p[0xf6]!=0) result=0;break;
}
return result;
}
