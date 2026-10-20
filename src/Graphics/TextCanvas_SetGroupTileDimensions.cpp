#include <globaldefs.h>
ARM
extern "C" unsigned char* DisplayLayout_FindGroupById(void*,int);
// Original: arm9/main @ 0x020808A4; symbol: func_020808a4; size: 0x24.
extern "C" void TextCanvas_SetGroupTileDimensions(unsigned char* p,int key,int a,int b){unsigned char* q=DisplayLayout_FindGroupById(p+12,key);if(q){*(short*)(q+14)=a;*(short*)(q+16)=b;}}
