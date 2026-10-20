#include <globaldefs.h>
ARM
extern "C" void Resource_ResetScriptContextRecordsAndCounters(void *);
// Original: arm9/ov001 @ 0x02159408; symbol: ResetScriptContextAtOffset11C; size: 0x14.
// Calls the script-context reset routine on the second argument plus 0x11C.
extern "C" int CutsceneActor_ResetHeadingPath(void *unused, unsigned char *base) {
    Resource_ResetScriptContextRecordsAndCounters(base + 0x11c);
    return 0;
}
