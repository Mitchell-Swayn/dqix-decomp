#include <globaldefs.h>
extern "C" {
extern unsigned int *data_02110370;
// Original: arm9/main @ 0x020BD88C; symbol: func_020bd88c; size: 0x20.
void ResourceManager_ReadGlobalWordPair7C(volatile unsigned int *p){volatile unsigned int *q=data_02110370;unsigned int a=q[31],b=q[32];p[0]=a;p[1]=b;}
}
