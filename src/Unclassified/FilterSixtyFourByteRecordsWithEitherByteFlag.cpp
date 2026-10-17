#include <globaldefs.h>
#include <std_library_functions.h>
// Original: arm9/main @ 0x0209F864; symbol: func_0209f864; size: 0x104.
extern "C" ARM void FilterSixtyFourByteRecordsWithEitherByteFlag(unsigned char* p,int mode){int i;if(!mode){*(int*)(p+0x98)=0;int count=(*(unsigned char**)(p+4))[0x8e07];for(i=0;i<count;i++){unsigned char* entry=*(unsigned char**)(p+4)+0x5c60+i*64;if(entry&&(entry[0x25]||entry[0x26])){int found=*(int*)(p+0x98);(*(int*)(p+0x98))++;memcpy(p+0x9c+found*64,entry,64);}}}else{*(int*)(p+0x49c)=0;memset(p+0x4a0,0,1024);for(i=0;i<*(int*)(p+0x98);i++){unsigned char* entry=p+0x9c+i*64;if(entry[0x25]||entry[0x26]){int found=*(int*)(p+0x49c);(*(int*)(p+0x49c))++;memcpy(p+0x4a0+found*64,entry,64);}}*(int*)(p+0x98)=*(int*)(p+0x49c);memcpy(p+0x9c,p+0x4a0,1024);}}
