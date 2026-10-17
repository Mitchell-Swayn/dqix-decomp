#include <globaldefs.h>
ARM
extern "C" {void func_0205addc(void*,unsigned char);
// Original: arm9/main @ 0x0205AE8C; symbol: func_0205ae8c; size: 0x44.
void Object_UpdateAllCountedResourceEntries(unsigned char* p){unsigned char* table=*(unsigned char**)(p+0x3c);if(!table)return;unsigned short count=*(unsigned short*)(table+4);for(unsigned short i=0;i<count;i++)func_0205addc(p,(unsigned char)i);}}
