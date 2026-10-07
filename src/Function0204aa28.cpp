#include <globaldefs.h>

struct Function0204aa28Array
{
    const void* elements;
    signed short index;
    unsigned char unknown_006[4];
    unsigned char wideElements;
};

extern "C" ARM const void* func_0204aa28(const Function0204aa28Array* array)
{
    int shift = 5;
    if (array->wideElements != 0)
        shift = 6;
    int index = array->index;
    const unsigned char* elements = (const unsigned char*)array->elements;
    return elements + (index << shift);
}
