#include <globaldefs.h>
ARM
extern "C" void *Field_InitializeTransitionFromZoneFeature(char *);
// Original: arm9/ov017 @ 0x0219CD98; symbol: InitializeSharedVectorRecordAndEnableFlags; size: 0x28.
// When object +0x36BC is nonnull, initializes its shared vector record and sets returned record bytes +2 and +7 to one; semantic purpose remains unknown.
extern "C" void Field_RequestTransitionFromSelectedZoneFeature(unsigned char *p) {
    unsigned char *source = *(unsigned char **)(p + 0x36bc);
    if (!source) return;
    unsigned char *record = (unsigned char *)Field_InitializeTransitionFromZoneFeature((char *)source);
    if (record) record[2] = 1;
}
