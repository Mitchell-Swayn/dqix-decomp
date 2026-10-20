#include <globaldefs.h>
// Original: arm9/main @ 0x020865B8; symbol: func_020865b8; size: 0x34.
extern "C" ARM void PartyRecord_MarkSpellLearned(unsigned char* p,int i){unsigned char* flags=p+0x111;flags[i/8]|=1<<(i%8);}
