#include <globaldefs.h>
ARM
extern "C" char* GetLinkedNodeByBoundedIndex(char*, int);
extern "C" void* Object_GetSubrecordAtOffset4(void*);
extern "C" void* func_ov015_0218f39c(void*, void*);
struct AnimationOwner { void* nodes; unsigned char pad[0x34]; short index; unsigned char pad2[0x12]; void* cached; };
// Original: arm9/ov015 @ 0x021900DC; symbol: func_ov015_021900dc; size: 0x40.
extern "C" void UpdateCachedAnimationEntry(AnimationOwner* object) {
    char* node = GetLinkedNodeByBoundedIndex((char*)object->nodes + 0x2c4, object->index);
    if (node == 0) return;
    void* subrecord = Object_GetSubrecordAtOffset4(node);
    void* record = func_ov015_0218f39c(object, subrecord);
    if (record != 0) object->cached = *(void**)((char*)record + 0x18);
}
