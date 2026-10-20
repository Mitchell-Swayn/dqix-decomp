#include <globaldefs.h>

// Original: arm9/ov000 @ 0x0217542C; symbol: func_ov000_0217542c; size: 0x14.
// Field roles remain unclassified; offsets describe the observed layout.
extern "C" ARM bool BattleMenu_HasTouchSelectionChanged(char* p)
{
    return *(int*)(p+0x118)==2;
}
