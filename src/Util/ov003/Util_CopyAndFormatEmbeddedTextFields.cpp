#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned);
extern "C" unsigned String_CountBytesUntilTerminator(const signed char*);
extern "C" int sprintf(char*, const char*, ...);
extern "C" const char data_ov003_0217fce0[];
struct TextOwner { unsigned first; unsigned buffer; unsigned third; };
struct TextSource { unsigned first; int value; unsigned third; };
// Original: arm9/ov003 @ 0x021580D8; symbol: func_ov003_021580d8; size: 0x68.
extern "C" void Util_CopyAndFormatEmbeddedTextFields(TextOwner* object, const TextSource* source) {
    if (!source) return;
    object->first = source->first;
    object->buffer = (unsigned)source->value;
    object->third = source->third;
    object->buffer = (unsigned)((char*)object + 0x44);
    int value = source->value;
    if (!value) return;
    memset((char*)object + 0x44, 0, 0x200);
    unsigned length = String_CountBytesUntilTerminator((const signed char*)((char*)object + 0x44));
    sprintf((char*)object + 0x44 + length, data_ov003_0217fce0, value);
}
