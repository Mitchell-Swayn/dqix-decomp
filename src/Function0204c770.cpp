#include <globaldefs.h>
#include <std_library_functions.h>

// Reset the four-byte field at offset 0xDB and optionally restore it from a
// caller-provided value.
extern "C" void func_0204c770(void* object, const void* value)
{
    unsigned char* field = static_cast<unsigned char*>(object) + 0xDB;
    memset(field, 0, 4);
    if (value != 0)
        memcpy(field, value, 4);
}
