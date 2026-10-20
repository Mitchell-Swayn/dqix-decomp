#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* _ZN9GameState20GetGameObjectByIndexEi(void*, int);
extern "C" int _ZN8Object3D10EnableFlagEi(void*, int);
extern "C" int _ZN8Object3D11DisableFlagEi(void*, int);
extern "C" int Script_ResolveEventObjectIndex(int);
extern "C" int Script_ReadParameterAsInteger(void*);
// Original: arm9/ov001 @ 0x0215EEB0; symbol: func_ov001_0215eeb0; size: 0x70.
extern "C" int Script_SetIndexedObjectFlag(void* parameters) {
    void* game = _ZN9GameState11GetInstanceEv();
    int objectIndex = Script_ResolveEventObjectIndex(Script_ReadParameterAsInteger(parameters));
    int flag = Script_ReadParameterAsInteger((char*)parameters + 8);
    int enabled = Script_ReadParameterAsInteger((char*)parameters + 16);
    void* object = _ZN9GameState20GetGameObjectByIndexEi(game, objectIndex);
    if (!object)
        return 0;
    if (enabled)
        _ZN8Object3D10EnableFlagEi(object, flag);
    else
        _ZN8Object3D11DisableFlagEi(object, flag);
    return 1;
}
