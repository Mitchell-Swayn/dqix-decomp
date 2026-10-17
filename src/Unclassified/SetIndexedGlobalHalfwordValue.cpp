#include <globaldefs.h>
extern "C" {
struct E{unsigned int value;char pad[32];};extern E data_0210f83c[];
// Original: arm9/main @ 0x020BBF4C; symbol: func_020bbf4c; size: 0x20.
void SetIndexedGlobalHalfwordValue(int i,unsigned int v){data_0210f83c[i].value=(unsigned short)v;}
}
