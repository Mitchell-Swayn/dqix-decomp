#include <globaldefs.h>

extern "C" void func_0202f45c(void*, int, int, int, int, int, int);

// Original: arm9/main @ 0x0202F404; symbol: func_0202f404; size: 0x58.
extern "C" void Object_InvokeConfiguredScaledHalfwordRectangle(void* object, int arg1, int arg2, int arg3)
{
    short* values = *(short**)((char*)object + 0x440);
    if (values != 0 && *(int*)((char*)values + 8) != 0) {
        func_0202f45c(object, (int)values[0] << 12, (int)values[1] << 12,
                      (int)values[2] * *(int*)((char*)values + 0x10),
                      (int)values[3] * *(int*)((char*)values + 0x14), arg1, arg2);
    }
}
