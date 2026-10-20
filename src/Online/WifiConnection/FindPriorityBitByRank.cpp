#include <globaldefs.h>
ARM
extern "C" int Network_GetConnectionWorkspace(unsigned);
// Original: arm9/ov031 @ 0x02214AFC; symbol: func_ov031_02214afc; size: 0x68.
// Finds the requested set-bit rank in the selected state's thirteen-bit mask.
extern "C" int FindPriorityBitByRank(int rank) {
 unsigned char bit,count;
 unsigned short mask=*(unsigned short*)((char*)Network_GetConnectionWorkspace(16)+0xd16);
 if(!mask)return -1;
 bit=0;count=0;
 do {
  if(mask&(1<<bit)) {
   if(count==rank)return (signed char)bit;
   ++count;
  }
  ++bit;
 }while(bit<13);
 return -1;
}
