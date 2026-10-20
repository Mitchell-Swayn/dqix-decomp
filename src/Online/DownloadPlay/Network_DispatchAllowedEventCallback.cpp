#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e33e0; symbol: data_ov027_021e33e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov027 @ 0x021DBD7C; symbol: func_ov027_021dbd7c; size: 0x70.
// Dispatches callback code 9 for a successful event with opcode 0x15.
extern "C" void Network_DispatchAllowedEventCallback(void *event)
{
    if(*(unsigned short*)((char*)event+2)!=0)return;
    switch(*(unsigned short*)((char*)event+4)) {
    case 0x15: {
        void *state=*(void**)(MBEnd_UnknownRoleZeroInitializedStorage+8);
        void (*callback)(int,void*)=*(void(**)(int,void*))((char*)state+0x51c);
        callback(9,event);
        return;
    }
    case 7: case 9: case 0x19: case 0x1a:
    default:
        return;
    }
}
