#include <globaldefs.h>
ARM
// Original: arm9/ov002 @ 0x02157480; symbol: func_ov002_02157480; size: 0x54.
// Fills four output indices with -1, then copies the selectable signed member indices.
extern "C" void PartyMenu_CopySelectableMemberIndices(char* self,int* output) {
 if(!output)return;
 for(int i=0;i<4;i++)output[i]=-1;
 for(int i=0;i<*(signed char*)(self+0x1c73);i++)output[i]=*(signed char*)(self+0x1c6e + i);
}
