#include <globaldefs.h>

extern "C" void Graphics_CopyClippedTilemapRectangle(void*, void*, int, int, int, int, int, int, int, unsigned short);

// Original: arm9/main @ 0x0204B878; symbol: func_0204b878; size: 0x58.
extern "C" void Graphics_CopyTilemapRectangleToStoredChild(void* object, int arg1, int arg2, int arg3,
                               short value0, short value1, short value2, short value3,
                               unsigned short value4)
{
    void* child = *(void**)((char*)object + 0x14);
    if (child != 0) {
        Graphics_CopyClippedTilemapRectangle(object, child, arg1, arg2, arg3,
                      value0, value1, value2, value3, value4);
    }
}
