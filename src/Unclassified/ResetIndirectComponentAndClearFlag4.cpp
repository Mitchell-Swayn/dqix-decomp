#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void ClearBytes0And1And6AndHalfwords2And4(void *);
// Original: arm9/main @ 0x02049520; symbol: func_02049520; size: 0x30.
void ResetIndirectComponentAndClearFlag4(char **p){if(!p[79])return;ClearBytes0And1And6AndHalfwords2And4(p[79]+0x4e);*(int *)(p[79]+32)&=~4;}
}
