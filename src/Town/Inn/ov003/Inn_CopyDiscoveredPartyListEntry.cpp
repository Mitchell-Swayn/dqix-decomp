#include <globaldefs.h>
ARM
struct RecordBytes48 { unsigned char bytes[48]; };
struct RecordBytes6 { unsigned char bytes[6]; };
struct FiftyFiveByteRecord { unsigned char first; RecordBytes48 middle; RecordBytes6 tail; };
// Original: arm9/ov003 @ 0x0215F650; symbol: Inn_CopyDiscoveredPartyListEntry; size: 0x48.
// Copies a leading byte, a 48-byte nested payload, and a six-byte nested tail.
// Individual field meanings remain unresolved.
extern "C" FiftyFiveByteRecord* Inn_CopyDiscoveredPartyListEntry(FiftyFiveByteRecord* destination, const FiftyFiveByteRecord* source)
{
 destination->first = source->first;
 destination->middle = source->middle;
 destination->tail = source->tail;
 return destination;
}
