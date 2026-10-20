#include <globaldefs.h>
ARM
extern "C" int Memory_CreateModeSelectedArenas(void*);
// Original: arm9/ov015 @ 0x0218F02C; symbol: func_ov015_0218f02c; size: 0x98.
extern "C" int Resource_MapTypeAndInitializeObject(unsigned char* p,void* owner,unsigned type){
 *(void**)p=owner;
 switch(type){
 case 0:p[0x1c]=0;break;
 case 1:p[0x1c]=1;break;
 case 2:p[0x1c]=3;break;
 case 3:p[0x1c]=2;break;
 case 4:p[0x1c]=2;break;
 case 5:p[0x1c]=5;break;
 case 6:p[0x1c]=6;break;
 case 7:p[0x1c]=4;break;
 }
 return Memory_CreateModeSelectedArenas(p);
}
