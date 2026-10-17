#include <globaldefs.h>
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" unsigned _ZN16BackgroundLoader13GetTaskStatusEi(void*, unsigned);
extern "C" void SetNestedSecondWordForTypeThree(void*, int);
extern "C" unsigned data_ov001_021658e0[];
extern "C" unsigned char data_ov001_021658b8[];
// Original: arm9/ov001 @ 0x0215EDB8; symbol: func_ov001_0215edb8; size: 0x74.
extern "C" ARM int Ov001_UpdateNestedStateFromTaskStatuses(void* object) {
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    for (int i = 0; i < *(int*)(data_ov001_021658b8 + 0x88); ++i) {
        if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, data_ov001_021658e0[i]) == 0) {
            SetNestedSecondWordForTypeThree(object, 1);
            return 1;
        }
    }
    SetNestedSecondWordForTypeThree(object, 0);
    return 1;
}
