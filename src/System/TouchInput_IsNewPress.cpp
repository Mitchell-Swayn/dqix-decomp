#include <globaldefs.h>
extern "C" {
// Original: arm9/main @ 0x02012AAC; symbol: func_02012aac; size: 0x24.
int TouchInput_IsNewPress(unsigned char *p){if(p[0x5d]&&p[0x5e]==0)return 1;return 0;}
}
