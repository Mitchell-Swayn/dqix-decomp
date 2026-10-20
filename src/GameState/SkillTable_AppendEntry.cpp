#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void SkillTable_CopyEntry(void *,int);
// Original: arm9/main @ 0x0209A4F0; symbol: func_0209a4f0; size: 0x40.
void SkillTable_AppendEntry(unsigned int *p,int v){if(!p[0])return;int i=p[1];if(i>=287)return;p[1]=i+1;SkillTable_CopyEntry((void *)(p[0]+i*12),v);}
}
