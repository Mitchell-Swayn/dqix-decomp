#include <globaldefs.h>
typedef int (*SelectionProc)(void*,void*,int*);
extern "C" SelectionProc data_ov000_0218409c[58];
#pragma force_active on
// Original: arm9/ov000 @ 0x021820BC; symbol: func_ov000_021820bc; size: 0x40.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" int DispatchCombatSelectionProcedure(void* context, void* action, int selector, int* output)
{
    if (selector < 0 || (unsigned)selector >= 58) return 0; SelectionProc proc=data_ov000_0218409c[selector]; if (!proc) return 0; return proc(context,action,output);
}
