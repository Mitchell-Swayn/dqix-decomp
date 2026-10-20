#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" void _ZN8Object3D10EnableFlagEi(void*, int);
extern "C" void _ZN8Object3D11DisableFlagEi(void*, int);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventGetObjectSession_UnknownRoleZeroInitializedStorage[];
// ARM / ov001 / 0x02161524 / Script_SetObjectFlagFromResourceEntry
// Original: arm9/ov001 @ 0x02161524; symbol: func_ov001_02161524; size: 0x12C.
extern "C" int Script_SetObjectFlagFromResourceEntry(void* parameters, int unused)
{
    int index = Script_ReadParameterAsInteger(parameters);
    int disable = Script_ReadParameterAsInteger((char*)parameters + 8);
    unsigned char* table = *(unsigned char**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 4);
    int kind = *(int*)(table + index * 16);
    volatile unsigned char* vtable = table;
    switch (kind) {
    case 0: case 1: case 4: case 5: {
        void* obj = *(void**)(*(unsigned char**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 4) + index * 16 + 12);
        if (!obj) return 0;
        if (disable) _ZN8Object3D11DisableFlagEi(obj, 0x10);
        else _ZN8Object3D10EnableFlagEi(obj, 0x10);
        break;
    }
    case 6: {
        void* obj = *(void**)(*(unsigned char**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 4) + index * 16 + 12);
        if (!obj || !*(void**)((char*)obj + 0x18)) return 0;
        if (disable) {
            _ZN8Object3D11DisableFlagEi(*(void**)((char*)obj + 0x18), 0x10);
            *(unsigned int*)*(void**)(*(unsigned char**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 4) + index * 16 + 12) &= ~0x40;
        } else {
            _ZN8Object3D10EnableFlagEi(*(void**)((char*)obj + 0x18), 0x10);
            *(unsigned int*)*(void**)(*(unsigned char**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 4) + index * 16 + 12) |= 0x40;
        }
        break;
    }
    case 2: {
        void* obj = *(void**)(*(unsigned char**)(EventGetObjectSession_UnknownRoleZeroInitializedStorage + 4) + index * 16 + 12);
        if (!obj) return 0;
        if (disable) *(unsigned int*)obj &= ~0x40;
        else *(unsigned int*)obj |= 0x40;
        break;
    }
    default: break;
    }
    return 1;
}
