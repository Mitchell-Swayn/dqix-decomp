#include <globaldefs.h>
ARM
extern "C" {void SetBankedReverseBitFlag(void*,void*,short,int);
// Original: arm9/main @ 0x0206EB20; symbol: func_0206eb20; size: 0x44.
void Zone3D_ClearRecordedBMDJStateRange(void* p,void* q,int start,int end){for(;start<end;start++)SetBankedReverseBitFlag(p,q,(short)start,0);}}
