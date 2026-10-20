#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0209A530; symbol: func_0209a530; size: 0x2C.
extern "C" void SkillTable_CopyEntry(unsigned char* p,unsigned char* q) { *(unsigned short*)p=*(unsigned short*)q;*(unsigned short*)(p+2)=*(unsigned short*)(q+2);*(unsigned int*)(p+4)=*(unsigned int*)(q+4);*(unsigned short*)(p+8)=*(unsigned short*)(q+8);*(unsigned short*)(p+10)=*(unsigned short*)(q+10); }
