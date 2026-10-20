#include <globaldefs.h>
ARM

struct LightingParameter;struct IntegerParameterView;struct Node;
struct PresetImage { unsigned word0; unsigned pad04[3]; unsigned word10; unsigned flags14; unsigned pad18[5]; unsigned word2c; unsigned word30; };
struct LightingNode { unsigned char prefix[4]; unsigned char tint[0x40]; void* model; unsigned char tail[0xc]; LightingNode* next; };
extern "C" void* Zone3D_GetMainInstance();
extern "C" char* _ZN15LightingManager11GetInstanceEv();
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" void _ZN15LightingManager25RecomputeAdvancedLightingEv(void*);
extern "C" void Lighting_ApplyTintToModelTree(Node*, void*);
extern "C" void Zone3D_DrawWorldGeometryAndNearbyGrottoTiles(void*);
// Original data: arm9/ov001 @ 0x2165880; symbol: data_ov001_02165880.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" volatile PresetImage EventGetObjectSession_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov001 @ 0x2164d14; symbol: data_ov001_02164d14.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000034430000f041000034430000f041.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" volatile unsigned LightingApplyScriptPresetAndUpdateScene_UnknownRoleInitializedBytes[];
// Original data: arm9/ov001 @ 0x2164d24; symbol: data_ov001_02164d24.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00000000000000000000000000000000.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" int LightingApplyScriptPresetAndUpdateScene_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/ov001 @ 0x021603D8; symbol: func_ov001_021603d8; size: 0x12C.
// Sets the script-selected lighting preset and updates the active lighting scene.
extern "C" int Lighting_ApplyScriptPresetAndUpdateScene(LightingParameter* parameter, void*, void*, void*, void*) {
    unsigned char* global = (unsigned char*)Zone3D_GetMainInstance();
    char* lighting = _ZN15LightingManager11GetInstanceEv();
    int choice = Script_ReadParameterAsInteger((IntegerParameterView*)parameter);
    *(int*)(lighting + 0x98) = choice;
    unsigned flags = EventGetObjectSession_UnknownRoleZeroInitializedStorage.flags14;
    if ((flags & 1) == 0) {
        LightingApplyScriptPresetAndUpdateScene_UnknownRoleInitializedBytes[4] = EventGetObjectSession_UnknownRoleZeroInitializedStorage.word0;
        LightingApplyScriptPresetAndUpdateScene_UnknownRoleInitializedBytes[5] = EventGetObjectSession_UnknownRoleZeroInitializedStorage.word10;
        LightingApplyScriptPresetAndUpdateScene_UnknownRoleInitializedBytes[6] = EventGetObjectSession_UnknownRoleZeroInitializedStorage.word30;
        LightingApplyScriptPresetAndUpdateScene_UnknownRoleInitializedBytes[7] = EventGetObjectSession_UnknownRoleZeroInitializedStorage.word2c;
        EventGetObjectSession_UnknownRoleZeroInitializedStorage.flags14 = flags | 1;
    }
    *(int*)(lighting + 0x94) = LightingApplyScriptPresetAndUpdateScene_UnknownRoleInitializedBytes_Variant2[choice];
    if (*(int*)(global + 0x410) == 1) {
        if (global[0x834]) return 1;
        LightingNode* node = *(LightingNode**)(global + 0x41c);
        while (node) {
            if (node->model) Lighting_ApplyTintToModelTree((Node*)node->model, node->tint);
            node = node->next;
        }
        global[0x834] = 1;
    } else {
        unsigned snapshot[4] = {EventGetObjectSession_UnknownRoleZeroInitializedStorage.word0, EventGetObjectSession_UnknownRoleZeroInitializedStorage.word10, EventGetObjectSession_UnknownRoleZeroInitializedStorage.word30, EventGetObjectSession_UnknownRoleZeroInitializedStorage.word2c};
        *(int*)(lighting + 0x94) = snapshot[choice];
        *(int*)(lighting + 0x90) = 0;
        _ZN15LightingManager25RecomputeAdvancedLightingEv(lighting);
    }
    global[0x832] = 1;
    global[0x833] = 1;
    Zone3D_DrawWorldGeometryAndNearbyGrottoTiles(global);
    return 1;
}
