#include <globaldefs.h>
ARM
struct List; struct Entry; struct Lookup;
extern "C" void ApplyValueToAllHalfwordCountedEntries(char* p,unsigned value);
extern "C" void Object_ResetSelectedEntryCoordinatesAndFlags(void*, int);
extern "C" Entry* FindRecordPointerByKey(List* list, unsigned int key);
extern "C" void Object_WriteSelectedEntryByte14(void* owner, int index, unsigned char value);
extern "C" void Object_UpdateAllCountedResourceEntries(unsigned char* p);
extern "C" void WriteResolvedLookupEntryXY(Lookup* lookup,unsigned id,unsigned x,unsigned y);
// Original: arm9/ov002 @ 0x0215B0A8; symbol: func_ov002_0215b0a8; size: 0x90.
extern "C" void Graphics_ResetFirstResourceEntryWhenFlagEight(char *self) {
    if (!(*(unsigned *)(self + 0x247c) & 8)) return;
    char *entries = *(char **)(*(char **)(self + 0x1a68) + 0x3c);
    Object_ResetSelectedEntryCoordinatesAndFlags(entries, 0);
    char *entry = (char *)FindRecordPointerByKey((List *)entries, 0);
    if (entry) *(unsigned char *)(entry + 0x15) |= 8;
    ApplyValueToAllHalfwordCountedEntries(entries, *(unsigned *)(self + 0x1ba0));
    WriteResolvedLookupEntryXY((Lookup *)entries, 0, 215, 150);
    Object_WriteSelectedEntryByte14(entries, 0, 0);
    Object_UpdateAllCountedResourceEntries(*(unsigned char **)(self + 0x1a68));
}
