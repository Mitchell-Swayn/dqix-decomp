#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x0209A614; symbol: func_0209a614; size: 0x40.
extern "C" void* SkillTable_FindEntryBySecondaryKey(unsigned char* p,unsigned key){for(int i=0;i<*(int*)(p+4);++i){unsigned char* q=*(unsigned char**)p+i*12;if(key==*(unsigned short*)(q+2))return q;}return 0;}
