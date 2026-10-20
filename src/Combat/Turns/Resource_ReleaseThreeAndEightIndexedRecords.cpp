#include <globaldefs.h>
ARM
extern "C" void TextSprite_ReleaseCachedText(unsigned char*);
struct IndexedRecord {unsigned char bytes[24];};
// Original: arm9/ov000 @ 0x02174DC0; symbol: func_ov000_02174dc0; size: 0x5C.
// Releases three indexed records at 0x1B0C and eight at 0x1C5C, invalidating each record's index.
extern "C" void Resource_ReleaseThreeAndEightIndexedRecords(unsigned char* self) {
 for(int i=0;i<3;i++)TextSprite_ReleaseCachedText(((IndexedRecord*)(self+0x1b0c))[i].bytes);
 for(int i=0;i<8;i++)TextSprite_ReleaseCachedText(((IndexedRecord*)(self+0x1c5c))[i].bytes);
}
