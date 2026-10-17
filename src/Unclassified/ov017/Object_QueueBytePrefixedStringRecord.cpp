#include <globaldefs.h>
ARM
extern "C" bool TestInactiveOrPrimaryIndexState(unsigned*);
extern "C" char* strcpy(char*, const char*);
extern "C" void func_ov017_02195250(void*, const char*);
// Original: arm9/ov017 @ 0x021CC148; symbol: func_ov017_021cc148; size: 0x50.
extern "C" void Object_QueueBytePrefixedStringRecord(unsigned char value, unsigned char* source, int unused, void* output, unsigned* state) {
    char record[0x10];
    if (TestInactiveOrPrimaryIndexState(state)) {
        record[0] = value;
        record[1] = source[5];
        strcpy(record + 2, (char*)source + 6);
        func_ov017_02195250(output, record);
    }
}
