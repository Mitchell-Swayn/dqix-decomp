#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
extern "C" unsigned int TextWindow_GetChoiceResult(unsigned int *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x021609C0; symbol: func_ov001_021609c0; size: 0x24.
extern "C" int TextWindow_ScriptReadChoiceResult(void *p) {
    unsigned int value = TextWindow_GetChoiceResult((unsigned int *)TextContext_GetSharedInstance());
    Script_WriteIntegerReferenceOutput(p, value);
    return 1;
}
