#include <globaldefs.h>
struct MainLoopWords {unsigned char preceding[0x18]; unsigned int words[2];};
extern "C" MainLoopWords data_ov031_02250c0c;
// Original: arm9/ov031 @ 0x0222750C; symbol: func_ov031_0222750c; size: 0x14.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM void SetMainLoopWordPair(unsigned int a,unsigned int b) {data_ov031_02250c0c.words[0]=a; data_ov031_02250c0c.words[1]=b;}
