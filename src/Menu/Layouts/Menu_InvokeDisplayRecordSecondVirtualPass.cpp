#include <globaldefs.h>
ARM
extern "C" void MenuRecordList_InvokeSecondaryPass(void *);
// Original: arm9/ov011 @ 0x02184740; symbol: func_ov011_02184740; size: 0x10.
extern "C" void Menu_InvokeDisplayRecordSecondVirtualPass(void *p) { MenuRecordList_InvokeSecondaryPass((unsigned char *)p + 0x118); }
