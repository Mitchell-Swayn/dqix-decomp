#include <globaldefs.h>
ARM
extern "C" void FieldCommandQueue_TransferActiveCommandDisplayBuffers(void *object, void *field);
// Original: arm9/ov017 @ 0x021A4358; symbol: func_ov017_021a4358; size: 0x10.
extern "C" void FieldCommandQueue_TransferFrontDisplayBuffers(void *object) {
    FieldCommandQueue_TransferActiveCommandDisplayBuffers(object, *(void **)object);
}
