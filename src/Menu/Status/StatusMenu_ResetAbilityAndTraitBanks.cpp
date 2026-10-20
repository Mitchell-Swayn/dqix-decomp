#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
struct Entry { unsigned char ids[14]; unsigned char values[7]; unsigned char flag; };
struct Bank { Entry entries[26]; unsigned char tail[4]; };
// Original: arm9/ov004 @ 0x0215EE90; symbol: func_ov004_0215ee90; size: 0x84.
extern "C" void StatusMenu_ResetAbilityAndTraitBanks(Bank* banks) {
 for(int i=0;i<2;++i,++banks) {
  int j;
  Entry* entry=banks->entries;
  for(j=0;j<26;++j,++entry) {
   memset(entry->ids,255,14);
   memset(entry->values,0,7);
   entry->flag=0;
  }
  banks->tail[0]=0;
  banks->tail[1]=0;
  banks->tail[2]=0;
  banks->tail[3]=0;
 }
}
