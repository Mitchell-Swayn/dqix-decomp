#include <globaldefs.h>
// Original: arm9/ov001 @ 0x02159EA8; symbol: Script_SetRecordWordAtOffset70; size: 0x8.
// Stores the supplied 32-bit value at record byte offset 0x70, used by the bounded script-parameter setter.
ARM
extern "C" void CutsceneActor_SetObjectSlot(void *record, unsigned int value) {
    *(unsigned int *)((unsigned char *)record + 0x70) = value;
}
