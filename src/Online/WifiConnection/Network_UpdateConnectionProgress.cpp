#include <globaldefs.h>
ARM
extern "C" int Network_GetConnectionWorkspace(unsigned);
extern "C" unsigned Network_NormalizeWirelessProfileIndex(unsigned);
// Original: arm9/ov031 @ 0x02213450; symbol: func_ov031_02213450; size: 0x60.
// The direct caller at arm9/ov031:022130AC loads this argument with ldrb.
// Stores the current state and, for a new maximum from eight through fifteen,
// refreshes two lookup bytes. State and table field roles remain unresolved.
extern "C" void Network_UpdateConnectionProgress(unsigned char value) {
 unsigned char* table;
 unsigned char* state=(unsigned char*)Network_GetConnectionWorkspace(1);
 table=(unsigned char*)Network_GetConnectionWorkspace(16);
 state[9]=value;
 if(value>=16u)return;
 if((unsigned)value>state[0x16]) {
  state[0x16]=value;
  if(value>7u) {
   state[0x15]=Network_NormalizeWirelessProfileIndex(table[0xd0d]);
   state[0x14]=(table+(table[0xd13]<<2))[0x444];
  }
 }
}
