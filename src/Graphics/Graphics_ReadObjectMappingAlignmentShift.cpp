#include <globaldefs.h>
// Original: arm9/main @ 0x0209378C; symbol: func_0209378c; size: 0x64.
extern "C" ARM int Graphics_ReadObjectMappingAlignmentShift(int engine){unsigned int value;if(engine==0){value=*(volatile unsigned int*)0x04000000;engine=0x300010;}else{value=*(volatile unsigned int*)0x04001000;engine=0x300010;}unsigned int selected=value&engine;int result=0;switch(selected){case 0x10:result=5;break;case 0x100010:result=6;break;case 0x200010:result=7;break;}return result;}
