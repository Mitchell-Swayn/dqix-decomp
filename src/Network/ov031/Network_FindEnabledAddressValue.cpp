#include <globaldefs.h>
ARM
struct Entry { unsigned char address[6]; unsigned short value; unsigned char pad[22]; };
struct State { unsigned short word,enabled; unsigned char pad[32]; Entry entries[1]; };
extern "C" State* data_ov031_02290d14;
// Original: arm9/ov031 @ 0x02239284; symbol: func_ov031_02239284; size: 0xA8.
extern "C" unsigned Network_FindEnabledAddressValue(const unsigned char* address) {
 unsigned short i;
 State* state=data_ov031_02290d14;
 unsigned enabled=state->enabled;
 i=1;
 do {
  if(enabled&(1<<i)) {
   Entry* entry=&state->entries[i-1];
   if(address[0]==entry->address[0] && address[1]==entry->address[1] && address[2]==entry->address[2] && address[3]==entry->address[3] && address[4]==entry->address[4] && address[5]==entry->address[5]) return state->entries[i-1].value;
  }
  ++i;
 } while(i<2);
 return 0;
}
