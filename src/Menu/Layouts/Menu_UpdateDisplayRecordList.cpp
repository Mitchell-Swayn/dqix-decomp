#include <globaldefs.h>
ARM
extern "C" void Object_InvokeUpdateOnLinkedNodes(void *object);
// Original: arm9/ov011 @ 0x02184750; symbol: func_ov011_02184750; size: 0x10.
extern "C" void Menu_UpdateDisplayRecordList(void *object) {
    Object_InvokeUpdateOnLinkedNodes((char *)object + 0x118);
}
