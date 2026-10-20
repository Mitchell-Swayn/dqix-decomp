#include <globaldefs.h>

extern "C" void Graphics_RepeatClippedTilemapRectangle(void*, void*, int, int, int, int, int, int, unsigned short);

// Original: arm9/main @ 0x0204BBB4; symbol: func_0204bbb4; size: 0x54.
extern "C" void Graphics_RepeatIndexedScreenRectangle(void* object, unsigned index, int arg2, int arg3,
                               short value0, short value1, short value2, short value3,
                               unsigned short value4)
{
    unsigned char* bytes = (unsigned char*)object;
    if (bytes[0x1d] > index) {
        int* entries = (int*)*(int*)(bytes + 0x10);
        if (entries != 0) {
            Graphics_RepeatClippedTilemapRectangle(object, (char*)entries + index * 16,
                          arg2, arg3, value0, value1, value2, value3, value4);
        }
    }
}
