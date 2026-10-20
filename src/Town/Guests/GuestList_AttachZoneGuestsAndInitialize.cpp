#include <globaldefs.h>
ARM
extern "C" void *Zone3D_GetMainInstance(void);
extern "C" void GuestList_InitializePresentation(void *);
// Original: arm9/ov003 @ 0x021700BC; symbol: func_ov003_021700bc; size: 0x20.
extern "C" void GuestList_AttachZoneGuestsAndInitialize(void *object) {
    *(void **)((unsigned char *)object + 0x170) = (unsigned char *)Zone3D_GetMainInstance() + 0x840;
    GuestList_InitializePresentation(object);
}
