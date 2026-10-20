#include <globaldefs.h>
ARM
extern "C" void Ov001_InitializeExtendedSessionRecord(char *record);
// Original: arm9/ov001 @ 0x02158E8C; symbol: func_ov001_02158e8c; size: 0x70.
// Returns a session record's extension and initializes it when the selected slot is empty.
extern "C" char *CutsceneCamera_ReleaseCompletedCommandAndGetNext(char *owner, char *record, int slot) {
    if (!record) return 0;
    char *extension = *(char **)(record + 0x48);
    switch (slot) {
    case 0:
        if (!*(void **)(owner + 0x30)) Ov001_InitializeExtendedSessionRecord(record);
        break;
    case 1:
        if (!*(void **)(owner + 0x34)) Ov001_InitializeExtendedSessionRecord(record);
        break;
    case 2:
        Ov001_InitializeExtendedSessionRecord(record);
        break;
    }
    return extension;
}
