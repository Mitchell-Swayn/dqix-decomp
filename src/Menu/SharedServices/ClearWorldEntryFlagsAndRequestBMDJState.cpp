#include <globaldefs.h>
ARM
extern "C" void InvokeEntryHandlerForStateKey(void*, unsigned int, unsigned int);
extern "C" void* Menu_FindCanvasNodeByKey(void*, unsigned int);
extern "C" void Menu_QueueScriptEntry(void*, unsigned int);
extern "C" void* Zone3D_GetMainInstance(void);
extern "C" void _ZN6Zone3D20SetBMDJStateRequestsEv(void*);
// Original: arm9/ov004 @ 0x02162D78; symbol: ClearWorldEntryFlagsAndRequestBMDJState; size: 0x60.
// Invokes key 0x83, clears bit 0x20 on nine following entries, invokes key 0x69, then requests Zone3D BMDJ state.
extern "C" int ClearWorldEntryFlagsAndRequestBMDJState(void* self) {
    InvokeEntryHandlerForStateKey(self, 0x83, 1);
    for (int i = 0; i < 9; ++i) {
        unsigned char* entry = (unsigned char*)Menu_FindCanvasNodeByKey(self, i + 0x83);
        if (entry) entry[0xc] = entry[0xc] & ~0x20;
    }
    Menu_QueueScriptEntry(self, 0x69);
    _ZN6Zone3D20SetBMDJStateRequestsEv(Zone3D_GetMainInstance());
    return 0;
}
