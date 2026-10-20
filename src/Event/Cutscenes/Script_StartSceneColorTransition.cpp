#include <globaldefs.h>
ARM
struct IntegerParameterView;
struct Color { unsigned int red, green, blue; };
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView *parameter);
extern "C" void *ColorAnimation_GetGlobalInstance(void);
extern "C" void ColorAnimation_StartColorTransition(unsigned char *object, const Color *color, unsigned int time);
// Original: arm9/ov001 @ 0x0215B3AC; symbol: func_ov001_0215b3ac; size: 0x5C.
extern "C" int Script_StartSceneColorTransition(IntegerParameterView *parameter) {
    Color color;
    color.red = Script_ReadParameterAsInteger(parameter);
    color.green = Script_ReadParameterAsInteger((IntegerParameterView *)((unsigned char *)parameter + 8));
    color.blue = Script_ReadParameterAsInteger((IntegerParameterView *)((unsigned char *)parameter + 0x10));
    unsigned int time = Script_ReadParameterAsInteger((IntegerParameterView *)((unsigned char *)parameter + 0x18));
    void *object = ColorAnimation_GetGlobalInstance();
    if (object != 0) {
        ColorAnimation_StartColorTransition((unsigned char *)object, &color, time);
    }
    return 1;
}
