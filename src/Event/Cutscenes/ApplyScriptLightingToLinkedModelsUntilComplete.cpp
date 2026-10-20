#include <globaldefs.h>
struct IntegerParameterView;struct Node;
struct LightingNode { unsigned char prefix[4]; unsigned char tint[0x40]; void* model; unsigned char tail[0xc]; LightingNode* next; };
extern "C" void* Zone3D_GetMainInstance();
extern "C" char* _ZN15LightingManager11GetInstanceEv();
extern "C" int Script_ReadParameterAsInteger(IntegerParameterView*);
extern "C" void Lighting_ApplyTintToModelTree(Node*, void*);
// Original: arm9/ov001 @ 0x02160338; symbol: func_ov001_02160338; size: 0x78.
// Stores the script lighting value and applies tint to linked models once when the global mode is enabled.
extern "C" int ApplyScriptLightingToLinkedModelsUntilComplete(IntegerParameterView* parameter, void*) {
    unsigned char* global = (unsigned char*)Zone3D_GetMainInstance();
    char* lighting = _ZN15LightingManager11GetInstanceEv();
    if (global[0x834]) return 1;
    *(int*)(lighting + 0x90) = Script_ReadParameterAsInteger(parameter);
    if (*(int*)(global + 0x410) == 1) {
        LightingNode* node = *(LightingNode**)(global + 0x41c);
        while (node) {
            if (node->model) Lighting_ApplyTintToModelTree((Node*)node->model, node->tint);
            node = node->next;
        }
        global[0x834] = 1;
    }
    return 1;
}
