#include <globaldefs.h>
ARM
extern "C" char* DebugMenu_GetEntryByIndex(char*, int);
extern "C" void* DebugMenu_GetEntryLabel(void*);
extern "C" void* CharacterViewer_FindLoadedAnimation(void*, void*);
struct AnimationOwner { void* nodes; unsigned char pad[0x34]; short index; unsigned char pad2[0x12]; void* cached; };
// Original: arm9/ov015 @ 0x021900DC; symbol: func_ov015_021900dc; size: 0x40.
extern "C" void UpdateCachedAnimationEntry(AnimationOwner* object) {
    char* node = DebugMenu_GetEntryByIndex((char*)object->nodes + 0x2c4, object->index);
    if (node == 0) return;
    void* subrecord = DebugMenu_GetEntryLabel(node);
    void* record = CharacterViewer_FindLoadedAnimation(object, subrecord);
    if (record != 0) object->cached = *(void**)((char*)record + 0x18);
}
