#include <globaldefs.h>
ARM
extern "C" {unsigned ReadSharedHalfwordOrBusy8000();void SetSharedObjectWord54UnlessStateNineOrTen(unsigned);void SetStateWithTransitionCallbacks(int);void func_ov031_02239d70();unsigned func_ov031_02239e48(void(*)(),unsigned);}
// Original: arm9/ov031 @ 0x02239CD4; symbol: func_ov031_02239cd4; size: 0x9C.
extern "C" unsigned short FindNextSharedMaskBitAndDispatch(unsigned short index){
unsigned mask=ReadSharedHalfwordOrBusy8000();
if(mask==0x8000){SetSharedObjectWord54UnlessStateNineOrTen(3);SetStateWithTransitionCallbacks(9);return 3;}
if(mask==0){SetSharedObjectWord54UnlessStateNineOrTen(22);SetStateWithTransitionCallbacks(9);return 24;}
while(!(mask&(1<<(index-1)))){index++;if(index>16)return 24;}
return func_ov031_02239e48(func_ov031_02239d70,index);
}
