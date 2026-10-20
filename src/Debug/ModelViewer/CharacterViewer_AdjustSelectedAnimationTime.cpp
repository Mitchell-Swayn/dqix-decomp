#include <globaldefs.h>
ARM
// Original: arm9/ov015 @ 0x0219015C; symbol: AdjustBoundedNestedRecordAmount; size: 0x6c.
// Adds a delta to the nested amount and clamps it to zero and the stored range.
extern "C" char* DebugMenu_GetEntryByIndex(char*, int);
extern "C" void* DebugMenu_GetEntryLabel(void*);
extern "C" void* CharacterViewer_FindLoadedAnimation(void*, void*);
extern "C" void CharacterViewer_AdjustSelectedAnimationTime(unsigned char* self, int delta) {
    char* node = DebugMenu_GetEntryByIndex(*(char**)self + 0x2c4, *(short*)(self + 0x38));
    if (!node) return;
    void* subrecord = DebugMenu_GetEntryLabel(node);
    unsigned char* value = (unsigned char*)CharacterViewer_FindLoadedAnimation(self, subrecord);
    if (!value) return;
    int upper=*(int*)(value+0x14); int lower=*(int*)(value+0x10); int limit=upper-lower; *(int*)(value+0x18)+=delta; if(*(int*)(value+0x18)<0)*(int*)(value+0x18)=0; if(*(int*)(value+0x18)>limit)*(int*)(value+0x18)=limit;
}
