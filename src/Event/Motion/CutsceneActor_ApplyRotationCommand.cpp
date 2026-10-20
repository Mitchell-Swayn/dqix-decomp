#include <globaldefs.h>
ARM
#include <std_library_functions.h>

// Original: arm9/ov001 @ 0x021594AC; symbol: func_ov001_021594ac; size: 0x20.
extern "C" int CutsceneActor_ApplyRotationCommand(const void *source, void *destination) {
    memcpy((unsigned char *)destination + 0x80, (const unsigned char *)source + 4, 0x0c);
    return 0;
}
