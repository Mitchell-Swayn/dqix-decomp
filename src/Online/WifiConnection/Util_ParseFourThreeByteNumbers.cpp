#include <globaldefs.h>
ARM
extern "C" int Runtime_ParseStringAsBaseTenInteger(const char*);
extern "C" void VectorizedMemset(void*,int,unsigned);
extern "C" void MI_CpuCopy8(const void*,void*,unsigned);
// Original: arm9/ov031 @ 0x022366D8; symbol: func_ov031_022366d8; size: 0x88.
extern "C" void Util_ParseFourThreeByteNumbers(const char* src, unsigned char* dst) {
char text[4];
VectorizedMemset(text,0,4);
int i=0,off=0;
do {
MI_CpuCopy8(src+off,text,3);
int j=0;
char* p=text;
do {
if(*(unsigned char*)p!=0) break;
++j;
*p++=' ';
} while(j<3);
dst[i]=Runtime_ParseStringAsBaseTenInteger(text);
++i;
off+=3;
} while(i<4);
}
