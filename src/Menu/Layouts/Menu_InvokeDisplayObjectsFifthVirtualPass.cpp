#include <globaldefs.h>
ARM
extern "C" void MenuRecordList_InvokeFinalPass(void *);
// Original: arm9/ov011 @ 0x02184760; symbol: func_ov011_02184760; size: 0x10.
extern "C" void Menu_InvokeDisplayObjectsFifthVirtualPass(void *p) {
    MenuRecordList_InvokeFinalPass((char *)p + 0x118);
}
