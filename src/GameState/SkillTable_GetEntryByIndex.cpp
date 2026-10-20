#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x0209A654; symbol: func_0209a654; size: 0x1C.
char *SkillTable_GetEntryByIndex(unsigned int *p,unsigned int i){if(p[1]<=i)return 0;return (char *)p[0]+i*12;}
}
