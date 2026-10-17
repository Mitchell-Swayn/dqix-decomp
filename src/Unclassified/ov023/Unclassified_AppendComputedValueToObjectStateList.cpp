#include <globaldefs.h>
ARM
extern "C" unsigned short func_ov023_021f6558(void *object);
extern "C" void *func_ov011_021849c8(void *self);
extern "C" void *func_ov023_021f6880(void **head, unsigned short value);
// Original: arm9/ov023 @ 0x021F6590; symbol: func_ov023_021f6590; size: 0x24.
extern "C" void Unclassified_AppendComputedValueToObjectStateList(void *object) {
    unsigned short value = func_ov023_021f6558(object);
    void *head = func_ov011_021849c8(object);
    func_ov023_021f6880((void **)head, value);
}
