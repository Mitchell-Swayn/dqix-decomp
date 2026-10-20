#include <globaldefs.h>
#include <std_library_functions.h>
// Original: arm9/main @ 0x02087628; symbol: func_02087628; size: 0x54.
extern "C" ARM void PartyTransfer_ClearAllSnapshots(char *p) { for(int i=0;i<3;i++){ memset(p+0xf2c+i*20,0,20); (p+i*20)[0xf3c]=(char)255; } }
