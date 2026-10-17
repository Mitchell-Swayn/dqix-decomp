#include <globaldefs.h>
ARM
extern "C" void ClearFourByteFieldsAtOffset50(void*);
// Original: arm9/main @ 0x020127CC; symbol: func_020127cc; size: 0x60.
extern "C" void SetDirectionalFlagsFromStoredPoint(unsigned char* p){ClearFourByteFieldsAtOffset50(p);if(*(int*)(p+56)<*(unsigned short*)(p+32))p[83]=1;if(*(int*)(p+56)>*(unsigned short*)(p+32))p[81]=1;if(*(int*)(p+60)<*(unsigned short*)(p+34))p[82]=1;if(*(int*)(p+60)>*(unsigned short*)(p+34))p[80]=1;}
