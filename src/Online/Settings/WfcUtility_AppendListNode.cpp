#include <globaldefs.h>
ARM
extern "C" void WfcUtility_InsertListNodeBefore(void *);
// Original: arm9/ov031 @ 0x0223D908; symbol: func_ov031_0223d908; size: 0x10.
extern "C" void WfcUtility_AppendListNode(void *p) { WfcUtility_InsertListNodeBefore((unsigned char *)p + 8); }
