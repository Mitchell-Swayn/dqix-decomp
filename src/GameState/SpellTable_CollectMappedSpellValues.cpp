#include <globaldefs.h>
extern "C" {
unsigned short *SpellTable_FindSpellMapping(void *,unsigned char);
// Original: arm9/main @ 0x0209ACDC; symbol: func_0209acdc; size: 0x54.
unsigned int SpellTable_CollectMappedSpellValues(void *p,unsigned char *ids,unsigned int n,unsigned short *out){unsigned int count=0;for(unsigned int i=0;i<n;i++){unsigned short *q=SpellTable_FindSpellMapping(p,ids[i]);if(q)out[count++]=q[1];}return count;}
}
