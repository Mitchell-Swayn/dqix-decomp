#include <globaldefs.h>
ARM
extern "C" char data_021065d8[],data_02105fd8[];extern "C" void func_0203b97c(void*,void*,int,int,int,int,int,int,int,unsigned short);
// Original: arm9/main @ 0x0203B8BC; symbol: func_0203b8bc; size: 0xC0.
extern "C" void Graphics_UpdateSelectedBackgroundTileBuffer(char* p,int row,int col,int a,int b,int c,int d,int e,unsigned short key){*(int*)(p+(col+row*4)*4+64)=1;if(row==1){switch(col){case 0:func_0203b97c(p,data_021065d8,64,32,a,b,c,d,e,key);break;case 1:func_0203b97c(p,data_02105fd8,32,24,a,b,c,d,e,key);break;}}}
