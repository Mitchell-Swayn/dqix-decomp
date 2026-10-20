#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x020A367C; symbol: func_020a367c; size: 0x18.
void PartySelection_DisableMember(unsigned char *p,unsigned int i){p[0x34]&=~(1<<i);}
}
