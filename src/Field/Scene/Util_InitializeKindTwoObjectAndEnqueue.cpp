#include <globaldefs.h>
ARM
extern "C" void Field_InitializeSharedSubscreenCommand(unsigned char*);
extern "C" void LinkedQueue_InsertAfterHeadAndMarkLinked(char*, char*);
// Original: arm9/ov017 @ 0x021A120C; symbol: func_ov017_021a120c; size: 0x40.
extern "C" void Util_InitializeKindTwoObjectAndEnqueue(unsigned char* self, int kind, int value) {
    unsigned char* object = *(unsigned char**)(self + 0x3708);
    Field_InitializeSharedSubscreenCommand(object);
    *(unsigned char*)(*(unsigned char**)(self + 0x3708) + 0x20) = kind;
    *(unsigned char*)(*(unsigned char**)(self + 0x3708) + 0x21) = value;
    LinkedQueue_InsertAfterHeadAndMarkLinked(*(char**)(self + 0x36fc), *(char**)(self + 0x3708));
}
