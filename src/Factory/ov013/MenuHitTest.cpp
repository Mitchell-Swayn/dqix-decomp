#include "MenuText.h"

// Observed prefix of the shared touch input state; the global remains fallback.
struct Ov013TouchInput {
    unsigned char unknown00[0x20];
    unsigned short x;
    unsigned short y;
    unsigned char unknown24[0x38];
    unsigned char active;
};

extern "C" {
extern Ov013TouchInput data_02114e54;
void func_0204c610(Ov013Widget*, short, short*, short*, short*, short*);
int func_02012734(Ov013TouchInput*, int, int, int, int);
}

extern "C" int func_ov013_021842a0(Ov013WidgetGroup* group, int index)
{
    if (data_02114e54.active) {
        Ov013Widget* widget = func_0205d81c(group, 0);
        if (widget != 0) {
            short x = widget->tileX;
            short y = widget->tileY;
            short offsetX, offsetY, width, height;
            func_0204c610(widget, (short)index, &offsetX, &offsetY, &width, &height);
            return func_02012734(&data_02114e54,
                                offsetX + (short)(x * 8),
                                offsetY + (short)(y * 8), width, height);
        }
    }
    return 0;
}
