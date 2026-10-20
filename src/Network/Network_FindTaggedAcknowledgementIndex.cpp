#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
// Original: arm9/main @ 0x020E38E4; symbol: func_020e38e4; size: 0x48.
int Network_FindTaggedAcknowledgementIndex(unsigned char *p,int type,int v){for(int i=0;i<4;i++,p+=8)if(p[4]==type&&(*(int *)p==v||v==-1))return i;return -1;}
}
