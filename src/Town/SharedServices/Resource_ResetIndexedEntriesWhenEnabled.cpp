#include <globaldefs.h>
ARM
extern "C" void Window_ResetResourceTransfers(void *);
extern "C" void Inn_RefreshStayChoiceAndGoldText(void *);
// Original: arm9/ov003 @ 0x0215CA68; symbol: func_ov003_0215ca68; size: 0x28.
extern "C" void Resource_ResetIndexedEntriesWhenEnabled(void *object) {
    unsigned char *p = (unsigned char *)object;
    if (p[0x3bc]) {
        Window_ResetResourceTransfers(p + 0x98);
        Inn_RefreshStayChoiceAndGoldText(object);
    }
}
