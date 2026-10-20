#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_rebuildconditionals off
struct Flags { unsigned kind:4; unsigned category:5; unsigned other:23; };
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" char* GameObject_GetLinkedActionDataWhenEnabled(char*);
// Original: arm9/ov000 @ 0x0217C514; symbol: func_ov000_0217c514; size: 0x80.
extern "C" unsigned GameState_AddLinkedObjectCategoryBit(int id, unsigned mask) {
    char* object = (char*)GameState_GetObjectWithFlag100(_ZN9GameState11GetInstanceEv(), id);
    if (!object) return mask;
    char* buffer = GameObject_GetLinkedActionDataWhenEnabled(object);
    if (!buffer) return mask;
    if (*(short*)(buffer+0x18)>0) {
      int valid = ((Flags*)(buffer+8))->kind <= 7;
      if (valid) {
        unsigned category=((Flags*)(buffer+8))->category;
        if (category<=11) mask |= 1u << category;
    }
    }
    return mask;
}
