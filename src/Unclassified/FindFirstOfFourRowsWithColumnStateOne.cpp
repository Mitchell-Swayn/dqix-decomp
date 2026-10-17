#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0207D9F4; symbol: func_0207d9f4; size: 0x3C.
extern "C" unsigned char* FindFirstOfFourRowsWithColumnStateOne(unsigned char* p,int column) { for(int i=0;i<4;i++) { unsigned char* row=p+i*12;unsigned char* cell=row+column;if(*(signed char*)(cell+8)==1)return row; }return 0; }
