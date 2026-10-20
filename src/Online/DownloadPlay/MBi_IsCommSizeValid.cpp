#include <globaldefs.h>
ARM
// Original: arm9/ov027 @ 0x021DC864; symbol: func_ov027_021dc864; size: 0x70.
// Validates parent/child packet sizes and the combined communication-buffer budget.
extern "C" int MBi_IsCommSizeValid(unsigned parent,unsigned child,unsigned children)
{
    if(parent>510 || parent<228)return 0;
    if(child>16 || child<8)return 0;
    int total=(parent+38)*4+0x14a+children*((child+32)*4+112);
    return total<0x15e0;
}
