#include <globaldefs.h>
ARM
extern "C" char* strcpy(char*,const char*);
// Original: arm9/main @ 0x02026B3C; symbol: func_02026b3c; size: 0x40.
extern "C" void Object_SetBoundedNamedTwentySixByteEntry(unsigned char* p,unsigned index,unsigned short value,const char* name){if(index>=p[0x77a])return;unsigned char* entries=*(unsigned char**)(p+0x77c);if(!entries)return;*(unsigned short*)(entries+index*26)=value;strcpy((char*)*(unsigned char**)(p+0x77c)+index*26+2,name);}
