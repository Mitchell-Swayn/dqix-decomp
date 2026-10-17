#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0203C05C; symbol: func_0203c05c; size: 0x70.
extern "C" void Graphics_WriteFourHorizontalObjectAttributes(char* p,unsigned* out,int a,int x,unsigned y,int flags){short id=*(short*)(p+34);if(id<0)return;for(int i=0;i<4;++i){*out=(y&255)|0x80004000|((unsigned(x)<<23)>>7);*(unsigned short*)(out+1)=id|((unsigned(a)<<30)>>20)|((unsigned(flags)<<28)>>16);out+=2;x+=32;id+=2;}}
