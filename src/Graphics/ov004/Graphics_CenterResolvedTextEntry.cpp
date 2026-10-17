#include <globaldefs.h>
ARM
#include <System/Matrix.h>
class Display { public:
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6();
    virtual void SetPosition(const Vector3i&);
    virtual Vector3i GetPosition();
};
extern "C" int Graphics_GetResolvedEntryTextWidth(void*,short);
extern "C" Display* func_ov004_0215e47c(void*,int);
// Original: arm9/ov004 @ 0x0215E574; symbol: func_ov004_0215e574; size: 0x88.
extern "C" void Graphics_CenterResolvedTextEntry(void *self, int id, int width, int left) {
    int textWidth = Graphics_GetResolvedEntryTextWidth(self, (short)id);
    Display *display = func_ov004_0215e47c(self, id);
    if (display) {
        Vector3i position;
        position = display->GetPosition();
        position.x = (left + ((width - textWidth) >> 1)) << 12;
        display->SetPosition(position);
    }
}
