#include <globaldefs.h>
ARM
extern "C" void Object_SetSelectedPartLowTwoBitMode(char *p,int i,int v);
extern "C" void SetKeyedRecordFlagMaskOne(unsigned char *p,int id);
extern "C" void Object_ApplyModeOneToSelectedPartGroup(unsigned char *p,int id);
extern "C" void WriteResolvedEntryHalfword0E(char *p,int i,short v);
struct ModeSource { int pad[2]; unsigned low : 12; unsigned mode : 2; unsigned high : 18; };
// Original: arm9/ov003 @ 0x0217818C; symbol: func_ov003_0217818c; size: 0x8C.
extern "C" void Graphics_ConfigureSelectedPartModes(char *self, ModeSource *source, int group, int part) {
    char *object = *(char **)(self + 0x89c);
    unsigned char enabled = 1;
    if (source) enabled = source->mode ? enabled : 0;
    if (enabled) {
        Object_ApplyModeOneToSelectedPartGroup((unsigned char *)object, group);
        WriteResolvedEntryHalfword0E(object, part, 0x48);
        Object_SetSelectedPartLowTwoBitMode(object, part, 1);
    } else {
        SetKeyedRecordFlagMaskOne((unsigned char *)object, group);
        WriteResolvedEntryHalfword0E(object, part, 0x46);
        Object_SetSelectedPartLowTwoBitMode(object, part, 1);
    }
}
