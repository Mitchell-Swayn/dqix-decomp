#include <globaldefs.h>
ARM
struct Entry { unsigned char address[6]; unsigned short value; unsigned char pad[22]; };
struct State { unsigned short word,enabled; unsigned char pad[32]; Entry entries[1]; };
// Original data: arm9/ov031 @ 0x2290d14; symbol: data_ov031_02290d14.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" State* MultibootGetParentState_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02239284; symbol: func_ov031_02239284; size: 0xA8.
extern "C" unsigned Network_FindEnabledAddressValue(const unsigned char* address) {
 unsigned short i;
 State* state=MultibootGetParentState_UnknownRoleZeroInitializedStorage;
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
