#include <globaldefs.h>
struct PackedEntry {unsigned int value; unsigned int other;};
struct EntryOwner {unsigned int preceding[2]; PackedEntry* entries;};
// Original: arm9/ov031 @ 0x0223BD28; symbol: func_ov031_0223bd28; size: 0x30.
// Layout projection only; broader object ownership remains unclassified.
extern "C" ARM void ReadPackedEntryFields(EntryOwner* p,int index,unsigned int* high,unsigned int* low) {
 PackedEntry* entries=p->entries; *high=(entries[index].value&0x1ff0000)>>16; *low=entries[index].value&255;
}
