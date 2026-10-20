#include <globaldefs.h>
ARM
// Original: arm9/main @ 0x020795CC; symbol: func_020795cc; size: 0x1C.
extern "C" int FieldMonster_GetSelectedPartyMemberOrInvalid(unsigned char* p) { unsigned char v=p[0x17d]; return v & 8 ? (unsigned char)((int)v>>4)&3 : -1; }
