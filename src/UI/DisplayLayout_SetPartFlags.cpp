#include <globaldefs.h>
extern "C" {
unsigned char *DisplayLayout_FindPartById(void *,int);
// Original: arm9/main @ 0x0207F7AC; symbol: func_0207f7ac; size: 0x20.
void DisplayLayout_SetPartFlags(void *p,int i,unsigned int v){unsigned char *q=DisplayLayout_FindPartById(p,i);if(q)q[42]|=v;}
}
