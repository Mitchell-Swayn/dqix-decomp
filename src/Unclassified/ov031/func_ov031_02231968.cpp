#include <globaldefs.h>
ARM
extern "C" int HasSharedObjectPointer(void);
extern "C" void SetMainLoopCallback(void (*callback)(void));
extern "C" void func_ov031_02231724(void);
// Original: arm9/ov031 @ 0x02231968; symbol: func_ov031_02231968; size: 0x20.
extern "C" void func_ov031_02231968(void) {
    if (!HasSharedObjectPointer()) SetMainLoopCallback(func_ov031_02231724);
}
