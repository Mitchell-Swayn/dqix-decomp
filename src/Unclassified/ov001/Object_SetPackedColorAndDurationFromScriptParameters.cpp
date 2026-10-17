#include <globaldefs.h>
ARM
struct IntegerParameterView;
struct Color { unsigned int red, green, blue; };
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *parameter);
extern "C" void *ReadGlobalValueAt02108D5C(void);
extern "C" void Object_SetPackedColorAndMillisecondsDuration(unsigned char *object, const Color *color, unsigned int time);
// Original: arm9/ov001 @ 0x0215B3AC; symbol: func_ov001_0215b3ac; size: 0x5C.
extern "C" int Object_SetPackedColorAndDurationFromScriptParameters(IntegerParameterView *parameter) {
    Color color;
    color.red = ReadScriptParameterAsInteger(parameter);
    color.green = ReadScriptParameterAsInteger((IntegerParameterView *)((unsigned char *)parameter + 8));
    color.blue = ReadScriptParameterAsInteger((IntegerParameterView *)((unsigned char *)parameter + 0x10));
    unsigned int time = ReadScriptParameterAsInteger((IntegerParameterView *)((unsigned char *)parameter + 0x18));
    void *object = ReadGlobalValueAt02108D5C();
    if (object != 0) {
        Object_SetPackedColorAndMillisecondsDuration((unsigned char *)object, &color, time);
    }
    return 1;
}
