struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
struct Record; struct Owner; struct State;
extern "C" void DisplayRecord_SetActiveAndResetSelection(unsigned char* self,unsigned int value);
extern "C" void DisplayRecord_SetPrimarySelectionAndMarkDirty(unsigned char* p,int v);
extern "C" void DisplayRecord_SetSecondarySelectionAndMarkDirty(unsigned char* p, unsigned char v);
extern "C" WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
extern "C" void* Window_GetUnusedCanvasSlotForId(State* self,unsigned id);
// Original: arm9/ov002 @ 0x0215B918; symbol: func_ov002_0215b918; size: 0x8C.
extern "C" void Util_SetRecordProgressFlags(char *self, unsigned id, unsigned flags, unsigned value) {
    char *part = self + 0x2c8;
    unsigned char *record = (unsigned char*)(Record*)Window_FindActiveCanvasById((WindowCanvasOwner*)((Owner*)(part + 0xc00)), id);
    if (!record) {
        record = (unsigned char*)Window_GetUnusedCanvasSlotForId((State*)(part + 0xc00), id);
        if (!record) return;
    }
    if (value) {
        DisplayRecord_SetActiveAndResetSelection(record, 1);
        DisplayRecord_SetPrimarySelectionAndMarkDirty(record, (unsigned char)flags);
        DisplayRecord_SetSecondarySelectionAndMarkDirty(record, (unsigned char)value);
    } else {
        DisplayRecord_SetActiveAndResetSelection(record, 0);
        DisplayRecord_SetPrimarySelectionAndMarkDirty(record, 0);
        DisplayRecord_SetSecondarySelectionAndMarkDirty(record, 0);
    }
}
