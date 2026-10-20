#include <globaldefs.h>
ARM
extern "C" char* DebugMenu_GetEntryByIndex(char*, int);
extern "C" int DebugMenu_GetEntryLabel(int);
extern "C" void* CharacterViewer_FindLoadedAnimation(void*, void*);
// Original: arm9/ov015 @ 0x0219011C; symbol: func_ov015_0219011c; size: 0x40.
extern "C" void Object_SetValueOnResolvedLinkedSubrecord(void* object, int value) {
    char* bytes = (char*)object;
    int requestedValue = value;
    char* node = DebugMenu_GetEntryByIndex(*(char**)bytes + 0x2c4, *(short*)(bytes + 0x38));
    if (!node) return;
    void* subrecord = (void*)DebugMenu_GetEntryLabel((int)node);
    int* target = (int*)CharacterViewer_FindLoadedAnimation(object, subrecord);
    if (target) target[6] = requestedValue;
}
